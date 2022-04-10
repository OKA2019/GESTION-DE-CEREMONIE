/**
 * @file supprimer_menu.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Fonction de suppression d'un menu de restauration
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

void supprimer_menu()
{
    //Appel initialisations des differents fonctions
    void menu();

    //Variables 
    int num_menu, continuer;

    printf(" \n \n ***************** SUPPRIMER UN MENU ***************** \n \n ");

    printf("\n \n \n ------->  Voulez-vous vraiment supprimer un Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
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
            char suppri[1000];
            printf("\n \n  -------> Entrer le numéro du menu a supprimer <-------\n \n");
            scanf("%d",&num_menu);
            
            sprintf(suppri, "DELETE FROM Menu WHERE iden_menu = %d ", num_menu);
            if(!mysql_query(&mysql,suppri))
            {
                printf(" \n \n La suppression a été realiser avec succès !!! \n ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Voulez-vous supprimer un autre Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
            scanf("%d",&continuer);
            if (continuer == 2)
            {
                menu();
            }
        }
        else
        {
            printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
        }
    }
}