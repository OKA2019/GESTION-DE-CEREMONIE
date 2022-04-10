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
        printf(" \n \n ***************** LISTE DES MENUS  ***************** \n \n ");

        while (row = mysql_fetch_row(result))
        {
            printf(" \n \n Numéro %s ", row[0]);
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