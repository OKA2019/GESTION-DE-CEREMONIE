/**
 * @file ajout_invite.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Enregistrement d'un invité
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/ceremonie.h"
#include "../header/liste_menu.h"
#include "../header/main.h"
#include "../header/lire.h"


void ajout_invite(int num_ceromo){

    //Fonctions à appeller
    void ceremonie();
    int main();

    int ajouter = 1, age, sexe = 0, num_table, num_siege, continuer = 1, id_invite = 0;
    char *nom, *prenoms, *residence, *entrer, *plat, *dessert, *contacts;
    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   char menuBD[1000];
        sprintf(menuBD,"SELECT entrer, plat, dessert FROM Menu, Ceremonie WHERE iden_menu = num_menu AND iden_ceromo = %d", num_ceromo);
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        printf(" \n \n ***************** MENU ***************** \n \n ");

        do
        {
            printf(" \n \n INSCRIPTION D'UN INVITÉ \n \n ");

            printf(" \n Nom :  ");
            getchar();
            nom = lire(30);
            printf("\n Prenoms :  ");
            prenoms = lire(255);
            printf("\n Age :  ");
            scanf("%d",&age);
            printf(" \n Sexe :  \n Taper  1 - Homme           2 - Femme \n ");
            scanf("%d",&sexe);
            if(sexe != 1)
            {
                sexe = 0;
            }
            printf(" \n Contact :  ");
            getchar();
            contacts = lire(11);
            printf(" \n Residence :  ");
            residence = lire(50);
            printf(" \n Numero de table :  ");
            scanf("%d",&num_table);
            printf(" \n Numero de siège :  ");
            scanf("%d",&num_siege);

            printf(" \n -------> Veuillez faire un choix parmi le menu ci-dessous \n  ");
 
            while (row = mysql_fetch_row(result))
            {
                printf(" \n \n Entrer %s ", row[0]);
                printf(" \n Plat : %s", row[1]);
                printf(" \n Dessert : %s \n", row[2]);
            }

            printf(" \n Entrer :  ");
            getchar();
            entrer = lire(255);
            printf(" \n Plat :  ");
            plat = lire(255);
            printf(" \n Dessert :  ");
            dessert = lire(255);

            char add[1000]; 
            //Copie de la requette dans la variables add
            sprintf(add, "INSERT INTO Invite(id_invite, nom, prenoms, age, contact, residence, sexe, num_table, num_siege, num_ceromo, entrer, plat, dessert) VALUES(0, '%s', '%s', %d, '%s', '%s', %d, %d, %d, %d, '%s', '%s', '%s')", nom, prenoms, age, contacts, residence, sexe, num_table, num_siege, num_ceromo, entrer, plat, dessert);
            if(!mysql_query(&mysql,add))
            {
                printf("\n \n Inscription valider avec succès !!! \n \n ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Taper  1 - Ajouter un invité  ou 2 - Pour revenir au menu \n \n");
            scanf("%d",&continuer);
            if (continuer != 1)
            {
                ceremonie();
            }
        } while (ajouter == 1);


    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    
}