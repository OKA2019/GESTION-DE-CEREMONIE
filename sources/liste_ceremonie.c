/**
 * @file ajout_invite.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Enregistrement d'un invité
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <string.h>
#include "arpa/inet.h"
#include "MYSQL/mysql.h"
#include "../header/ajout_ceremonie.h"


void liste_ceremonie(){

    int main();
    void ajout_ceremonie();

    int continuer;
    time_t date_ceremo;
    //time(&date_ceremo);
    //initialisation 
    MYSQL mysql;
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   char menuBD[1000];
        sprintf(menuBD,"SELECT iden_ceromo, nom_ceromo, descri_ceremo, from_unixtime(date_ceremo),from_unixtime(date_debut),from_unixtime(date_fin) FROM Ceremonie WHERE date_ceremo >= %d", date_ceremo);
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        printf(" \n \n ***************** LISTE DES CÉRÉMONIES À GERER  ***************** \n \n ");

        while (row = mysql_fetch_row(result))
        {
            printf(" \n \n Numero : %s ", row[0]);
            printf(" \n Nom  : %s", row[1]);
            printf(" \n Description : %s \n", row[2]);
            printf(" \n Date : %s \n", row[3]);
            printf(" \n Debut : %s \n", row[4]);
            printf(" \n Fin : %s \n", row[5]);
        }

        printf("\n \n \n ------->  Taper  1 - Ajouter une cérémonie  ou 2 - Pour revenir au menu \n \n");
        scanf("%d",&continuer);
        if (continuer == 1)
        {
            ajout_ceremonie();
        }
        else
        {
            main();
        }
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    
}