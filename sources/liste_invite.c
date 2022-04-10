/**
 * @file liste_invite.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Liste des invités
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
#include "../header/ceremonie.h"
#include "../header/main.h"


void liste_invite(int num_ceremo)
{
    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   char menuBD[1000];
        sprintf(menuBD,"SELECT * FROM Invite WHERE num_ceromo = %d", num_ceremo);
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);
        
        printf(" \n \n ***************** LISTE DES INVITÉS A LA CÉREMONIE ***************** \n \n ");
        //Tant qu'il y a encore un résultat ...
        while (row = mysql_fetch_row(result))
        {
            printf("\n \n Numéro de table : %s", row[7]);
            printf(" \n Numéro de siège : %s", row[8]);
            printf(" \n Noms : %s %s", row[1], row[2]);
            printf(" \n Age : %s", row[3]);
            printf(" \n contact : %s", row[4]);
            printf(" \n residence : %s", row[5]);
            if(atoi(row[6]) == 0)
            {
                printf(" \n sexe : Femme");
            }
            else
            {
                printf(" \n sexe : Homme");
            }
        }

    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    
}