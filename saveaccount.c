#include"header.h"
void save(A_c *head)
{
    FILE *fp = fopen("account.dat", "wb");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    A_c *temp = head;
    while (temp) 
    {
        int len = strlen(temp->Acc_Name) + 1;
        fwrite(&len, sizeof(int), 1, fp);
        fwrite(temp->Acc_Name, sizeof(char), len, fp);
        fwrite(&temp->Acc_Num, sizeof(int), 1, fp);
        fwrite(temp->Cont_Num, sizeof(char), sizeof(temp->Cont_Num), fp);
        fwrite(&temp->a_t, sizeof(struct A_T), 1, fp);
        fwrite(&temp->Acc_bal, sizeof(float), 1, fp);

        temp = temp->next;
    }

    fclose(fp);
    printf("Accounts saved successfully.\n");
}

