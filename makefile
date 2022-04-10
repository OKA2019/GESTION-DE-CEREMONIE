lib : 
	ar crs librairie.a main.o sources/lire.o sources/ajout_ceremonie.o sources/ajout_menu.o sources/ceremonie.o sources/ajout_invite.o sources/liste_invite.o sources/chronogramme.o sources/invite_ceremonie.o

main : main.o sources/lire.o sources/ajout_ceremonie.o sources/menu.o sources/ajout_menu.o sources/liste_menu.o sources/modifier_menu.o sources/supprimer_menu.o sources/ceremonie.o sources/ajout_invite.o sources/liste_invite.o sources/chronogramme.o sources/invite_ceremonie.o liste_ceremonie.o
	gcc -o main main.o sources/lire.o sources/ajout_ceremonie.o sources/menu.o sources/ajout_menu.o sources/liste_menu.o sources/modifier_menu.o sources/supprimer_menu.o sources/ceremonie.o sources/ajout_invite.o sources/liste_invite.o sources/chronogramme.o sources/invite_ceremonie.o liste_ceremonie.o -L. -lmysqlclient

main.o : sources/main.c
	gcc -c sources/main.c

ceremonie.o : sources/ceremonie.o
	gcc -c sources/ceremonie.c

ajout_ceremonie.o : sources/ajout_ceremonie.c
	gcc -c sources/ajout_ceremonie.c

liste_invite.o : sources/liste_invite.c
	gcc -c sources/liste_invite.c

ajout_invite.o : sources/ajout_invite.c
	gcc -c sources/ajout_invite.c

chronogramme.o : sources/chronogramme.c
	gcc -c sources/chronogramme.c

invite_ceremonie.o : sources/invite_ceremonie.c
	gcc -c sources/invite_ceremonie.c

menu.o : sources/menu.c
	gcc -c sources/menu.c

ajout_menu.o : sources/ajout_menu.c
	gcc -c sources/ajout_menu.c

liste_menu.o : sources/liste_menu.c
	gcc -c sources/liste_menu.c

modifier_menu.o : sources/modifier_menu.c
	gcc -c sources/modifier_menu.c

supprimer_menu.o : sources/supprimer_menu.c
	gcc -c sources/supprimer_menu.c


liste_ceremonie.o : sources/liste_ceremonie.c
	gcc -c sources/liste_ceremonie.c

lire.o : sources/lire.c
	gcc -c sources/lire.c

clean:
	rm main sources/*.o
