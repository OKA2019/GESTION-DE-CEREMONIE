/**
 * @file main.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Accueil de l'application gestion de menu
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/menu.h"
#include "../header/ceremonie.h"
#include "../header/invite.h"

/**
 * @brief Fonction princiaple de l'application
 * 
 * @return int (0)
 */
int main()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void ceremonie();
    void ajout_ceremonie();
    void menu();
    void invite();

    //Variables 
    int choix_menu = 0;

    printf(" \n \n ***************** BIENVENU DANS L'APPLICATION DES GESTION DES CÉRÉMONIES ***************** \n \n ");

    do
    {
        printf(" \n  \t1 - Invité \n");
        printf(" \n  \t2 - Gestionnaire \n");
        printf(" \n  \t3 - Quitté \n");
        printf("\n \n  ---------------->  Taper le numero de votre choiX \n \n");
        scanf("%d",&choix_menu);
        switch(choix_menu)
        {
            case 1:
                connect_invite();
                break;
            case 2:
                connect_administrateur();
                break;
            case 3:
                printf(" \n ************************ Bye, à la prochaine ! ************************ \n ");
                break;
            default:
                printf(" \n \t\t ERREUR DE SAISI ! ");
                printf("\n \n \n ------------>  Taper  1 - pour réessayer \n ------->  2 - Pour revenir au menu de gestion de cérémonie \n \n");
                scanf("%d",&choix_menu);
                if (choix_menu != 1)
                {
                    main();
                    break;
                }
        }
    } while (choix_menu == 1);
       
    return (0);
}