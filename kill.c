#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	int num;
	if((pid=fork())<0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid==0)
		sleep(30);
	else{
		printf("Sending SIGCHLD to %d\n",pid);
		num=kill(pid,SIGCHLD);
		if(num<0)
			perror("kill:SIGCHLD");
		else
			printf("%d still alive\n",pid);
		printf("killing %d\n",pid);
		if((kill(pid,SIGTERM))<0)
			perror("kill:SIGTERM");
		waitpid(pid,NULL,0);
	}
	exit(EXIT_SUCCESS);
}

