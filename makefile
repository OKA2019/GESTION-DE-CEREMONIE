lib :
	ar crs librairie.a main.o sources/lire.o sources/menu.o sources/ceremonie.o sources/invite.o

main : main.o sources/lire.o sources/menu.o sources/ceremonie.o sources/invite.o
	gcc -o main main.o sources/lire.o sources/menu.o sources/ceremonie.o sources/invite.o -L. -lmysqlclient

main.o : sources/main.c
	gcc -c sources/main.c

ceremonie.o : sources/ceremonie.o
	gcc -c sources/ceremonie.c

liste_invite.o : sources/invite.c
	gcc -c sources/invite.c

menu.o : sources/menu.c
	gcc -c sources/menu.c

lire.o : sources/lire.c
	gcc -c sources/lire.c

clean:
	rm sources/*.o main