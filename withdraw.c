#include "header.h"
#include <stdio.h>
long int getid()
{
	return rand()%1000000+100000;
}
void *withdraw(A_c *head)
{
    if (head == NULL) 
    {
        printf("No accounts available!\n");
        return head;
    }
    srand(getpid());
    int acc_num, attempts = 5;
    float amount;
    A_c *temp;
    while (attempts > 0) 
    {
        printf("Enter Account Number: ");
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
        }
    }

    if (attempts == 0) 
    {
        printf("You exceeded the limit for entering the account number.\n");
        return head;
    }

    while (1) 
    {
        printf("Enter the amount you want to withdraw: ");
        scanf("%f", &amount);
        if (amount <= 0) 
	{
            printf("Invalid amount. Please enter a positive value.\n");
        }
       	else if(amount>temp->Acc_bal)
       	{
            printf("Insufficient balance ! Avaliable balance:%2.f\n",temp->Acc_bal);
        }
	else
	{
		break;
	}
    }
    long int newID=getid();
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
    temp->a_t.withdraw[idx]= amount;
    temp->a_t.tra_id[idx]=newID;
    temp->a_t.count++;

    printf("Withdraw successful! New Balance: %.2f\n", temp->Acc_bal);
    return head;

}
