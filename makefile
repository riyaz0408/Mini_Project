a.out:main.o printmenu.o creacc.o display.o deposit.o withdraw.o balance.o transfer.o load.o saveaccount.o history.o find.o
	cc  main.o printmenu.o creacc.o  display.o deposit.o withdraw.o balance.o transfer.o load.o saveaccount.o history.o find.o -o a.out
main.o:main.c
	cc -c main.c
printmenu.o:printmenu.c
	cc -c printmenu.c
creacc.o:creacc.c
	cc -c creacc.c
display.o:display.c
	cc -c display.c
deposit.o:deposit.c
	cc -c deposit.c
withdraw.o:withdraw.c
	cc -c withdraw.c
balance.o:balance.c
	cc -c balance.c
transfer.o:transfer.c
	cc -c transfer.c
load.o:load.c
	cc -c load.c
saveaccount.o:saveaccount.c
	cc -c saveaccount.c
history.o:history.c
	cc -c history.c
find.o:find.c
	cc -c find.c
