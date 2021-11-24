#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int option;
int nombre_de_comptes_a_ajouter;
int compteur_de_comptes = 0;
int index_cin = 0;
char comptes_bancaires_cin[100][30];
char comptes_bancaires_noms[100][30];
int comptes_bancaires_montants[100];
float pourcentage_a_ajouter[3];
char tmp[30];
int montant_retrait_depot = 0;
int trouve = 0;

void separer(){
    printf("\n\n\n\n\n\n\n\n");
}

void menu_principal(){
    separer();
    printf("===================================| MENU PRINCIPAL |================================\n\n\n");
    printf("\t1.Introduire un compte bancaire (CIN, Nom et Prenom, montant).\n");
    printf("\t2.Introduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant).\n");
    printf("\t3.Operations .\n");
    printf("\t4.Affichage.\n");
    printf("\t5.Fidelisation.\n");
    printf("\t0.Quitter l application.\n\n");
    printf("======================================================================================\n");
}
void entree_compte(){
    printf("\nVeuillez entrer CIN du client : ");
    scanf("%s", &comptes_bancaires_cin[compteur_de_comptes]);
    printf("\nVeuillez entrer le nom du client sous la forme (Nom.Prenom) : ");
    scanf("%s", &comptes_bancaires_noms[compteur_de_comptes]);
    printf("\nVeuillez entrer le solde du client : ");
    scanf("%d", &comptes_bancaires_montants[compteur_de_comptes]);
    compteur_de_comptes++;

}
int recherche_par_cin(){
    char recherche_cin[30];
    int index_cin_fonction;
    do{
        printf("Veuillez entrer CIN du client : ");
        scanf("%s", &recherche_cin);
        for (int i = 0; i < compteur_de_comptes; i++) {
            for (int j = 0; j < 30; j++) {
                tmp[j] = comptes_bancaires_cin[i][j];
            }
            if (strcmp(tmp, recherche_cin) == 0) {
                printf("Votre identifiant existe\n");
                trouve = 1;
                index_cin_fonction = i;

                break;
            }

        }
        if(trouve == 0){
            printf("Votre cin non trouve\n");
        }
    }while(trouve == 0);
    return index_cin_fonction;
}
void affichage_menu(){
    separer();
    printf("=========================================|affichage|=================================================");
    printf("\n1-Par Ordre Ascendant\n");
    printf("2-Par Ordre Descendant\n");
    printf("3-Par Ordre Ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
    printf("4-Par Ordre Descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
    printf("5-Recherche par CIN\n");
    printf("===================================================================================================");
}
void tri_ascendent(){
    int copie_du_compteur_de_compte = 0;
    copie_du_compteur_de_compte = compteur_de_comptes;

    while (copie_du_compteur_de_compte > 0) {
        char enregistrer_le_nom[30];
        int max = comptes_bancaires_montants[0];
        int max_index = 0;
        char enregistrer_cin[30];
        //stocker la valeur max
        for (int i = 0; i < copie_du_compteur_de_compte; i++) {
            if (comptes_bancaires_montants[i] > max) {
                max = comptes_bancaires_montants[i];
                max_index = i;

            }
            for (int j = 0; j < 30; j++) {
                enregistrer_le_nom[j] = comptes_bancaires_noms[max_index][j];
                enregistrer_cin[j] = comptes_bancaires_cin[max_index][j];
            }

        }
        //reculer les valeurs
        for (int i = max_index; i < copie_du_compteur_de_compte; i++) {
            comptes_bancaires_montants[i] = comptes_bancaires_montants[i + 1];

            for (int j = 0; j < 30; j++) {
                comptes_bancaires_cin[i][j] = comptes_bancaires_cin[i + 1][j];
                comptes_bancaires_noms[i][j] = comptes_bancaires_noms[i + 1][j];
            }
        }
        //poser la valeur max dans la derniere case
        comptes_bancaires_montants[copie_du_compteur_de_compte - 1] = max;

        for (int j = 0; j < 30; j++) {
            comptes_bancaires_cin[copie_du_compteur_de_compte - 1][j] = enregistrer_cin[j];
            comptes_bancaires_noms[copie_du_compteur_de_compte - 1][j] = enregistrer_le_nom[j];
        }
        copie_du_compteur_de_compte--;
        printf("\n");
    }
}
void tri_descendent(){
    int copie_du_compteur_de_compte = compteur_de_comptes;

    while (copie_du_compteur_de_compte > 0) {
        char enregistrer_le_nom[30];
        int min = comptes_bancaires_montants[0];
        int min_index = 0;
        char enregistrer_cin[30];
        //stocker la valeur min
        for (int i = 0; i < copie_du_compteur_de_compte; i++) {
            if (comptes_bancaires_montants[i] < min) {
                min = comptes_bancaires_montants[i];
                min_index = i;
            }
            for (int j = 0; j < 30; j++) {
                enregistrer_le_nom[j] = comptes_bancaires_noms[min_index][j];
                enregistrer_cin[j] = comptes_bancaires_cin[min_index][j];
            }

        }
        //reculer les valeurs
        for (int i = min_index; i < copie_du_compteur_de_compte; i++) {

            comptes_bancaires_montants[i] = comptes_bancaires_montants[i + 1];
            for (int j = 0; j < 30; j++) {
                comptes_bancaires_cin[i][j] = comptes_bancaires_cin[i + 1][j];
                comptes_bancaires_noms[i][j] = comptes_bancaires_noms[i + 1][j];
            }
        }
        //poser la valeur min dans la derniere case
        comptes_bancaires_montants[copie_du_compteur_de_compte - 1] = min;

        for (int j = 0; j < 30; j++) {
            comptes_bancaires_cin[copie_du_compteur_de_compte - 1][j] = enregistrer_cin[j];
            comptes_bancaires_noms[copie_du_compteur_de_compte - 1][j] = enregistrer_le_nom[j];
        }
        copie_du_compteur_de_compte--;
        printf("\n");
    }
}
void affichage_tableau(int debut,int fin){

        printf("=======================================================================\n");
        for(int i=debut;i<fin;i++){
            printf("|\t%10s\t|\t%10s\t|\t%8d\t|\n",comptes_bancaires_noms[i], comptes_bancaires_cin[i], comptes_bancaires_montants[i]);
        }
        printf("=======================================================================");
    }





int main() {

    do {

        menu_principal();
        printf("\n Veuillez choisir votre option : ");
        scanf("%d", &option);

        switch (option) {
            //Introduire un compte bancaire (CIN, Nom et Prénom, Montant)
            case 1:{
                separer();
                printf("=====================|entree de comptes|=======================");
                entree_compte();
                break;
            }
                //Introduire plusieurs comptes bancaires (CIN, Nom et Prénom, Montant)
            case 2:{
                separer();
                printf("=============================|entree de comptes|=============================\n\n");
                printf("Saisissez le nombre de comptes que vous souhaitez : ");
                scanf("%d", &nombre_de_comptes_a_ajouter);
                for (int i = 0; i < nombre_de_comptes_a_ajouter; i++) {
                    entree_compte();
                    printf("\n__________________________________________________________________________________________\n");
                }
                break;}
                //Opérations
            case 3:{
                separer();
                printf("=====================|operations|=======================");
                printf("\n1-Retrait.\n2-Depot.\n");
                printf("Veuillez choisir votre option :");
                scanf("%d", &option);

                switch (option) {
                    //Retrait
                    case 1 :{
                        index_cin = recherche_par_cin();
                        if(trouve == 1){
                            printf("Veuillez saisir le montant que vous souhaitez de retirer :");
                            scanf("%d", &montant_retrait_depot);
                            comptes_bancaires_montants[index_cin] -= montant_retrait_depot;
                            printf("Le nouveau montant est %d\n", comptes_bancaires_montants[index_cin]);
                            trouve = 0;
                        }
                        break;
                    }
                        //Dépôt
                    case 2 : {

                        index_cin = recherche_par_cin();
                        if(trouve == 1){
                            printf("Veuillez saisir le montant que vous souhaitez de ajouter :");
                            scanf("%d", &montant_retrait_depot);
                            comptes_bancaires_montants[index_cin] += montant_retrait_depot;
                            printf("Le nouveau montant est %d\n", comptes_bancaires_montants[index_cin]);
                            trouve = 0;
                        }
                        break;
                    }
                }
                break;
            }
                //Affichage
            case 4:{
                affichage_menu();
                printf("\n Veuillez choisir votre option : ");
                scanf("%d", &option);

                switch (option) {
                    //Par Ordre Ascendant
                    case 1 : {

                        tri_ascendent();
                        affichage_tableau(0,compteur_de_comptes);
                        break;
                    }
                        //Par Ordre Descendant
                    case 2 : {
                        tri_descendent();
                        affichage_tableau(0,compteur_de_comptes);
                        break;
                    }
                        //Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)
                    case 3 : {
                        int recherche_de_montant;
                        int index_recherche_de_montant;
                        tri_ascendent();
                        do{
                            printf("S il vous plait entrez le montant que vous souhaitez rechercher:");
                            scanf("%d", &recherche_de_montant);

                            for (int i = 0; i < compteur_de_comptes; i++) {
                                if (comptes_bancaires_montants[i] == recherche_de_montant) {
                                    index_recherche_de_montant = i;
                                    trouve = 1;
                                    break;
                                }
                            }
                            if(trouve == 0){
                                printf("Le montant saisie n existe pas !!\n");
                            }
                            else{
                                affichage_tableau(index_recherche_de_montant,compteur_de_comptes);
                            }
                        }
                        while(trouve == 0);
                        trouve = 0;

                        break;
                    }
                        //Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)
                    case 4 : {
                        int recherche_de_montant;
                        int index_recherche_de_montant;
                        tri_descendent();
                        do{

                            printf("S il vous plait entrez le montant que vous souhaitez rechercher:");
                            scanf("%d", &recherche_de_montant);


                            for (int i = 0; i < compteur_de_comptes; i++) {
                                if (comptes_bancaires_montants[i] == recherche_de_montant) {
                                    index_recherche_de_montant = i;
                                    trouve = 1;
                                    break;
                                }
                            }
                            if(trouve == 0){
                                printf("Le montant saisie n existe pas !! ");
                            }
                            else
                                affichage_tableau(0,index_recherche_de_montant);
                        }
                        while(trouve == 0);
                        trouve = 0;
                        break;

                    }
                        //Recherche par CIN
                    case 5 : {
                        recherche_par_cin();
                        affichage_tableau(index_cin,index_cin+1);
                        trouve = 0;
                        break;
                    }

                }
                break;
            }
                //Fidélisation
            case 5:{
                separer();
                printf("=====================|fidelisation|=======================");
                tri_descendent();

                for (int i = 0; i < 3 ; i++) {

                    pourcentage_a_ajouter[i] = (comptes_bancaires_montants[i] * 1.3) / 100;
                    comptes_bancaires_montants [i]  += pourcentage_a_ajouter[i];


                }
                affichage_tableau(0,3);

                break;
            }

        }
    }
    while (option != 0);


    return 0;
}
