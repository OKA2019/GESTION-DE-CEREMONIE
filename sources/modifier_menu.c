/**
 * @file modifier_menu.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Fonction de modification d'un menu de restauration
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

void modifier_menu()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void menu();

    //Variables 
    int num_menu, continuer;
    char *entrer, *plat, *dessert;

    printf(" \n \n ***************** MODIFIER UN MENU ***************** \n \n ");

    printf("\n \n \n ------->  Voulez-vous vraiment modifier un Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
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
                char modif[1000];
                printf("\n \n  -------> Entrer le numéro du menu a modifier <-------\n \n");
                scanf("%d",&num_menu);
                printf("\nEntrer du menu : ");
                getchar();
                entrer = lire(255);
                printf("\nPlat du menu : ");
                plat = lire(255);
                printf("\nDessert du menu : ");
                dessert = lire(255);

                sprintf(modif, "UPDATE Menu SET entrer = '%s', plat = '%s', dessert = '%s' WHERE iden_menu = %d ", entrer, plat, dessert, num_menu);
                if(!mysql_query(&mysql,modif))
                {
                    printf(" \n \n La modification a été realiser avec succès !!! \n ");
                }
                else
                {
                    printf(" \n \n Echec veuillez réessayer !!! \n ");
                }

                printf("\n \n \n ------->  Voulez-vous Modifier un autre Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
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