/**
 * @file ceremonie.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Enregistrement d'un invité
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
#include "../header/invite_ceremonie.h"
#include "../header/chronogramme.h"
#include "../header/main.h"

void ceremonie()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    int main();
    void invite_ceremonie(int num_reun);
    void chronogramme(char *nom_ceromo,char *descri_ceremo, char *date_ceremo,char *date_debut, char *date_fin, char *num_menu);

    //Variables 
    int reun, choix_cereom, choix_menu, compte_exit;
    char continuer;

    printf("\n \n \n --------------->  Voulez-vous vraiment gerer une cérémonie ? <----------  \n \n  ---------------> 1 - OUI \n  ---------------> 2 - NON (retour au menu principal) \n \n");
    scanf("%d", &choix_cereom);
    
    if (choix_cereom == 1)
    
        {MYSQL mysql;
        mysql_init(&mysql);
        mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
        {
            char menuBD[1000];
            printf(" ----------> Enter le numero de la ceremonie \n");
            scanf("%d", &reun);

            sprintf(menuBD,"SELECT nom_ceromo, descri_ceremo,from_unixtime(date_ceremo),from_unixtime(date_debut),from_unixtime(date_fin),num_menu FROM Ceremonie WHERE iden_ceromo = %d", reun);
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
                    printf(" \n \n ***************** GESTION DES CEREMINIE ***************** \n \n ");

                    printf(" \n  1 - Chronogramme \n");
                    printf(" \n  2 - invite \n");
                    printf(" \n  3 - Accueil \n");
                    printf("\n \n  ------->  Taper le numero de votre choiX \n \n");

                    do
                    {
                        scanf("%d",&choix_menu);
                        switch(choix_menu)
                        {
                            case 1:
                                //Appel de la fonctions Chronogramme
                                chronogramme(row[0], row[1], row[2], row[3], row[4], row[5]);
                                printf(" \n \n \n veuiller faire bun choix \n");
                                printf(" \n  2 - invite \n");
                                printf(" \n  3 - Accueil \n");
                                printf("\n \n  ------->  Taper le numero de votre choiX \n \n");
                                scanf("%d",&choix_menu);
                            case 2:
                                //Appel de la fonctions invite
                                invite_ceremonie(atoi(row[5]));
                                break;
                            case 3:
                                //Appel de la fonctions main
                                main();
                                break;
                            default:
                                printf(" \n ERREUR DE SAISI, RÉESSAYER SVP! ");
                                choix_menu == 0;
                        }
                    } while (choix_menu == 0);

                }
                else
                {
                    printf(" Ce numero ne fugure pas dans la liste des céromonie \n \n");
                }

                printf("\n \n \n ------->  Taper  1 - Pour réessayer  ou 2 - Pour revenir au menu \n \n");
                scanf("%s",&continuer);
                if (continuer != 1)
                {
                    main();
                }
            } while (continuer == 1);
            
            
        }
        else
        {
            printf("\n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
        }
    }
    else
    {
        main();
    }
}