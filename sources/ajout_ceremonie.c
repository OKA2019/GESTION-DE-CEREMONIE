/**
 * @file ajout_ceremonie.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Creation une cérémonie
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
#include "../header/chronogramme.h"
#include "../header/lire.h"

/**
 * @brief Après connexion à la base de données. La fonction insert les données de la cérémonie à travers un formulaire
 * 
 */
void ajout_ceremonie()
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    int main();
    char *lire(int size);

    //Variables 
    int duree_ceremo, date_ceremo, heure_dine, date_debut, date_fin, num_menu, duree;
    char continuer, *nom_ceromo, *descri_ceremo;

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
            printf(" Nom : ");
            getchar();
            nom_ceromo = lire(30);
            printf("\n Description : ");
            descri_ceremo = lire(255);
            printf("\n Combien de jours avant l'événement : ");
            scanf("%d",&date_ceremo);
            printf("\n Combien d'heure va durée la céremonie : ");
            scanf("%d",&duree_ceremo);
            printf("\n Numéro du menu : ");
            scanf("%d",&num_menu);
            printf("\n Heure du diné : ");
            scanf("%d",&heure_dine);

            time_t date_auj;
            time(&date_auj);
            date_ceremo = date_ceremo * 86400;
            date_ceremo = date_ceremo + date_auj;
            date_debut = date_ceremo;
            duree_ceremo = duree_ceremo * 3600;
            date_fin = duree_ceremo + date_debut;

            sprintf(add, "INSERT INTO Ceremonie(iden_ceromo, nom_ceromo , descri_ceremo, date_ceremo, date_debut , date_fin, num_menu) VALUES(NULL, '%s', '%s',' %d',' %d', '%d', '%d')", nom_ceromo, descri_ceremo, abs(date_ceremo), abs(date_debut), abs(date_fin), num_menu);
            if(!mysql_query(&mysql,add))
            {
                printf(" \n \n La cérémonie a été ajouter ave succès \n  ");
                printf(" \n Taper un caractere puis Entrer pour continuer \n  ");

                scanf("%s",&continuer);
                main();
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Taper  1 - Ajouter une cérémonie \n ------->  2 - Pour revenir au menu \n \n");
            scanf("%s",&continuer);
            if (continuer != 1)
            {
                main();
            }
        } while (continuer == 1);
        
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}