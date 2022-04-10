/**
 * @file ajout_menu.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Creation un menu de restauration
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/main.h"
#include "../header/menu.h"
#include "../header/lire.h"

void ajout_menu()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void menu();

    //Variables 
    int choix_liv, choix_menu, compte_exit, continuer;
    char *entrer, *plat, *dessert;

    printf(" \n \n ***************** AJOUTER UN MENU ***************** \n \n ");

    printf("\n \n \n ------->  Voulez-vous ajouter un Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
    scanf("%d",&continuer);
    if (continuer == 2)
    {
        menu();
    }
    else
    {
        MYSQL mysql;
        //initialisation 
        mysql_init(&mysql);
        mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
        {   
            do
            {
                char add[1000];
                printf("\n \n  -------> Entrer le menu de la céremonie <-------\n \n");
                printf("\nEntrer du menu : ");
                getchar();
                entrer = lire(250);
                printf("\nPlat du menu : ");
                plat = lire(250);
                printf("\nDessert du menu : ");
                dessert = lire(250);

                sprintf(add, "INSERT INTO Menu(iden_menu, entrer , plat, dessert) VALUES(NULL, '%s', '%s', '%s')", entrer, plat, dessert);
                if(!mysql_query(&mysql,add))
                {
                    printf(" \n \n Menu ajouter avec succès !!! \n ");
                }
                else
                {
                    printf(" \n \n Echec veuillez réessayer !!! \n ");
                }

                printf("\n \n \n ------->  Voulez-vous ajouter un Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
                scanf("%d",&continuer);
                if (continuer == 2)
                {
                    menu();
                }
            }while (continuer != 2);
            
        }
        else
        {
            printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
        }
    }
}