/**
 * @file chronogramme.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Liste le chronogramme de la cérémonie
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
    
void chronogramme(char *nom_ceromo,char *descri_ceremo, char *date_ceremo,char *date_debut, char *date_fin, char *num_menu)
{

    //variables locales
    char row[100];
    int choix;

    printf("  \n \n ******************************** CHRONOGRAMMES %s \n \n %s ******************************** \n \n ", nom_ceromo, descri_ceremo);
    printf(" \n \n  Date de la céremonie %s", date_ceremo);
    printf(" \n \n Début %s", date_debut);
    printf(" \n \n Fin %s ", date_fin);
}