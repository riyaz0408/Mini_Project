#include"header.h"
A_c *load(A_c *head)
{
    FILE *fp = fopen("account.dat", "rb");
    if (!fp) 
    {
        perror("File open error");
        return head;
    }

    A_c *newNode, *last = NULL;

    while (1) 
    {
        int len;
        if (fread(&len, sizeof(int), 1, fp) != 1) 
		break; 
        newNode = calloc(1, sizeof(A_c));
        if (!newNode) 
	{
            printf("Memory error\n");
            break;
        }

        newNode->Acc_Name = malloc(len);
        fread(newNode->Acc_Name, sizeof(char), len, fp);
        fread(&newNode->Acc_Num, sizeof(int), 1, fp);
        fread(newNode->Cont_Num, sizeof(char), sizeof(newNode->Cont_Num), fp);
        fread(&newNode->a_t, sizeof(struct A_T), 1, fp);
        fread(&newNode->Acc_bal, sizeof(float), 1, fp);
        newNode->next = NULL;

        if (last)
            last->next = newNode;
        else
            head = newNode;

        last = newNode;
    }

    fclose(fp);
    printf("Accounts loaded successfully.\n");
    return head;
}

