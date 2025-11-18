#include"header.h"
void save(A_c *head)
{
	FILE *fptr;
	fptr=fopen("account.dat","wb");
	if(fptr==NULL)
	{
		printf("Error while opening the file\n");
		return;
	}
	if(head==NULL)
	{
		printf("No data to save\n");
		return;
	}
	A_c *cur;
	cur=head;
	while(cur!=NULL)
	{
		fwrite(cur,sizeof(A_c),1,fptr);
		cur=cur->next;
	}
	fclose(fptr);
	printf("Data saved successfully.\n");
}
