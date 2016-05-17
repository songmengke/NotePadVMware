#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#define BUFSIZ 20
int main()
{
	static const char mesg[]="Happy New Years to you!";
	char buf[BUFSIZ];
	size_t rcount,wcount;
	int p_fd[2];
	size_t n;
	if(pipe(p_fd)<0){
		printf("create pipe fail!\n");
		exit(1);
	}
	n=strlen(mesg);
	wcount=write(p_fd[1],mesg,n);
	rcount=read(p_fd[0],buf,BUFSIZ);
	buf[rcount]='\0';
	printf("Read <%s> from pipe\n",buf);
	close(p_fd[0]);
	close(p_fd[1]);
	return 0;
}
