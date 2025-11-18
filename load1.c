#include"header.h"
A_c *load(A_c *head)
{
    FILE *file = fopen("account.dat", "rb");
    if (file == NULL)
    {
	printf("No existing account data found.\n");
        return head;
    }

    A_c *newAccount, *last = NULL;
    while (1)
    {
        newAccount = (A_c *)malloc(sizeof(A_c));
       if(newAccount == NULL) 
	{
		printf("Error while creating a memory\n");
            	fclose(file);
           	 return head;
        }

       if(fread(newAccount, sizeof(A_c), 1, file) != 1) 
       {
		//printf("No data\n");
                free(newAccount);
                break;
         
        }

        newAccount->next = NULL;
        if (last != NULL)
       	{
            last->next = newAccount;
        }
       	else
       	{
            head = newAccount;  
        }
        last = newAccount;
	//iprintf("%s",newAccount->Acc_Name);
    }

    fclose(file);
    return head;
}

