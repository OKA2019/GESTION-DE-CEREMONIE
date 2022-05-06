/**
 * @file ceremonie.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Gestioon des cérémonies
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
#include "../header/users.h"
#include "../header/invite.h"
#include "../header/menu.h"
#include "../header/lire.h"

/**
 * @brief Fonction principale de gestion de cérémonie
 * 
 * @param row informations sur la cérémonie a gérer
 */
void ceremonie()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void connect_administrateur();
    void liste_ceremonie();

    //Variables 
    int choix_menu;

    liste_ceremonie();
    printf(" \n \n ***************** GESTION DES CEREMINIES ***************** \n \n ");

    printf(" \n  1 - Ajouter une cérémonie\n");
    printf(" \n  2 - Modifier une cérémonie \n");
    printf(" \n  3 - Supprimer une cérémonie \n");
    printf(" \n  4 - Se connecter a une cérémonie \n");
    printf(" \n  6 - Accueil (Retour a la page d'accueil) \n");
    printf("\n \n  ------->  Taper le numero de votre choiX \n \n");

    do
    {
        scanf("%d",&choix_menu);
        switch(choix_menu)
        {
            case 1:
                ajout_ceremonie();
                break;
            case 2:
                modifier_ceremonie();
                break;
            case 3:
                supprimer_ceremonie();
                break;
            case 4:
                connect_ceremenie();
                break;
            case 5:
                menu();
                break;
            case 6:
                connect_administrateur();
                break;
            default:
                printf(" \n ERREUR DE SAISI, RÉESSAYER SVP! \n ");
                choix_menu = 0;
        }
    } while (choix_menu == 0);

}


/**
 * @brief Creation une cérémonie
 * 
 */
void ajout_ceremonie()
{
    
    //Appel initialisations des differents fonctions
    void ceremonie();
    char *lire(int size);

    //Variables 
    int duree_ceremo, date_ceremo, heure_dine, date_debut, type, num_menu, continuer;
    char *nom_ceromo, *descri_ceremo;

    printf(" \n \n ***************** AJOUTER UNE CÉREMONIE ***************** \n \n ");

    MYSQL mysql;
    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {
        do
        {
            char add[1000];
            printf("\n \n  -------> Entrer les références de la céremonie <-------\n \n");

            printf("\n Type de cérémonie : \n taper \n");
            printf("\n\t\t 1 - REUNION \n");
            printf("\n\t\t 2 - MARIAGE \n");
            printf("\n\t\t 3 - GALA \n");
            printf("\n\t\t 4 - AUTRE \n");
            scanf("%d",&type);
            printf(" Nom : ");
            getchar();
            nom_ceromo = lire(30);
            printf("\n Description : ");
            descri_ceremo = lire(255);
            printf("\n Combien de jours avant l'événement : ");
            scanf("%d",&date_ceremo);
            printf("\n Numéro du menu : ");
            scanf("%d",&num_menu);

            time_t date_auj;
            time(&date_auj);
            date_ceremo = date_ceremo * 86400;
            date_ceremo = date_ceremo + date_auj;
            date_debut = date_ceremo;

            sprintf(add, "INSERT INTO Ceremonie(iden_ceromo, nom_ceromo , descri_ceremo, date_ceremo, date_debut , type, num_menu) VALUES(NULL, '%s', '%s',' %d',' %d', '%d', '%d')", nom_ceromo, descri_ceremo, abs(date_ceremo), abs(date_debut), type, num_menu);
            if(!mysql_query(&mysql,add))
            {
                printf(" \n \n La cérémonie a été ajouter ave succès \n  ");
                printf(" \n Taper un caractere puis Entrer pour continuer \n  ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Taper  1 - Ajouter une cérémonie \n ------->  2 - Pour revenir au menu de gestion de cérémonie \n \n");
            scanf("%d",&continuer);
            if (continuer != 1)
            {
                ceremonie();
            }
        } while (continuer == 1);
        
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}


/**
 * @brief liste des cérémonies avenir
 * 
 */
void liste_ceremonie(){

    void connect_administrateur();
    void ajout_ceremonie();

    int continuer;

    time_t date_auj;
    time(&date_auj);
    
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   char menuBD[1000];
        sprintf(menuBD,"SELECT iden_ceromo, nom_ceromo, descri_ceremo, from_unixtime(date_ceremo,'%W, %D %M %Y'),type,date_ceremo FROM Ceremonie WHERE date_ceremo >= '%d' ORDER BY date_ceremo DESC", date_auj);
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        printf(" \n \n \t\t\t LISTE DES CÉRÉMONIES À GERER  \n");

        while (row = mysql_fetch_row(result))
        {
            printf(" \n \t\tNumero : %s \n", row[0]);
            if(atoi(row[4]) == 1)
            {
                printf(" \n \t\tType : REUNION \n");
            }
            else if(atoi(row[4]) == 2)
            {
                printf(" \n \t\tType : MARIAGE SUIVI DE DINÉ GALA \n");
            }
            else if(atoi(row[4]) == 3)
            {
                printf(" \n \t\tType : DINÉ GALA \n");
            }
            else
            {
                printf(" \n \t\tType : MARIAGE \n");
            }
            printf(" \n \t\tNom  : %s\n", row[1]);
            printf(" \n \t\tDescription : %s \n", row[2]);
            printf(" \n \t\tDate : %s \n\n\n", row[3]);
        }
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}


/**
 * @brief Fonction de connexion a une céréménie
 * 
 * @return char* 
 */
void connect_ceremenie()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void connect_administrateur();
    void ceremonie();
    void menu();
    void liste_invite(int num_ceremo);

    //Variables 
    int reun, choix_menu, continuer;
    char ;

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {
        char menuBD[1000];
        printf(" ----------> Enter le numero de la ceremonie \n");
        scanf("%d", &reun);

        sprintf(menuBD,"SELECT nom_ceromo, descri_ceremo,from_unixtime(date_ceremo, '%W, %D %M %Y'),num_menu, type FROM Ceremonie WHERE iden_ceromo = %d", reun);
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        row = mysql_fetch_row(result);
        do
        {
            if(row != NULL)
            {
                //On efface l'écrans
                system("clear");
                if(atoi(row[4]) == 1)
                {

                    printf(" \n \n ***************** CEREMINIE : REUNION ***************** \n \n ");
                    chronogramme_reunion();
                }
                else if(atoi(row[4]) == 2)
                {
                    printf(" \n \n ***************** CEREMINIE : MARIAGE ***************** \n \n ");
                    chronogramme_mariage();
                    chronogramme_gala();
                }
                else if(atoi(row[4]) == 3)
                {
                    printf(" \n \n ***************** CEREMINIE : GALA ***************** \n \n ");
                    chronogramme_gala();
                }
                else
                {
                    printf(" \n \n ***************** CEREMINIE : MARIAGE ***************** \n \n ");
                    chronogramme_mariage();
                }
                //liste des invités
                liste_invite(reun);

                //Menu de la page
                printf("\n \n  1 - Modifier la cérémonie \n");
                printf(" \n  2 - Gestion les invités \n");
                printf(" \n  3 - Gestion des Menus \n");
                printf(" \n  4 - Gestion de cérémonie \n");
                printf(" \n  5 - Accueil \n");
                printf("\n \n  ------->  Taper le numero de votre choiX \n \n");

                do
                {
                    scanf("%d",&choix_menu);
                    switch(choix_menu)
                    {
                        case 1:
                            modifier_ceremonie(reun);
                        case 2:
                            invite(reun);
                            break;
                        case 3:
                            menu();
                            break;
                        case 4:
                            ceremonie();
                            break;
                        case 5:
                            connect_administrateur();
                            break;
                        default:
                            printf(" \n ERREUR DE SAISI, RÉESSAYER SVP! \n");
                            printf("\n ------->  1 - Pour réessayer \n");
                            printf("\n -------> 2 - Gestion cérémonié \n");
                            printf("\n -------> 3 - Accueil \n");
                            scanf("%d",&choix_menu);
                            if (choix_menu == 2)
                            {
                                ceremonie();
                            }
                            else if (choix_menu == 3)
                            {
                                connect_administrateur();
                            }
                            else
                            {
                                choix_menu = 1;
                            }
                    }
                } while (choix_menu == 1);

            }
            else
            {
                printf(" Ce numero ne figure pas dans la liste des céromonie \n \n");
                printf("\n \n -------> 1 - Pour réessayer \n");
                printf("\n -------> 2 - Gestion cérémonié \n");
                printf("\n -------> 3 - Accueil \n");
                scanf("%d",&continuer);
                if (continuer == 2)
                {
                    ceremonie();
                }
                else if (continuer == 3)
                {
                    connect_administrateur();
                }
                else
                {
                    continuer = 1;
                }
            }
            
        } while (continuer == 1);
    }
    else
    {
        printf("\n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}


/**
 * @brief Fonction de modification d'une cérémonie
 * 
 */
void modifier_ceremonie()
{
    //Appel initialisations des differents fonctions
    void ceremonie();
    char *lire(int size);

    //Variables 
    int duree_ceremo, date_ceremo, heure_dine, date_debut, type, num_menu, num_ceremo, continuer;
    char *nom_ceromo, *descri_ceremo;

    printf(" \n \n ***************** MODIFIER UNE CÉREMONIE ***************** \n \n ");

    MYSQL mysql;
    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {
        do
        {
            char add[1000];
            printf("\n \n  -------> Entrer les références de la céremonie <-------\n \n");

            printf("Numéro de la cérémonie : ");
            scanf("%d",&num_ceremo);
            printf("\n Type de cérémonie : \n taper \n");
            printf("\n\t\t 1 - REUNION \n");
            printf("\n\t\t 2 - MARIAGE \n");
            printf("\n\t\t 3 - GALA \n");
            printf("\n\t\t 4 - AUTRE \n");
            scanf("%d",&type);
            printf("\n Nom : ");
            getchar();
            nom_ceromo = lire(30);
            printf("\n Description : ");
            descri_ceremo = lire(255);
            printf("\n Combien de jours avant l'événement : ");
            scanf("%d",&date_ceremo);
            printf("\n Numéro du menu : ");
            scanf("%d",&num_menu);

            time_t date_auj;
            time(&date_auj);
            date_ceremo = date_ceremo * 86400;
            date_ceremo = date_ceremo + date_auj;
            date_debut = date_ceremo;

            sprintf(add, "UPDATE Ceremonie SET nom_ceromo = '%s' , descri_ceremo = '%s', date_ceremo = '%d', date_debut = '%d', type = '%d', num_menu = '%d' WHERE iden_ceromo = '%d'", nom_ceromo, descri_ceremo, abs(date_ceremo), abs(date_debut), type, num_menu, num_ceremo);
            if(!mysql_query(&mysql,add))
            {
                printf(" \n \n La cérémonie a été modier avec succès \n  ");
                printf(" \n Taper un caractere puis Entrer pour continuer \n  ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Taper  1 - Modifier une cérémonie \n ------->  2 - Pour revenir au menu de gestion de cérémonie \n \n");
            scanf("%d",&continuer);
            if (continuer != 1)
            {
                ceremonie();
            }
        } while (continuer == 1);
        
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}


/**
 * @brief Fonction de suppression d'une cérémonie
 * 
 */
void supprimer_ceremonie()
{
    //Appel initialisations des differents fonctions
    void menu();

    //Variables 
    int num_ceremo, continuer;

    printf(" \n \n ***************** SUPPRIMER UNE CÉRÉMONIE ***************** \n \n ");

    printf("\n \n \n ------->  Voulez-vous vraiment supprimer un Menu ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
    scanf("%d",&continuer);
    if (continuer == 1)
    {
        MYSQL mysql;
        //initialisation 
        mysql_init(&mysql);
        mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
        {
            do
            {
                char suppri_inv[1000];
                char suppri[1000];
                printf("\n \n  -------> Entrer le numéro de la cérémonie a supprimer <-------\n \n");
                scanf("%d",&num_ceremo);
                
                sprintf(suppri_inv, "DELETE FROM Invite WHERE num_ceromo = %d ", num_ceremo);
                mysql_query(&mysql, suppri_inv);
                sprintf(suppri, "DELETE FROM Ceremonie WHERE iden_ceromo = %d ", num_ceremo);
                if(!mysql_query(&mysql,suppri))
                {
                    printf(" \n \n La suppression a été realiser avec succès !!! \n ");
                }
                else
                {
                    printf(" \n \n Echec veuillez réessayer !!! \n ");
                }

                printf("\n \n \n ------->  Voulez-vous supprimer une autre cérémonie ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
                scanf("%d",&continuer);
                if (continuer != 1)
                {
                    ceremonie();
                }
            } while (continuer == 1);
            
        }
        else
        {
            printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
        }
    }
    else
    {
        ceremonie();
    }
}


/**
 * @brief Chronogramme de reunion
 * 
 */
void chronogramme_reunion()
{
    printf("  \n \n ***************** CHRONOGRAMMES DE LA REUNION *****************  \n ");
    printf(" \n \n \\t INSTALLATION DES PARTICIPANTS :  \t\t 14h30");
    printf(" \n \n \t ARRIVÉE DU PRESIDENT : \t\t\t14h45");
    printf(" \n \n \t DEBUT DE LA REUNION PAR LES MOTS DU PRESIDENT : 15h00");
    printf(" \n \n \t FIN DE LA REUNION : \t\t\t\t17h00\n");
}


/**
 * @brief Chronogramme de mariage
 * 
 */
void chronogramme_mariage()
{
    printf("  \n \n ***************** CHRONOGRAMMES DE MARIAGE *****************  \n ");
    printf(" \n \n \t ACCUEIL ET INSTALLATION DES INVITÉES : \t\t09h00");
    printf(" \n \n \t ARRIVÉE DES MARIÉS : \t\t\t\t\t09h45");
    printf(" \n \n \t DEBUT DE LA CÉRÉMONIE PAR LE MAIRE/ADJOINT AU MAIRE :  10h00");
    printf(" \n \n \t SEANCE DE PRISE DE PHOTO : \t\t\t\t11h30");
    printf(" \n \n \t FIN DE LA CÉRÉMONIE : \t\t\t\t\t12h00\n");
}


/**
 * @brief Chronogramme de diné gala
 * 
 */
void chronogramme_gala()
{
    printf("  \n \n ***************** CHRONOGRAMME DE DINÉ GALA  *****************  \n ");
    printf(" \n \n \t ACCUEIL ET INSTALLATION DES INVITÉES : 19h00");
    printf(" \n \n \t ARRIVÉE DES OFFICIEUX : \t\t19h30");
    printf(" \n \n \t MOT DE BIENVENU SUIVI DES DISCOURTS : \t19h45");
    printf(" \n \n \t OUVERTURE DU BUFFET : \t\t\t21h00");
    printf(" \n \n \t COMEDIE ET/OU SHOW MUSICAL : \t\t22h00");
    printf(" \n \n \t FIN DE LA CÉRÉMONIE : \t\t\t00h00");
}