/**
 * @file lire.c
 * @author OUATTARA KOUNAPETRI ABDOULAYE (kounapetri05@gmail.com)
 * @brief Recupération des saisi
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) SIGL2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Réccupère la chaine de caractères
 * 
 */

char *lire(int size){
    int i = 0;

    char* text = (char*) malloc(sizeof(char)*size);

    while(i < size){
        scanf("%c", &text[i]);
        if(text[i] == '\n') break ;
        else i++ ;
    }
    text[i] = '\0';
    return text ;
}