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
#include "../header/liste_ceremonie.h"
#include "../header/menu.h"
#include "../header/ceremonie.h"


int main()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void ceremonie();
    void ajout_ceremonie();
    void menu();

    //Variables 
    int choix_liv,choix_menu = 0, compte_exit;


        printf(" \n \n ***************** BIENVENU DANS L'APPLICATION DES GESTION DE MENU DE CÉRÉMONIE ***************** \n \n ");

        printf(" \n  1 - Gestion \n");
        printf(" \n  2 - Menu \n");
        printf(" \n  3 - Céremonie \n");
        printf("\n \n  ------->  Taper le numero de votre choiX \n \n");

        do
        {
            scanf("%d",&choix_menu);
            switch(choix_menu)
            {
                case 1:
                    //Appel de la fonctions Céremonie
                    ceremonie();
                    break;
                case 2:
                    //Appel de la fonctions Menu
                    menu();
                    break;
                case 3:
                    //Appel de la fonctions liste de ceremonie
                    liste_ceremonie();
                    break;
                default:
                    printf(" \n ERREUR DE SAISI VUEILLER RÉESSAYER ! ");
                    choix_menu == 0;
            }
        } while (choix_menu==0);
       
    return 0;
}