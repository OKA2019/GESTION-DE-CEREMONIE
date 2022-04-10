/**
 * @file invite_ceremonie.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Gestion des invités
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../header/ajout_invite.h"
#include "../header/ceremonie.h"
#include "../header/liste_invite.h"

//#include "../header/livres.h"
    
void invite_ceremonie(int num_ceremo)
{
    system("clear");
    //Fonctions à appeller
    void ceremonie();
    void ajout_invite(int num_ceremo);
    void liste_invite(int num_ceremo);

    //variables locales
    char row[100];
    int choix;

    printf("  \n \n ******************************** INVITÉ DE LA CÉREMONIE ******************************** \n \n ");
    liste_invite(num_ceremo);
    

    printf("\n \n \n ------->  Voulez-vous ajouter un invité ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
    scanf("%d",&choix);
    if(choix == 1)
    {
        //appel la fonction ajout_invité
        ajout_invite(num_ceremo);
    }
    else
    {
        //retourne au menu
        ceremonie();
    }
}