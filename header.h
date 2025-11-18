#include<stdio.h>
#include<stdio_ext.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 5
#define USER "V24HE6M1"
#define PASS "12345678"
typedef struct A_T 
{
	long int tra_id[MAX];
	float withdraw[MAX];
	float deposit[MAX];
	 int count;
	//struct A_T *next;
}A_t;
typedef struct a_c
{
	char *Acc_Name;
        int Acc_Num;
        char Cont_Num[11];
        A_t a_t;
        float Acc_bal;
	struct a_c *next;
}A_c;
void *creacc(A_c *);
void printmenu(void);
void display(A_c *);
void *deposit(A_c *);
void *withdraw(A_c *);
void balance(A_c *);
void *transfer(A_c *);
void save(A_c *);
A_c *load(A_c *);
void history(A_c *);
A_c *find(A_c *);
