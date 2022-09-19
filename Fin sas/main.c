#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Les structures
struct Produit {
char code[20],nom[30];
int quantite;
float prix;
};



//Les Fonctions
void ajoutezProduit(struct Produit produit[100],int *q){
int i;
for(i=0;i<(*q);i++){
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


}

void afficherProduits(struct Produit produit[100],int *q){
int i;

for(i=0;i<(*q);i++){

    printf("**********************************\n");
    printf("le code de produit %d est %s\n",i+1,produit[i].code);

    printf("le nom de produit %d est %s\n",i+1,produit[i].nom);

    printf("le quantite de produit %d est %d\n",i+1,produit[i].quantite);

    printf("le prix de produit %d est %f\n",i+1,produit[i].prix);

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
