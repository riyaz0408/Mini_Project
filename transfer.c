#include "header.h"
#include <stdio.h>
#include <stdlib.h>

long int raid()
{
    return rand() % 1000000 + 100000;
}

void *transfer(A_c *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    int amount;
    A_c *temp;
    A_c *temp2;
    int n = 5;
    temp = head;
    temp2 = head;
    int account;
    while (n > 0)
    {
        printf("Enter your account number\n");
        scanf("%d", &account);

        while (temp)
        {
            if (temp->Acc_Num == account)
                break;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            n--;
            printf("Account not found or you have entered wrong number. Enter again.\n");
        }
        else
        {
            break;
        }
    }

    if (temp == NULL && n <= 0)
    {
        printf("You have entered the wrong number many times.\n");
        return head;
    }

    n = 5;
    while (n > 0)
    {
        printf("Enter account number you want to transfer to: \n");
        scanf("%d", &account);

        while (temp2)
        {
            if (temp2->Acc_Num == account)
                break;
            temp2 = temp2->next;
        }

        if (temp2 == NULL)
        {
            n--;
            printf("Account not found or you have entered wrong number. Enter again.\n");
        }
        else
        {
            break;
        }
    }

    if (temp2 == NULL && n <= 0)
    {
        printf("You have entered the wrong number many times.\n");
        return head;
    }

    printf("Enter the amount you want to transfer: ");
    scanf("%d", &amount);

    if (temp->Acc_bal < amount)
    {
        printf("Your balance is insufficient\n");
        return head;
    }
    else
    {
        long int newID = raid();
        if (temp->a_t.count >= 5)
        {
            for (int i = 1; i < 5; i++)
            {
                temp->a_t.tra_id[i - 1] = temp->a_t.tra_id[i];
                temp->a_t.withdraw[i - 1] = temp->a_t.withdraw[i];
            }
            temp->a_t.count = 4;
        }
        
        int idx = temp->a_t.count;
        temp->Acc_bal -= amount;
        temp->a_t.withdraw[idx] = amount;
        temp->a_t.tra_id[idx] = newID;
        temp->a_t.count++;
        newID = raid();
        
        if (temp2->a_t.count >= 5)
        {
            for (int i = 1; i < 5; i++)
            {
                temp2->a_t.tra_id[i - 1] = temp2->a_t.tra_id[i];
                temp2->a_t.deposit[i - 1] = temp2->a_t.deposit[i];
            }
            temp2->a_t.count = 4;
        }
        
        idx = temp2->a_t.count;
        temp2->Acc_bal += amount;
        temp2->a_t.deposit[idx] = amount;
        temp2->a_t.tra_id[idx] = newID;
        temp2->a_t.count++;
        
        printf("Transfer successful! You transferred %d to account %d\n", amount, temp2->Acc_Num);
    }
    
    return head;
}

