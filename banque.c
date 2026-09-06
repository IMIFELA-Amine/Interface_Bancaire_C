#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define LONGUEUR_NOM 255
#define PLAFOND_MAX 1000000000
#define LOGIN_MAX 30
#define MOT_DE_PASSE 30

typedef struct {
    char nom[LONGUEUR_NOM];
    char prenom[LONGUEUR_NOM];
    char dateDeNaissance[11];
    int solde;
}Client;

typedef struct {
    char login[LOGIN_MAX];
    char mot_de_passe[MOT_DE_PASSE];
    char fonction[100];
}Admin;

typedef enum {
    PAGE_PRINCIPALE, // 0
    PAGE_INFO_CLIENT, // 1
    PAGE_CLIENT, // 2
    PAGE_VIREMENT_CLIENT,
    PAGE_SOLDE_CLIENT,
    PAGE_HISTORIQUE_CLIENT,
    PAGE_BANQUIER, // 3
    PAGE_INFO_BANQUIER, // 4
    QUITTER // 5
}Etat;

// typedef enum {
//     ASSISTANT,
//     EMPLOYE,
//     CADRE,
//     CADRE_SUPERIEURE,
//     DIRECTEUR
// }GRADE;

char *listeGrade[] = {"Assistant", "Enmploye", "Cadre", "Cadre superieure", "Directeur"};



int verifier_admin(char fonction[]){
    int resultat = 1;
    for (int i = 0; i<5; i++){

        resultat  = strcmp(fonction, listeGrade[i]);
        if (resultat == 0){
            break;
        }


    }
    return resultat;
}


int main(void){

    srand(time(NULL));

    Etat etatCourant = PAGE_PRINCIPALE;
    int choix = 0;

    // Creation de compte CLIENT
    Client *bibliothequeClient = malloc(30*sizeof(Client));
    if(bibliothequeClient == NULL){
        printf("Erreur d'allocation client");
    }

    // Creation de compte fictif
    char *listeNom[] = {"Martin", "Bernard", "Thomas", "Petit", "Robert", "Richard", "Durand", "Dubois", "Moreau", "Laurent", "Simon", "Michel", "Lefebvre", "Leroy", "Roux", "David", "Bertrand", "Morel", "Fournier", "Girard", "Bonnet", "Dupont", "Lambert", "Fontaine", "Rousseau", "Vincent", "Muller", "Lefevre", "Faure", "Andre"};
    char *listePrenom[] = {"Jean", "Marie", "Pierre", "Jeanne", "Michel", "Francoise", "Jacques", "Monique", "Alain", "Catherine", "Philippe", "Nathalie", "Christophe", "Isabelle", "Nicolas", "Sylvie", "Laurent", "Anne", "Marc", "Martine", "Julien", "Camille", "Romain", "Chloe", "Luc", "Emma", "Antoine", "Lea", "Paul", "Lucas"};
    char *listeDateDeNAissance[] = {"12/05/1985", "23/11/1990", "04/07/1978", "15/02/2001", "30/09/1995", "08/12/1982", "19/04/1999", "27/08/1975", "11/01/1988", "03/06/1992", "14/10/1980", "25/03/1997", "09/09/1986", "21/05/1979", "02/11/2003", "18/07/1994", "29/01/1983", "07/04/1991", "16/08/1976", "22/12/1989", "05/03/1998", "13/06/1981", "28/10/1996", "01/02/1987", "17/09/1977", "24/04/1993", "10/08/1984", "31/12/2000", "06/05/1999", "20/11/1985"};
    int listesolde[30] = {12500, 4500, 31000, 1500, 89000, 2300, 14500, 67000, 1200, 9400, 32000, 4100, 18500, 7500, 53000, 9800, 16000, 2400, 81000, 3900, 11000, 62000, 45000, 8700, 19000, 3400, 72000, 15600, 48000, 21000};

    for(int i = 1; i<30;i++){

        int j = rand()%30;

        strcpy(bibliothequeClient[i].nom,listeNom[j]);
        strcpy(bibliothequeClient[i].prenom,listePrenom[j]);
        strcpy(bibliothequeClient[i].dateDeNaissance,listeDateDeNAissance[j]);  
        bibliothequeClient[i].solde = listesolde[j];
    }

    for(int i = 1; i<30;i++){

        printf("Nom = %s\n", bibliothequeClient[i].nom);
        printf("Prenom = %s\n", bibliothequeClient[i].prenom);
        printf("Date de naissance = %s\n", bibliothequeClient[i].dateDeNaissance);
        printf("solde = %d\n", bibliothequeClient[i].solde);
        printf("====================\n");

    }
    
    // Creation compte ADMIN
    Admin admin1;

    //Boucle générale
    while(etatCourant != QUITTER)
    {
        switch(etatCourant)
        {
            case PAGE_PRINCIPALE: // 0
                printf("======= BIENVENUE A LA BANQUEE =========\n");
                printf("Faite votre choix : \n");
                printf("1 : ACCES COMPTE CLIENT\n");
                printf("2 : ACCES COMPTE ADMIN\n");
                scanf("%d", &choix);

                if(choix == 1){
                    etatCourant = PAGE_INFO_CLIENT;
                }
                else if(choix == 2 ){
                    etatCourant = PAGE_INFO_BANQUIER;
                }
                else {
                    printf("!!!!!! NOUS N'AVONS PAS COMPRIS VOTRE CHOIX !!!!!!\n");
                    printf("Faite votre choix : \n");
                    printf("1 : ACCES COMPTE CLIENT\n");
                    printf("2 : ACCES COMPTE ADMIN\n");
                    scanf("%d", &choix);
                }
                break;


            case PAGE_INFO_CLIENT:
                printf("=====LA BANQUE=====\n");
                printf("Entrez votre nom\n");
                scanf("%s", bibliothequeClient[0].nom);
                printf("Entrez votre prenom\n");
                scanf("%s", bibliothequeClient[0].prenom);
                printf("Entrez votre date de naissance (01/01/1970) \n");
                scanf("%s", bibliothequeClient[0].dateDeNaissance);
                bibliothequeClient[0].solde = rand()%1000000000+1;
                printf("=======================\n");
                printf("QUE VOULEZ VOUS FAIRE Mr %s %s ?\n", bibliothequeClient[0].nom,bibliothequeClient[0].prenom);
                printf("1 : Virement\n");
                printf("2 : Consulter votre solde\n");
                printf("3 : Consulter votre historique bancaire\n");
                choix = 0;
                scanf("%d", &choix);

                if(choix == 1){
                    etatCourant = PAGE_VIREMENT_CLIENT;
                }
                else if(choix == 2){
                    etatCourant = PAGE_SOLDE_CLIENT;
                }
                else if (choix == 3){
                    etatCourant = PAGE_HISTORIQUE_CLIENT;
                }
                else {
                    printf("!!!!!! NOUS N'AVONS PAS COMPRIS VOTRE CHOIX !!!!!!\n");
                    printf("=======================\n");
                    printf("QUE VOULEZ VOUS FAIRE Mr %s %s ?\n", bibliothequeClient[0].nom,bibliothequeClient[0].prenom);
                    printf("1 : Virement\n");
                    printf("2 : Consulter votre solde\n");
                    printf("3 : Consulter votre historique bancaire\n");

                }
                break;  
                
            case PAGE_INFO_BANQUIER:
            
                printf("======== PAGE ADMINISTARTEUR BANQUIER ========= \n");
                printf("Login : \n");
                scanf("%s", admin1.login);
                printf("Mot de passe : \n");
                scanf("%s", admin1.mot_de_passe);
                printf("Fonction : \n");
                scanf("%s", admin1.fonction);
                int verification = verifier_admin(admin1.fonction);

                if (verification == 0) {

                    printf("Chargement ...... \n");
                    sleep(5);
                    printf("En attente de la récuperation des données\n");
                    sleep(3);
                    // printf("Bonjour %s et bienvenue sur votre Tableau de bord\n")
                    etatCourant = PAGE_BANQUIER;
                    break;
                }
                else{
                    break;
                }
                
        }




    }

    

    free(bibliothequeClient);

    return 0;
}