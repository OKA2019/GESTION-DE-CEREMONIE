/**
 * @file menu.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Fonction de gestion de menu
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include "../header/main.h"
#include "../header/liste_menu.h"
#include "../header/liste_menu.h"
#include "../header/ajout_menu.h"
#include "../header/modifier_menu.h"
#include "../header/supprimer_menu.h"

void menu()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    int main();
    void ajout_menu();
    void modifier_menu();
    void suprimer_menu();
    void liste_menu();

    //Variables 
    int choix_menu, continuer;

    printf(" \n \n ***************** GESTION DE MENU CÉREMONIE ***************** \n \n ");
    liste_menu();

    printf("\n \n \n ------->  Voulez-vous Faire ? <------- \n \n  -------> 1 - Ajouter \n \n  -------> 2 - Modifier \n  \n  -------> 3 - Supprimé \n  \n  -------> 4 - Retour \n \n");
    scanf("%d",&choix_menu);
    switch (choix_menu)
    {
    case 1:
        ajout_menu();
        break;
    
    case 2:
        modifier_menu();
        break;
    case 3:
        supprimer_menu();
        break;
    default:
        main();
    }
}