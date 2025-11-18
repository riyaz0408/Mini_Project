#include"header.h"
void *getstr()
{
	char *p=NULL;
	int i=0;
	do
	{
		p=realloc(p,(i+1)*sizeof(*p));
		p[i]=getchar();
	}while(p[i++]!='\n');
	p[i-1]='\0';
	return p;
}
int gen(int p)
{
	int min=100000,max=99999999;
	int range;
       	range=min-max+1;
	p=rand()%range+min;
	return p;

}
void *creacc(A_c *head)
{
	A_c *new;
	new=calloc(1,sizeof(A_c));
	printf("Enter the account name\n");
	__fpurge(stdin);
	new->Acc_Name=getstr();
	printf("Enter Contact Number\n");
	scanf("%10s",new->Cont_Num);
	srand(time(NULL));
	new->Acc_Num=gen(new->Acc_Num);
	new->Acc_bal=0.0;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		A_c *temp;
		temp=head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=new;
	}
	printf("******Account created successfully*******\n");
	printf("Account Holder: %s\n",new->Acc_Name);
	printf("Account Number: %d\n",new->Acc_Num);
	printf("Balance       : %f\n",new->Acc_bal);
	printf("Contact Number: %s\n",new->Cont_Num);
	return head;

}
