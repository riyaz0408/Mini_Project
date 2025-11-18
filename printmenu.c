#include"header.h"
void printmenu(void)
{

	
		printf("***********MENU**********\n");
		printf("c/C: Create account\nh/H: Transaction history\nw/W: Withdraw amount.\nd/D: Deposit amount.\nb/B: Balance Enquery.\nt/T: Transfer money.\ne/E: Display all account details.\ns/S: Save the account info in files\nf/F: Finding/searching for specific account.\nq/Q: Quit from app\n");
		__fpurge(stdin);

}
