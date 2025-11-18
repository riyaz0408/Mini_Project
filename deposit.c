#include "header.h"
#include <stdio.h>
long int randomid()
{
	return rand()%1000000+100000;
}

void *deposit(A_c *head)
{
    if (head == NULL) 
    {
        printf("No accounts available!\n");
        return head;
    }

    int acc_num, attempts = 5;
    float amount;
    A_c *temp;
    srand(getpid());
e:
    while (attempts > 0) 
    {
	printf("Enter Account Number: ");
	__fpurge(stdin);
        scanf("%d", &acc_num);

        temp = head;
        while (temp) 
	{
            if (temp->Acc_Num == acc_num)
	    {
                break;
            }
            temp = temp->next;
        }

        if (temp != NULL)
       	{
            break;
        } 
	else
       	{
            printf("Incorrect Account Number! Attempts remaining: %d\n", --attempts);
	    goto e;
        }
    }

    if (attempts == 0) 
    {
        printf("You exceeded the limit for entering the account number.\n");
        return head;
    }

    while (1) 
    {
        printf("Enter the amount you want to deposit: ");
        scanf("%f", &amount);
        if (amount <= 0) 
	{
            printf("Invalid amount. Please enter a positive value.\n");
        }
       	else
       	{
            break;
        }
    }
    long int newID=randomid();
    if(temp->a_t.count>=5)
    {
	    for(int i=1;i<5;i++)
	    {
		    temp->a_t.tra_id[i-1]=temp->a_t.tra_id[i];
		    temp->a_t.deposit[i-1]=temp->a_t.deposit[i];
	    }
	    temp->a_t.count=4;
    }
    int idx =temp->a_t.count;
    temp->Acc_bal += amount;
    temp->a_t.deposit[idx]=amount;
    temp->a_t.tra_id[idx]=newID;
    temp->a_t.count++;

    printf("Deposit successful! New Balance: %.2f\n", temp->Acc_bal);
    return head;
}
