#include<stdio.h>
int main()
{
	int n,i,j;
	printf("input a number between 2 and 10\n");
	scanf("%d",&n);
	if(n==2)
		printf("@@\n@@");
	else
	{
		printf("@");
		for(i=0;i<n-2;i++)
		{
			printf("+");
		}
		printf("@\n");

		for(j=0;j<n-2;j++)
		{
			printf("&");
			for(i=0;i<n-2;i++)
			{
				printf(" ");
			}
			printf("&\n");
		}

		printf("@");
		for(i=0;i<n-2;i++)
		{
			printf("+");
		}
		printf("@\n");
		
	}
	return 0;
}
