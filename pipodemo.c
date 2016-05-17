#include<unistd.h>
#include<stdio.h>
#include<error.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZ 512
struct msg{
	long type;
	char text[BUFSIZ];
};
int main(void)
{
	int qid;
	key_t key;
	int len1,len2;
	struct msg pmsg_w,pmsg_r;
	key=IPC_PRIVATE;
	if((qid=msgget(key,IPC_CRATE|0666))<0){
		perror("msgget:create");
		exit(EXIT_FAILURE);
	}
	puts("Enter message to post:");
	if((fgets(pmsg_w.text,BUFSIZ,stdin))==NULL)
	{
		puts("Wrong,no message to post.");
		exit(EXIT_FAILURE);
	}	
	pmsg_w.type=10;
	len1=strlen(pmsg_w.text);
	if((msgsnd(qid,&pmsg_w,len1,IPC_NOWAIT))<0)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	puts("message posted.");
	puts("***************");
	len2=msgrcv(qid,&pmsg_r,BUFSIZ,10,IPC_NOWAIT|MSG_NOERROR);
	if(len2>0){
		pmsg_r.text[len2]='\0';
		printf("reading queue id = %05d\n",qid);
		printf("message type = %05ld\n",pmsg_r.type);
		printf("message length= %d bytes\n",len2);
		printf("message text = %s\n",pmsg_r.text);
	}
	else{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
