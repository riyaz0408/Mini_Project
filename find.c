#include "header.h"
void *getstring()
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
A_c *find(A_c *head)
{
    char *name,*contact;
    int attempts = 5;
    A_c *temp;

    while (attempts-- > 0)
    {
        printf("Enter the account holder name: ");
	__fpurge(stdin);
        name=getstring();
        printf("Enter the contact number: ");
        contact=getstring();
        temp = head;
        while (temp != NULL)
        {
            if (strcmp(temp->Acc_Name, name) == 0 && strcmp(temp->Cont_Num, contact) == 0)
            {
                printf("----- Account Found -----\n");
                printf("Account Holder: %s\n", temp->Acc_Name);
                printf("Account Number: %d\n", temp->Acc_Num);
                printf("Balance       : %.2f\n", temp->Acc_bal);
                printf("Contact Number: %s\n", temp->Cont_Num);
		free(name);
		free(contact);
                return temp;
            }
            temp = temp->next;
        }

        printf("Account not found. Attempts remaining: %d\n", attempts);
    }

    printf("You exceeded the allowed number of attempts.\n");
    free(name);
    free(contact);
    return NULL;
}
