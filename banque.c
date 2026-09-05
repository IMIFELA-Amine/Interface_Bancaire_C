#include <stdio.h>
#include <stdlib.h>
#define LONGUEUR_NOM 255
#define PLAFOND_MAX 1000000000

typedef struct {
    char nom[LONGUEUR_NOM];
    char prenom[LONGUEUR_NOM];
    int dateDeNaissance[8];
    int solde[PLAFOND_MAX];
}Client;

typedef struct {
    char nom[LONGUEUR_NOM];
    char prenom[LONGUEUR_NOM];
    char fonction[100];
}Admin;

typedef enum {
    PAGE_PRINCIPALE,
    PAGE_CLIENT,
    PAGE_BANQUIER,
    QUITTER
}Etat;

int main(void){

    Etat etatCourant = PAGE_PRINCIPALE;

    


    return 0;
}