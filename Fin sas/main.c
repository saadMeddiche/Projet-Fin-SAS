#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Les structures
struct Produit {
char code[100];
char nom[30];
int quantite;
float prix;
int date; //Seulement pour la comparaison
int anne;
int jour;
int mois;
};

//Global variable
time_t date;
int i=0;
int oldQ=0;
int exciste=-10; //Return de la fonction rechercheParQuantiter
int excisteCode=-11;//Return de la rechercheParCode
int quantiterAcheter=0;
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

    printf("%s\n",produit[0].code);

}
i = i + 0; // Ymkn n9dr ngl3o

}

void afficherProduits(struct Produit produit[100]){
int h;
for(h=0;h<oldQ;h++){
    printf("**********************************\n");

    printf("le code de produit  %d est    %s\n", h+1,         produit[h].code);

    printf("le nom de produit %d est     %s\n",h+1  ,       produit[h].nom);

    printf("le quantite de produit%d est %d\n",h+1  ,  produit[h].quantite);

    printf("le prix de produit %d est    %f\n",h+1  ,      produit[h].prix + 0.15 * produit[h].prix );

}

}

void rechercheParQuantiter(struct Produit produit[100],int X){

    int l;

    for(l=0;l<oldQ;l++){
        if(X == produit[l].quantite){
             exciste= l;
        }

    }
return exciste;
}

void rechercheParCode(struct Produit produit[100],  int Y){
    int r;
for(r=0;r<oldQ;r++){
    if(strcmp(Y , produit[r].code)==0){
      excisteCode=r;

    }
}
return excisteCode;
}

void supprimer(struct Produit produit[100]){

int S;
S=excisteCode;

for(S;S<oldQ;S++){

strcpy (produit[S].code , produit[S+1].code);
strcpy (produit[S].nom , produit[S+1].nom);
produit[S].quantite = produit[S+1].quantite;
produit[S].prix = produit[S+1].prix;
oldQ--;
i--;
}

}

void ordreParNom(struct Produit produit[100]){
int conteur;
int k;
char swap[100];

do {
  conteur=0;

for(k=0;k<oldQ-1;k++){
    if(strcmp(produit[k].nom,produit[k+1].nom)>0){
        strcpy(swap,produit[k].nom);
        strcpy(produit[k].nom,produit[k+1].nom);
        strcpy(produit[k+1].nom,swap);
        conteur--;
    }else {
    conteur++;
    }
}

}while(conteur>oldQ && k<oldQ-1 );

}

void ordreParPrix(struct Produit produit[100]){
int conteur;
int k;
int swap;

do{
   conteur=0;
   for(k=0;k<oldQ-1;k++){
    if(produit[k].prix - produit[k+1].prix>0){
    conteur++;

    }else{
    swap=produit[k+1].prix;
    produit[k+1].prix=produit[k].prix ;
    produit[k].prix =swap;
    }

   }

}while(conteur>oldQ-1 && k<oldQ-1);
}

void acheter(struct Produit produit[100]){
 //save the current date Lien: https://waytolearnx.com/2019/09/afficher-la-date-et-lheure-courante-en-langage-c.html
int tm = localtime(&date);
time(&date);
struct tm *local = localtime(&date);


produit[excisteCode].quantite = produit[excisteCode].quantite - quantiterAcheter;
/*Example: on 09/11/2022
et in 11/09/2022
regle: (jour-mois)+annee
*/

produit[excisteCode].anne=local->tm_year + 1900;
produit[excisteCode].mois=local->tm_mon + 1;
produit[excisteCode].jour=local->tm_mday;

produit[excisteCode].date=(produit[excisteCode].jour - produit[excisteCode].mois) + produit[excisteCode].anne;

}
int main()
{


struct Produit produit[100];
char choixDeService;
int i,nmbrDeNouveauxProduit;
int *q;
q=&nmbrDeNouveauxProduit;
do{
//Menu de choix
puts("-----------------------------------------");
puts("-Pour Ajouter un  produit press ---- [A]-");
puts("-                                       -");
puts("-Pour Afficher les produits press -- [B]-");
puts("-                                       -");
puts("-Pour Acheter un produit press ----- [C]-");
puts("-                                       -");
puts("-Pour rechercher un produit press -- [R]-");
puts("-                                       -");
puts("-Pour Supprimer un produit press --- [S]-");
puts("-                                       -");
puts("-Pour lister les produits press ---- [L]-");
puts("-                                       -");
puts("-Pour quitter le programme press --- [Q]-");
puts("-----------------------------------------");

scanf("%s",&choixDeService);

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
    printf("%s\n",produit[0].code);
    afficherProduits(produit);
    }
    break;

case 'R'://Rechecher
    {
        system("cls");
        //Choisir la methode de recherche
        char choixDeRecherche;
        system("cls");
        printf("Determnier la methode de rechechrche\n");
        printf("Tapez C si la recherche est avec La code\n");
        printf("Tapez Q si la recherche est avec La quantiter\n");
        scanf("%s",&choixDeRecherche);
        system("cls");

        //Recherche aven quantiter
        if (choixDeRecherche == 'Q'){
          int quantiterRcherche;
          puts("Tapez la quantiter");
          scanf("%d",&quantiterRcherche);
          rechercheParQuantiter(produit,quantiterRcherche);

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

        }else{//Recherche avec Code
           char codeRcherche[30];
          puts("Tapez le code");
          scanf("%s",&codeRcherche);
          rechercheParCode(produit,codeRcherche);
          if(exciste==-11){
            puts("Ce code ne trouve pas");
          }else{
          printf("**********************************\n");
          printf("le code de produit %d est %s\n",excisteCode+1,produit[excisteCode].code);

          printf("le nom de produit %d est %s\n",excisteCode+1,produit[excisteCode].nom);

          printf("le quantite de produit %d est %d\n",excisteCode+1,produit[excisteCode].quantite);

          printf("le prix de produit %d est %f\n",excisteCode+1,produit[excisteCode].prix);

          excisteCode=-11;
          }
        }

    }
    break;

case 'S'://Supprimer
    {
        //choisire la methode de suprimation
    system("cls");
    char codeASupprimer[30];
    puts("Tapez le code du produit que vous voulez le supprimer");
    scanf("%s",&codeASupprimer);
    rechercheParCode(produit,codeASupprimer);
    if(exciste==-11){
            puts("Ce code ne trouve pas");
          }else{
          char ouiOuNon;
          printf("**********************************\n");

          printf("le code de produit %d est %s\n",excisteCode+1,produit[excisteCode].code);

          printf("le nom de produit %d est %s\n",excisteCode+1,produit[excisteCode].nom);

          printf("le quantite de produit %d est %d\n",excisteCode+1,produit[excisteCode].quantite);

          printf("le prix de produit %d est %f\n",excisteCode+1,produit[excisteCode].prix);

          puts("Est ce que ca le produit que vous voulez le supprimer ?");

          puts("Tapez [o] si oui ou bien [n] pour non");
          scanf("%s",&ouiOuNon);
          switch (ouiOuNon){

          case 'o':{
          supprimer(produit);

          }break;

          case 'n':{


          }break;



          }
          excisteCode=-11;
          }




    }
    break;

case 'L'://Lister
    {
        char choixDeListe;

     puts("------------------------Choisir la methode de l'orde---------------------------------");
     puts("Pour lister tous les produits selon l’ordre alphabetique  croissant du nom, press [N]");
     puts("Pour lister tous les produits selon l’ordre  décroissant du prix, press --------- [P]");
     puts("-------------------------------------------------------------------------------------");

     scanf("%s",&choixDeListe);
      printf("test 0\n");
     switch (choixDeListe){
      printf("test 1\n");
          case 'N':{// ordre avec nom
           printf("test 2\n");
                 ordreParNom(produit);
                 afficherProduits(produit);
          }break;

          case 'P':{//ordre avec prix

                 ordreParPrix(produit);
                 afficherProduits(produit);


          }break;


     }






    }break;

case 'C': //acheter
    {
     char codeProduit[100];
     puts("Tapez le code du produit");
     scanf("%s",&codeProduit);
     puts("Donner la quantiter a ete acheter");
     scanf("%d",&quantiterAcheter);

     rechercheParCode(produit,codeProduit);

     acheter(produit);
     printf("%d\n",produit[excisteCode].date);
     printf("%d %d %d \n",produit[excisteCode].jour, produit[excisteCode].mois), produit[excisteCode].anne;
     quantiterAcheter=0;
     excisteCode=-11;
    }break;
}//fin de switch





}while(choixDeService != 'Q');


    return 0;
}
