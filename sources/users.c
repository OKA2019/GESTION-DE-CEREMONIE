/**
 * @file users.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Connexion des invités et des Administrateurs
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
#include "../header/main.h"
#include "../header/menu.h"
#include "../header/ceremonie.h"
#include "../header/invite.h"
#include "../header/lire.h"

/**
 * @brief Connexion de l'administateur
 * 
 */

void connect_administrateur()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    void ceremonie();
    void ajout_ceremonie();
    void menu();
    void invite();
    char *lire(int size);

    //Variables 
    int choix_menu = 0, continuer;
    char *nom_gestion, *pass_gestion;

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {
        do
        {
            //On efface l'écrans
            system("clear");
            printf("\n**************************  AUTHENTIFICATION DU GESTIONNAIRE **************************\n\n");
    
            printf("\n\t Entrer votre d'utilisateur \n");
            getchar();
            nom_gestion = lire(31);
            printf("\t Entrer votre mot de pass \n");
            pass_gestion = lire(51);

            char menuBD[5000];
            sprintf(menuBD,"SELECT * FROM gestionnaire WHERE nom_gestion = '%s' AND pass_gestion = '%s' ", nom_gestion, pass_gestion);
        
            mysql_query(&mysql, menuBD);
            MYSQL_RES *resultat = NULL;
            MYSQL_ROW row;
            int i = 1;
            resultat = mysql_use_result(&mysql);
            printf("\n %s \n", resultat);
            row = mysql_fetch_row(resultat);
            if(row != NULL)
            {
                do
                {
                    printf(" \n  1 - Cérémonie \n");
                    printf(" \n  2 - Menu \n");
                    printf(" \n  3 - Se connecter a une cérémonie \n");
                    printf(" \n  4 - Home \n");
                    printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
                    scanf("%d",&choix_menu);
                    switch(choix_menu)
                    {
                        case 1:
                            ceremonie();
                            break;
                        case 2:
                            menu();
                            break;
                        case 3:
                            connect_ceremenie();
                            break;
                        case 4:
                            main();
                            break;
                        default:
                            printf(" \n ERREUR DE SAISI ! ");
                            printf("\n \n \n ------->  Taper  1 - pour réessayer \n ------->  2 - Pour revenir à l'accueil \n \n");
                            scanf("%d",&choix_menu);
                            if (choix_menu != 1)
                            {
                                main();
                                break;
                            }
                    }
                } while (choix_menu == 1);
            }
            else
            {
                printf("\tErreur, ces coordonnées ne figure pas dans notre base \n \n");
                printf("\n \n -------> 1 - Pour réessayer \n");
                printf("\n -------> 2 - Accueil \n");
                scanf("%d",&continuer);
                if (continuer == 2)
                {
                    main();
                }
                else
                {
                    continuer = 1;
                }
            }
        }while (continuer == 1);
    }
    else
    {
        printf("\n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }

}


/**
 * @brief Connexion des invités
 * 
 */
void connect_invite()
{
    int iden_ceremo, iden_invite, continuer, choix, choix_menu, menu;
   
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {
        do
        {
            printf("\n**************************  AUTHENTIFICATION  **************************\n\n");
            printf("\t Entrer le numéro de la cérémonie \n");
            scanf("%d", &iden_ceremo);
            printf("\t Entrer votre identifiant \n");
            scanf("%d", &iden_invite);

            char menuBD[5000];
            sprintf(menuBD,"SELECT nom_ceromo, descri_ceremo, from_unixtime(date_ceremo,'%W, %D %M %Y'), num_menu, type, Menu.entrer, Menu.plat, Menu.dessert, nom, prenoms, age, contact, residence, sexe, num_table, num_siege, Invite.entrer, Invite.plat, Invite.dessert FROM Ceremonie, Invite, Menu WHERE iden_menu = num_menu AND num_ceromo = iden_ceromo AND num_ceromo = %d AND id_invite = %d ", iden_ceremo, iden_invite);
        
            mysql_query(&mysql, menuBD);
            MYSQL_RES *resultat = NULL;
            MYSQL_ROW row;
            int i = 1;
            resultat = mysql_use_result(&mysql);
            printf("\n %s \n", resultat);
            row = mysql_fetch_row(resultat);
            if(row != NULL)
            {
                do
                {
                    //On efface l'écrans
                    system("clear");
                    if(atoi(row[4]) == 1)
                    {
                        printf(" \n \n ***************** CEREMINIE : REUNION ***************** \n \n ");
                        printf(" \t Description de la cérémonie : %s \n  ",row[1]);
                        printf(" \t Date : %s \n  ",row[2]);
                    }
                    else if(atoi(row[4]) == 2)
                    {
                        printf(" \n \n ***************** CEREMINIE : MARIAGE ***************** \n \n ");
                        printf(" \t Description de la cérémonie : %s \n  ",row[1]);
                        printf(" \t Date : %s \n  ",row[2]);
                    }
                    else if(atoi(row[4]) == 3)
                    {
                        printf(" \n \n ***************** CEREMINIE : GALA ***************** \n \n ");
                        printf(" \t Description de la cérémonie : %s \n  ",row[1]);
                        printf(" \t Date : %s \n  ",row[2]);
                    }
                    else
                    {
                        printf(" \n \n ***************** CEREMINIE : MARIAGE ***************** \n \n ");
                        printf(" \t Description de la cérémonie : %s \n  ",row[1]);
                        printf(" \t Date : %s \n  ",row[2]);
                        
                    }

                    //Menu de la page
                    printf("\n \n  1 - Profil \n");
                    printf(" \n  2 - Chronogramme \n");
                    printf(" \n  3 - Accueil \n");
                    printf("\n \n  ------->  Taper le numero de votre choiX \n \n");

                    scanf("%d",&choix_menu);
                    switch(choix_menu)
                    {
                        case 1:
                            //On efface l'écrans
                            system("clear");
                            printf("\n**************************  PROFIL  **************************\n\n");
                            printf(" \n \t\t MES COORDONNÉES");
                            printf(" \n Nom et prénoms : %s %s ", row[8], row[9]);
                            printf(" \n Age : %s", row[10]);
                            printf(" \n Contact : %s ", row[11]);
                            printf(" \n residence : %s", row[12]);
                            if(atoi(row[13]) == 0)
                            {
                                printf(" \n sexe : Femme");
                            }
                            else
                            {
                                printf(" \n sexe : Homme ");
                            }
                            printf(" \n Place : \tTable N°%s Siège N°%s \n", row[14], row[15]);

                            printf(" \n\n \t\t MENU DISPONIBLE");
                            printf(" \n Entrer %s ", row[5]);
                            printf(" \n Plat : %s", row[6]);
                            printf(" \n Dessert : %s \n", row[7]);
                            printf(" \n \n \t\t Votre choix");
                            printf(" \n Entrer %s ", row[16]);
                            printf(" \n Plat : %s", row[17]);
                            printf(" \n Dessert : %s \n", row[18]);
                            printf("\n \n ------->  1 - Modifier mes informations \n");
                            printf("\n ------->  2 - Retour \n");
                            printf("\n ------->  3 - Accueil \n");
                            scanf("%d",&menu);
                            if(menu == 1)
                            {
                                modifier_invite(iden_ceremo);
                                choix_menu = 1;
                            }
                            else if (menu == 3)
                            {
                                main();
                                break;
                            }
                            else
                            {
                                choix_menu = 1;
                            }
                            break;
                        case 2:
                            if(atoi(row[4]) == 1)
                            {
                                chronogramme_reunion();
                            }
                            else if(atoi(row[4]) == 2)
                            {
                                chronogramme_mariage();
                                chronogramme_gala();
                            }
                            else if(atoi(row[4]) == 3)
                            {
                                chronogramme_gala();
                            }
                            else
                            {
                                chronogramme_mariage();
                            }
                            printf("\n \n \n ------->  1 - Pour retour \n");
                            printf("\n -------> 2 - Accueil \n");
                            scanf("%d",&menu);
                            if (menu == 2)
                            {
                                main();
                                break;
                            }
                            else
                            {
                                choix_menu = 1;
                            }
                            break;
                        case 3:
                            main();
                            break;
                        default:
                            printf(" \n ERREUR DE SAISI, RÉESSAYER SVP! \n");
                            printf("\n -------> 1 - Pour réessayer \n");
                            printf("\n -------> 2 - Accueil \n");
                            scanf("%d",&menu);
                            if (menu == 2)
                            {
                                main();
                                break;
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
                printf("\n -------> 2 - Accueil \n");
                scanf("%d",&continuer);
                if (continuer == 2)
                {
                    main();
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
