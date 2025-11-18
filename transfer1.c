#include"header.h"
long int raid()
{
        return rand()%1000000+100000;
}
void *transfer(A_c *head)
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	int amount;
	A_c *temp;	
	A_c *temp2;
	int n=5;
	temp=head;
	temp2=head;
	int account;
	p:printf("Enter your account number\n");
	scanf("%d",&account);
	printf("%d",temp->Acc_Num);
	while(temp)
	{
		if(temp->Acc_Num!=account)
			temp=temp->next;
	}
	if((temp==NULL)&&(n>=0))
	{
		n--;
		printf("Account not found or you have entered worng number enter again\n");
		goto p;
	}
	else if(n<=0)
	{
		printf("You have entered wrong number many time\n");
		return head;
	}
	n=5;

	g:printf("Enter account number you want to transfer to: \n");
        scanf("%d",&account);
        while(temp2)
        {
                if(temp2->Acc_Num!=account)
                        temp2=temp2->next;
        }
        if((temp2==NULL)&&(n>=0))
        {
                n--;
                printf("Account not found or you have entered worng number enter again\n");
                goto g;
        }
        else if(n<=0)
        {
                printf("You have entered wrong number many time\n");
                return head;
        }
	printf("Enter the amount you want to transfer:");
	scanf("%d",&amount);
	if(temp->Acc_bal<amount)
	{
		printf("Your balance is isufficient\n");
		return head;
	}
	else
	{
		long int newID=raid();
	 	if(temp->a_t.count>=5)
   		 {
           		 for(int i=1;i<5;i++)
          		 {
                	    temp->a_t.tra_id[i-1]=temp->a_t.tra_id[i];
                	    temp->a_t.withdraw[i-1]=temp->a_t.withdraw[i];
           		 }
         	   temp->a_t.count=4;
   		 }
   		 int idx =temp->a_t.count;
  		 temp->Acc_bal -= amount;
  		 temp->a_t.withdraw[idx]=amount;
 		 temp->a_t.tra_id[idx]=newID;
 		 temp->a_t.count++;
		  newID=raid();
		 if(temp2->a_t.count>=5)
   		 {
            		for(int i=1;i<5;i++)
           		 {
                	  temp2->a_t.tra_id[i-1]=temp2->a_t.tra_id[i];
               		  temp2->a_t.deposit[i-1]=temp2->a_t.deposit[i];
           		 }
            		temp2->a_t.count=4;
   		 }
 	   idx =temp2->a_t.count;
 	   temp2->Acc_bal += amount;
 	   temp2->a_t.deposit[idx]=amount;
 	   temp2->a_t.tra_id[idx]=newID;
 	   temp2->a_t.count++;
	   printf("Amount transfer successfully!Amount remaning:%.2f",temp->Acc_bal);
	}
	return head;


}
