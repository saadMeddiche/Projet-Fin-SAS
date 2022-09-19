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
int oldi=0;
int i=0;
int oldQ=0;
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

case 'B':
    {
    system("cls");

    afficherProduits(produit,q);
    }

break;
}





}while(choixDeService != 'Q');


    return 0;
}
