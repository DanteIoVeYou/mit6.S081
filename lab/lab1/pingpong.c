#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main()
{
    int r[2];
    int w[2];
    if(pipe(r) == -1) {
        exit(2);
    }
    if(pipe(w) == -1) {
        exit(3);
    }
    if(fork() == 0) {
        close(r[0]);
        close(w[1]);
        char ch;
        read(w[0], &ch, 1);
        fprintf(1, "%d: received ping\n", getpid());
        write(r[1], &ch, 1);
        close(r[1]);
        close(w[0]);
        exit(1);
    }
    close(r[1]);
    close(w[0]);
    char ch = 'x';
    write(w[1], &ch, 1);
    read(r[0], &ch, 1);
    fprintf(1, "%d: received pong\n", getpid());
    close(r[0]);
    close(w[1]);
    exit(0);
}
