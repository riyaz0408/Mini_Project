#include"header.h"
void balance(A_c *head)
{
	A_c *temp;
	int n=5;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	e:int number;
	  temp=head;
	printf("Enter account number:");
	scanf("%d",&number);
	while((temp!=NULL)&&temp->Acc_Num!=number)
	{
		temp=temp->next;
	}
	if((temp==NULL)&&(n>0))
	{
		printf("Account not found\n");
		printf("Enter account number correctly\n");
		n--;
		goto e;
	}
	else if(n<=0)
	{
		printf("You have exceded limit to enter the account number\n");
		return;
	}
	else
	{
		printf("Account Holder: %s\n", temp->Acc_Name);
		printf("Account Number: %d\n", temp->Acc_Num);
		printf("Balance: %.2f\n", temp->Acc_bal);
		printf("Last 5 Transactions:\n");
		printf("---------------------------------\n");

// Header formatting without fixed width specifiers
		printf("ID         | TYPE      | AMOUNT\n");

// Calculate the starting point for the last 5 transactions
		int start = temp->a_t.count > 5 ? temp->a_t.count - 5 : 0;
		for (int i = start; i < temp->a_t.count; i++) {
    if (temp->a_t.deposit[i] > 0) {
        printf("%ld       | Deposit   | %.2f\n", temp->a_t.tra_id[i], temp->a_t.deposit[i]);
    } else {
        printf("%ld       | Withdraw  | %.2f\n", temp->a_t.tra_id[i], temp->a_t.withdraw[i]);
    }
}
printf("---------------------------------\n");
	}

}
