#include"header.h"
void display(A_c *head)
{
	char sor[10],pass[10];
	int n=5;
	g:puts("Enter the username and password");
	printf("USERNAME:");
	__fpurge(stdin);
	fgets(sor,10,stdin);
	sor[strlen(sor)-1]='\0';
	printf("PASSWORD:");
	fgets(pass,10,stdin);
	pass[strlen(pass)-1]='\0';
	if((!strcmp(sor,USER))&&(!strcmp(pass,PASS)))
	{
	if(head==NULL)
	{
		printf("List is empty\n");
		
	}
	else
	{
		A_c *temp;
		temp=head;
		while(temp)
		{
			printf("Account Holder:%s\n",temp->Acc_Name);
			printf("Account Number:%d\n",temp->Acc_Num);
			printf("Contact Number:%s\n",temp->Cont_Num);
			printf("Balance:%.2f\n",temp->Acc_bal);
			temp=temp->next;
		}
	}
	}
	else if(n>0)
	{
		n--;
		printf("You have entered wrong username or password!No. of of attempt %d\n",n);
		goto g;
	}
	else
	{
		printf("You have exceeded the number of attempts\n");
		return ;
	}
}
