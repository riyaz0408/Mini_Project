#include"header.h"
#include<stdio.h>
int main()
{
	A_c *head=NULL;
	head=load(head);
	char ch;
	while(1)
	{
		printmenu();
		scanf("%c",&ch);
		switch(ch)
		{
			case'c':
			case'C':head=creacc(head);break;
			case'e':
			case'E':display(head);break;
			case'd':
			case'D':head=deposit(head);break;
			case'w':
			case'W':head=withdraw(head);break;
			case'b':
			case'B':balance(head);break;
			case't':
			case'T':head=transfer(head);break;
			case's':
			case'S':save(head);break;
			case'h':
			case'H':history(head);break;
			case'f':
			case'F':find(head);break;
			case'q':
			case'Q':exit(0);
		}
	}
}
