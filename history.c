#include"header.h"
void history(A_c *head)
{
	A_c *temp;
	int n=5;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	int number;
	e:  temp=head;
	printf("Enter account number:");
	scanf("%d",&number);
	n--;
	while((temp!=NULL)&&(temp->Acc_Num!=number))
	{
		temp=temp->next;
	}
	if((temp==NULL)&&(n>0))
	{
		printf("Account not found\n");
		printf("Enter account number correctly\n");
		goto e;
	}
	else if(n<=0)
	{
		printf("You have exceded limit to enter the account number\n");
		return;
	}
	else
	{
  	  printf("---------------------------------\n");
	  printf("Account Holder: %s\n", temp->Acc_Name);
	  printf("Account Number: %d\n", temp->Acc_Num);
	  printf("Last 5 Transactions:\n");
	  printf("--------------------------------------------------\n");
	  printf("%-15s | %-10s | %12s\n", "ID", "TYPE", "AMOUNT (Rs)");
	  printf("--------------------------------------------------\n");
	  int start = temp->a_t.count > 5 ? temp->a_t.count - 5 : 0;
	  for (int i = start; i < temp->a_t.count; i++) 
	  {
		  if (temp->a_t.deposit[i] > 0)
		  {
			  printf("%-15ld | %-10s | %12.2f\n", temp->a_t.tra_id[i], "Deposit", temp->a_t.deposit[i]);
		  }
		  else 
		  {
			  printf("%-15ld | %-10s | %12.2f\n", temp->a_t.tra_id[i], "Withdraw", temp->a_t.withdraw[i]);
		  }
	  }
	  printf("--------------------------------------------------\n");

	}

}
