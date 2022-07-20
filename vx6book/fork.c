/**
 * system interface fork to create child process
 *
*/
int main()
{
	int pid = fork();
	if(pid > 0) {
		printf("i am parent: child=%d\n", pid);
		int ret = wait((int*)0);
		printf("wait ret = %d\n", ret);
	}else if(pid == 0){
		printf("i am child\n");
		exit(0);
	}else{
		printf("fork error");
	}
	exit(1);
}
