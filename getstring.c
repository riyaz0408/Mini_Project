#include"header.h"
void *getstring(void)
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
