/**
 * @file menu.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Gestion de menu
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
#include "../header/ceremonie.h"
#include "../header/invite.h"
#include "../header/lire.h"

/**
 * @brief Fonction principale de gestion de menu
 * 
 */
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

    printf(" \n \n ***************** GESTION DE MENU DES CÉREMONIES ***************** \n \n ");
    liste_menu();
    do
    {
        printf("\n \n ------->  Voulez-vous Faire ? <------- \n \n  -------> 1 - Ajouter menu \n \n  -------> 2 - Modifier menu \n  \n  -------> 3 - Supprimé menu\n  \n  -------> 4 - Accueil \n \n");
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
            case 4:
                main();
                break;
            default:
                printf(" \n ERREUR DE SAISI ! ");

                printf("\n \n \n ------->  1 - Pour réessayer \n ------->  2 - Pour revenir au menu de gestion de cérémonie \n \n");
                scanf("%d",&continuer);
                if (continuer != 1)
                {
                    main();
                }
        }
    }while (continuer == 1);
    
}


/**
 * @brief Creation un menu de restauration
 * 
 */
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

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   
        do
        {
            char add[1000];
            printf("\n \n  -------> Entrer le menu de la céremonie <-------\n \n");
            printf("\n Entrer du menu : ");
            getchar();
            entrer = lire(250);
            printf("\nPlat du menu : ");
            plat = lire(250);
            printf("\nDessert du menu : ");
            dessert = lire(250);

            sprintf(add, "INSERT INTO Menu(iden_menu, entrer, plat, dessert) VALUES(NULL, '%s', '%s', '%s')", entrer, plat, dessert);
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


/**
 * @brief liste des differents menus
 * 
 */
void liste_menu(){

    //Fonctions à appeller
    void ceremonie();
    int main();

    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   char menuBD[1000];
        sprintf(menuBD,"SELECT iden_menu, entrer, plat, dessert FROM Menu");
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        printf(" \n \n \t\t\t LISTE DES MENUS  \n ");

        while (row = mysql_fetch_row(result))
        {
            printf(" \n Numéro %s ", row[0]);
            printf(" \n Entrer %s ", row[1]);
            printf(" \n Plat : %s", row[2]);
            printf(" \n Dessert : %s \n", row[3]);
        }
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    
}


/**
 * @brief Fonction de modification d'un menu de restauration
 * 
 */
void modifier_menu()
{
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
                entrer = lire(250);
                printf("\nPlat du menu : ");
                plat = lire(250);
                printf("\nDessert du menu : ");
                dessert = lire(250);
                
                sprintf(modif, "UPDATE Menu SET entrer = '%s', plat = '%s', dessert = '%s' WHERE iden_menu = '%d' ", entrer, plat, dessert, num_menu);
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


/**
 * @brief Fonction de suppression d'un menu de restauration
 * 
 */
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


