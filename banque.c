    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #define LONGUEUR_NOM 255
    #define PLAFOND_MAX 1000000000

    typedef struct {
        char nom[LONGUEUR_NOM];
        char prenom[LONGUEUR_NOM];
        char dateDeNaissance[11];
        int solde;
    }Client;

    typedef struct {
        char nom[LONGUEUR_NOM];
        char prenom[LONGUEUR_NOM];
        char fonction[100];
    }Admin;

    typedef enum {
        PAGE_PRINCIPALE, // 0
        PAGE_INFO_CLIENT, // 1
        PAGE_CLIENT, // 2
        PAGE_BANQUIER, // 3
        PAGE_INFO_BANQUIER, // 4
        QUITTER // 5
    }Etat;

    int main(void){

        srand(time(NULL));

        Etat etatCourant = PAGE_PRINCIPALE;
        int choix = 0;

        // Creation de compte
        Client *bibliothequeClient = malloc(30*sizeof(Client));
        if(bibliothequeClient == NULL){
            printf("Erreur d'allocation client");
        }

        // Creation de compte fictif
        char listeNom[29] = {"Martin", "Bernard", "Thomas", "Petit", "Robert", "Richard", "Durand", "Dubois", "Moreau", "Laurent", "Simon", "Michel", "Lefebvre", "Leroy", "Roux", "David", "Bertrand", "Morel", "Fournier", "Girard", "Bonnet", "Dupont", "Lambert", "Fontaine", "Rousseau", "Vincent", "Muller", "Lefevre", "Faure", "Andre"};
        char listePrenom[29] = {"Jean", "Marie", "Pierre", "Jeanne", "Michel", "Francoise", "Jacques", "Monique", "Alain", "Catherine", "Philippe", "Nathalie", "Christophe", "Isabelle", "Nicolas", "Sylvie", "Laurent", "Anne", "Marc", "Martine", "Julien", "Camille", "Romain", "Chloe", "Luc", "Emma", "Antoine", "Lea", "Paul", "Lucas"};
        char listeDateDeNAissance[29] = {"Jean", "Marie", "Pierre", "Jeanne", "Michel", "Francoise", "Jacques", "Monique", "Alain", "Catherine", "Philippe", "Nathalie", "Christophe", "Isabelle", "Nicolas", "Sylvie", "Laurent", "Anne", "Marc", "Martine", "Julien", "Camille", "Romain", "Chloe", "Luc", "Emma", "Antoine", "Lea", "Paul", "Lucas"};
        int listesolde[29] = {12500, 4500, 31000, 1500, 89000, 2300, 14500, 67000, 1200, 9400, 32000, 4100, 18500, 7500, 53000, 9800, 16000, 2400, 81000, 3900, 11000, 62000, 45000, 8700, 19000, 3400, 72000, 15600, 48000, 21000};

        for(int i = 1; i<31;i++){

            int j = rand()%30;

            strcpy(bibliothequeClient[i].nom,listeNom[j]);
            strcpy(bibliothequeClient[i].prenom,listePrenom[j]);
            strcpy(bibliothequeClient[i].dateDeNaissance,listeDateDeNAissance[j]);
            strcpy(bibliothequeClient[i].solde,listesolde[j]);
        }

        for(int i = 1; i<31;i++){

            printf("Nom = %s", bibliothequeClient[i].nom);
            printf("Prenom = %s", bibliothequeClient[i].prenom);
            printf("Date de naissance = %s", bibliothequeClient[i].dateDeNaissance);
            printf("solde = %d", bibliothequeClient[i].solde);

        }        

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
                    printf("=====LA BANQUE=====");
                    printf("Entrez votre nom\n");
                    scanf("%s", bibliothequeClient[0].nom);
                    printf("Entrez votre prenom\n");
                    scanf("%s", bibliothequeClient[0].prenom);
                    printf("Entrez votre date de naissance (01/01/1970) \n");
                    scanf("%s", bibliothequeClient[0].dateDeNaissance);
                    bibliothequeClient[0].solde = rand()%1000000000+1;
                    printf("=======================\n");
                    printf("QUE VOULEZ VOUS FAIRE ?\n");
                    break;  
                    
                    
            }




        }

        


        return 0;
    }