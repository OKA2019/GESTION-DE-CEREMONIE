/**
 * @file invite.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Gestion des invités
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
#include "../header/menu.h"
#include "../header/main.h"
#include "../header/lire.h"

/**
 * @brief Fonction principale de gestion des invitées
 * 
 * @param num_ceremo numéro d'identifiant de la cérémonie
 */
void invite(int num_ceremo)
{
    //On efface l'écrans
    system("clear");
    
    //Appel initialisations des differents fonctions
    int main();
    void ajout_invite(int num_ceremo);
    void modifier_invite(int num_ceremo);
    void suprimer_invite(int num_ceremo);
    void liste_invite(int num_ceremo);

    //Variables 
    int choix_menu, continuer;

    printf(" \n \n ***************** GESTION DES INVITES DE LA CÉREMONIE ***************** \n \n ");
    liste_invite(num_ceremo);

    printf("\n \n \n ------->  Voulez-vous Faire ? <------- \n ");
    printf("\n  -------> 1 - Ajouter un invité \n ");
    printf("\n  -------> 2 - Modifier un invité \n");
    printf("\n  -------> 3 - Supprimé un invité \n ");
    printf("\n  -------> 4 - Retour \n \n");
    do
    {
        scanf("%d",&choix_menu);
        switch (choix_menu)
        {
        case 1:
            ajout_invite(num_ceremo);
            break;
        case 2:
            system("clear");
            modifier_invite(num_ceremo);
            break;
        case 3:
            system("clear");
            supprimer_menu(num_ceremo);
            break;
        case 4:
            main();
            break;
        default:
            printf(" \n ERREUR DE SAISI, RÉESSAYER SVP! \n ");
            printf("\n \n \n -------> 1 - pour réessayer \n ------->  2 - Pour revenir au menu de gestion de cérémonie \n \n");
            scanf("%d",&choix_menu);
            if (choix_menu != 1)
            {
                main();
            }
    }
    } while (choix_menu == 1);
}


/**
 * @brief Enregistrement d'un invité
 * 
 * @param num_ceremo numéro d'identifiant de la cérémonie
 */
void ajout_invite(int num_ceremo){
    void invite();
    int main();

    int ajouter = 1, age, sexe = 0, num_table, num_siege, continuer = 1, id_invite = 0;
    char *nom, *prenoms, *residence, *entrer, *plat, *dessert, *contacts;

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   
        char menuBD[1000];
        sprintf(menuBD,"SELECT entrer, plat, dessert FROM Menu, Ceremonie WHERE iden_menu = num_menu AND iden_ceromo = %d", num_ceremo);
        mysql_query(&mysql, menuBD);
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;
        result = mysql_use_result(&mysql);
        do
        {
            printf(" \n \n INSCRIPTION D'UN INVITÉ \n \n ");

            printf(" \n Nom :  ");
            getchar();
            nom = lire(30);
            printf("\n Prenoms :  ");
            prenoms = lire(255);
            printf("\n Age :  ");
            scanf("%d",&age);
            printf(" \n Sexe :  \n Taper  1 - Homme           2 - Femme \n ");
            scanf("%d",&sexe);
            if(sexe != 1)
            {
                sexe = 0;
            }
            printf(" \n Contact :  ");
            getchar();
            contacts = lire(11);
            printf(" \n Residence :  ");
            residence = lire(50);
            printf(" \n Numero de table :  ");
            scanf("%d",&num_table);
            printf(" \n Numero de siège :  ");
            scanf("%d",&num_siege);

            printf(" \n -------> Veuillez faire un choix parmi le menu ci-dessous \n  ");
 
            while (row = mysql_fetch_row(result))
            {
                printf(" \n \n Entrer %s ", row[0]);
                printf(" \n Plat : %s", row[1]);
                printf(" \n Dessert : %s \n", row[2]);
            }

            printf(" \n Entrer :  ");
            getchar();
            entrer = lire(255);
            printf(" \n Plat :  ");
            plat = lire(255);
            printf(" \n Dessert :  ");
            dessert = lire(255);

            char add[1000]; 
            //Copie de la requette dans la variables add
            sprintf(add, "INSERT INTO Invite(id_invite, nom, prenoms, age, contact, residence, sexe, num_table, num_siege, num_ceromo, entrer, plat, dessert) VALUES(0, '%s', '%s', %d, '%s', '%s', %d, %d, %d, %d, '%s', '%s', '%s')", nom, prenoms, age, contacts, residence, sexe, num_table, num_siege, num_ceremo, entrer, plat, dessert);
            if(!mysql_query(&mysql,add))
            {
                printf("\n \n Inscription valider avec succès !!! \n \n ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Taper  1 - Ajouter un invité  ou 2 - Pour revenir au menu \n \n");
            scanf("%d",&continuer);
            if (continuer != 1)
            {
                invite(num_ceremo);
            }
        } while (ajouter == 1);


    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    
}


/**
 * @brief Liste des invités
 * 
 * @param num_ceremo numéro d'identifiant de la cérémonie
 */
void liste_invite(int num_ceremo)
{
    MYSQL mysql;
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
        
        printf(" \n \n \n ***************** LISTE DES INVITÉS A LA CÉREMONIE ***************** \n ");
        //Tant qu'il y a encore un résultat ...
        while (row = mysql_fetch_row(result))
        {
            printf("\n Numéro de table : %s", row[0]);
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
                printf(" \n sexe : Homme \n \n");
            }
        }

    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
    
}


/**
 * 
 * @brief Modification d'un invité
 * 
 * @param num_ceremo numéro d'identifiant de la cérémonie
 */
void modifier_invite(int num_ceremo){

    void invite(num_ceremo);
    int main();

    int ajouter = 1, iden_invite, age, sexe = 0, num_table, num_siege, continuer = 1, id_invite = 0;
    char *nom, *prenoms, *residence, *entrer, *plat, *dessert, *contacts;
    MYSQL mysql;

    //initialisation 
    mysql_init(&mysql);

    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
        
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {   
        char menuBD[1000];
        sprintf(menuBD,"SELECT entrer, plat, dessert FROM Menu, Ceremonie WHERE iden_menu = num_menu AND iden_ceromo = %d", num_ceremo);
        mysql_query(&mysql, menuBD);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;

        result = mysql_use_result(&mysql);

        do
        {
            printf(" \n \n INSCRIPTION D'UN INVITÉ \n \n ");

            printf(" \n Numero d'identifiant de l'invité :  ");
            scanf("%d",&iden_invite);
            printf(" \n Nom :  ");
            getchar();
            nom = lire(30);
            printf("\n Prenoms :  ");
            prenoms = lire(255);
            printf("\n Age :  ");
            scanf("%d",&age);
            printf(" \n Sexe :  \n Taper  1 - Homme           2 - Femme \n ");
            scanf("%d",&sexe);
            if(sexe != 1)
            {
                sexe = 0;
            }
            printf(" \n Contact :  ");
            getchar();
            contacts = lire(11);
            printf(" \n Residence :  ");
            residence = lire(50);
            printf(" \n Numero de table :  ");
            scanf("%d",&num_table);
            printf(" \n Numero de siège :  ");
            scanf("%d",&num_siege);

            printf(" \n -------> Veuillez faire un choix parmit le menu ci-dessous \n  ");
 
            while (row = mysql_fetch_row(result))
            {
                printf(" \n \n Entrer %s ", row[0]);
                printf(" \n Plat : %s", row[1]);
                printf(" \n Dessert : %s \n", row[2]);
            }

            printf(" \n Entrer :  ");
            getchar();
            entrer = lire(255);
            printf(" \n Plat :  ");
            plat = lire(255);
            printf(" \n Dessert :  ");
            dessert = lire(255);

            char add[1000]; 
            //Copie de la requette dans la variables add
            sprintf(add, "UPDATE SET nom = '%s' , prenoms = '%s', age '%d', contact '%s', residence = '%s' , sexe = '%d', num_table = '%d', num_siege = '%d', entrer = '%s', plat = '%s', dessert = '%s' FROM Invite WHERE id_invite = '%d' AND num_ceromo = '%d'", nom, prenoms, age, contacts, residence, sexe, num_table, num_siege, entrer, plat, dessert, iden_invite, num_ceremo);
            if(!mysql_query(&mysql,add))
            {
                printf("\n \n Inscription valider avec succès !!! \n \n ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Taper  1 - Modifier un invité  ou 2 - Pour revenir au menu \n \n");
            scanf("%d",&continuer);
            if (continuer != 1)
            {
                invite(num_ceremo);
            }
        } while (ajouter == 1);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}


/**
 * 
 * @brief Supprimer un invité
 * 
 * @param num_ceremo numéro d'identifiant de la cérémonie
 */
void supprimer_invite(int num_ceremo){

    void invite(num_ceremo);
    int main();

    int iden_invite, continuer;

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,"localhost","oka2019","123456789","examenCavance",0,NULL,0))
    {
        do
        {
            char suppri[1000];
            printf("\n \n  -------> Entrer l'identifiant de l'invité a supprimer <-------\n \n");
            scanf("%d",&iden_invite);
            
            sprintf(suppri, "DELETE FROM Invite WHERE iden_ceromo = '%d' AND id_invite ='%d' ", num_ceremo, iden_invite);
            if(!mysql_query(&mysql,suppri))
            {
                printf(" \n \n La suppression a été realiser avec succès !!! \n ");
            }
            else
            {
                printf(" \n \n Echec veuillez réessayer !!! \n ");
            }

            printf("\n \n \n ------->  Voulez-vous supprimer un autre invité ? \n \n   1 - OUI \n   2 - NON (retour au menu principal) \n \n");
            scanf("%d",&continuer);
            if (continuer != 1)
            {
                invite(num_ceremo);
            }
        } while (continuer == 1);
    }
    else
    {
        printf("  \n \n Erreur de connexion a la base au niveau d'ajout des adherents \n \n ");
    }
}

