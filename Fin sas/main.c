#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Les structures
struct Produit {
char code[20],nom[30];
int quantite;
float prix;
};

//Global variable

int i=0;
int oldQ=0;
int exciste=-10;
//Les Fonctions
void ajoutezProduit(struct Produit produit[100],int *q){

oldQ = (*q) + oldQ;

for(i;i<oldQ;i++){
    system("cls");

    printf("Tapez le code de produit %d!!\n",i+1);
    scanf("%s",&produit[i].code);
    printf("Tapez le nom de produit %d!!\n",i+1);
    scanf("%s",&produit[i].nom);
    printf("Tapez le quantite de produit %d!!\n",i+1);
    scanf("%d",&produit[i].quantite);
    printf("Tapez le prix de produit %d!!\n",i+1);
    scanf("%f",&produit[i].prix);

}
i = i + 0;

}

void afficherProduits(struct Produit produit[100],int *q){
int h=0;

for(h=0;h<oldQ;h++){

    printf("**********************************\n");
    printf("le code de produit %d est %s\n",h+1,produit[h].code);

    printf("le nom de produit %d est %s\n",h+1,produit[h].nom);

    printf("le quantite de produit %d est %d\n",h+1,produit[h].quantite);

    printf("le prix de produit %d est %f\n",h+1,produit[h].prix);

}

}

void recherche(struct Produit produit[100],int X){

    int l;

    for(l=0;l<oldQ;l++){
        if(X == produit[l].quantite){
             exciste= l;
        }

    }
return exciste;
}
//fonction d'affichage

int main()
{
struct Produit produit[100];
char choixDeService;
int i,nmbrDeNouveauxProduit;
int *q;
q=&nmbrDeNouveauxProduit;
do{
//Menu de choix
puts("Pour Ajouter un nouveaux produit press A\n");
puts("Pour Afficher les produits press B\n");
puts("Pour rechercher un produit press R\n");
puts("Pour quitter le programme press Q\n");
scanf("%c",&choixDeService);

//Determiner le Choix
switch (choixDeService)
{
case 'A': // Ajouter
   {
    system("cls");

    printf("Taper le nombre des nouvaux produits ajoute\n");
    scanf("%d",&nmbrDeNouveauxProduit);

    ajoutezProduit(produit,q);
   }
   break;

case 'B'://Afficher
    {
    system("cls");
    afficherProduits(produit,q);
    }
    break;

case 'R'://Rechecher
    {
        char choixDeRecherche;
        system("cls");
        printf("Determnier la methode de rechechrche\n");
        printf("Tapez C si la recherche est avec La code\n");
        printf("Tapez Q si la recherche est avec La quantiter\n");
        scanf("%s",&choixDeRecherche);

        if (choixDeRecherche == 'Q'){
          int quantiterRcherche;
          puts("Tapez la quantiter");
          scanf("%d",&quantiterRcherche);
          recherche(produit,quantiterRcherche);

          if(exciste==-10){
            puts("Cette quantiter ne trouve pas");
          }else{
          printf("**********************************\n");
          printf("le code de produit %d est %s\n",exciste+1,produit[exciste].code);

          printf("le nom de produit %d est %s\n",exciste+1,produit[exciste].nom);

          printf("le quantite de produit %d est %d\n",exciste+1,produit[exciste].quantite);

          printf("le prix de produit %d est %f\n",exciste+1,produit[exciste].prix);

          exciste=-10;
          }

        }else{
          //Recherche avec Code
        }
    }
    break;
}





}while(choixDeService != 'Q');


    return 0;
}
