#include <stdio.h> //Appeler plusieur fonction (EX: printf()et scanf() et puts())
#include <stdlib.h> //Appeler plusieur fonction (EX: system()et exit() )
#include <string.h> //Appeler plusieur fonction (EX: strcpy()et strcmp() )
#include <time.h> //https://koor.fr/C/ctime/ctime.wp

//Les structures
struct Produit {
//info du produit
char code[1000];
char nom[30];
int quantite;
float prix;
//info du date
int date; //Seulement pour la comparaison
int anne;
int jour;
int mois;
//info du statique
float tableau;
};

//Global variable
int i=0; //Pour stocker le nombre du derniere case a la fonction ajoutez
int oldQ=0; // determiner le nombre de case utiliser
int exciste=-10; //Return de la fonction rechercheParQuantiter
int excisteCode=-11; //Return de la rechercheParCode
int quantiterAcheter=0;
int quantiterAjouter=0;
int nmbrDeNouveauxProduit;

//variables du statique
float prixTotal=0;
float prixMoyenne=0;
int sommeQuantiterAcheter=0;
int O=0; //Pour stocker prix * quantiter d'un chaque produit (case acheter)
float Max;
float Min;

//Les Fonctions
void ajoutezProduit(struct Produit produit[100],int L){

oldQ = L + oldQ;

for(i;i<oldQ;i++){
    system("cls");
    begin:
    printf("___________________________________\n");
    printf("Tapez le code de produit %d : ",i+1);
    scanf("%s",&produit[i].code);

    for(int l=0;l<i;l++){ //cheque if il ya deja un code
       if (strcmp(produit[i].code,produit[l].code)==0) {
        system("cls");
        printf("-------------------\n");
        printf("Il y a deja se code\n");
        printf("-------------------\n");
        system("pause");
        system("cls");
        goto begin;
       }
    }

    printf("___________________________________\n");
    printf("Tapez le nom de produit %d : ",i+1);
    scanf("%s",&produit[i].nom);
    printf("___________________________________\n");
    printf("Tapez le quantite de produit %d : ",i+1);
    scanf("%d",&produit[i].quantite);
    printf("___________________________________\n");
    printf("Tapez le prix de produit %d : ",i+1);
    scanf("%f",&produit[i].prix);
    printf("___________________________________\n");
    //printf("%s\n",produit[0].code);

}
//i = i + 0; // Ymkn n9dr ngl3o

}

void afficherProduits(struct Produit produit[100]){
int h;
for(int h=0;h<oldQ;h++){
    printf("\n-------Produit %d-------\n",h+1);

    printf("Code : %s\n",     produit[h].code);

    printf("Nom : %s\n",      produit[h].nom);

    printf("Quantite : %d\n", produit[h].quantite);

    printf("Prix : %f\n" ,    produit[h].prix + 0.15 * produit[h].prix );
    printf("--------------------------\n\n\n");
}
system("pause");
system("cls");
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

//Pour ordreParNom https://www.youtube.com/watch?v=Rd5V0Yemv4E (Probleme de condition) min:6:32
void ordreParNom(struct Produit produit[100]){
int conteur;
int k;
char swap[100];
int swap2;

do {
  conteur=0;

for(k=0;k<oldQ-1;k++){
    if(strcmp(produit[k].nom,produit[k+1].nom)>0){
        strcpy(swap,produit[k].nom);
        strcpy(produit[k].nom,produit[k+1].nom);
        strcpy(produit[k+1].nom,swap);

        strcpy(swap,produit[k].code);
        strcpy(produit[k].code,produit[k+1].code);
        strcpy(produit[k+1].code,swap);

        swap2 = produit[k].prix;
        produit[k].prix = produit[k+1].prix;
        produit[k+1].prix = swap2;

        swap2 = produit[k].quantite;
        produit[k].quantite = produit[k+1].quantite;
        produit[k+1].quantite = swap2;
        conteur=1;
    }
}

}while(conteur==1 && k<oldQ-1 );

}

void ordreParPrix(struct Produit produit[100]){
int conteur;
int k;
int swap;
int swap2[100];
do{
   conteur=0;
   for(k=0;k<oldQ-1;k++){
    if(produit[k].prix - produit[k+1].prix>0){


    }else{
        strcpy(swap2,produit[k].nom);
        strcpy(produit[k].nom,produit[k+1].nom);
        strcpy(produit[k+1].nom,swap2);

        strcpy(swap2,produit[k].code);
        strcpy(produit[k].code,produit[k+1].code);
        strcpy(produit[k+1].code,swap2);

        swap = produit[k].prix;
        produit[k].prix = produit[k+1].prix;
        produit[k+1].prix = swap;

        swap = produit[k].quantite;
        produit[k].quantite = produit[k+1].quantite;
        produit[k+1].quantite = swap;
        conteur=1;
    }

   }

}while(conteur==1 && k<oldQ-1);

}

void acheter(struct Produit produit[100]){
 //save the current date Lien: https://waytolearnx.com/2019/09/afficher-la-date-et-lheure-courante-en-langage-c.html
time_t date;

time(&date);

struct tm *local = localtime(&date);

//mettre a jour la quantiter du produit
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

void alimenterStock(struct Produit produit[100]){
//mettre a jour la quantiter du produit
produit[excisteCode].quantite = produit[excisteCode].quantite + quantiterAjouter;
}

void etatDuStocke(struct Produit produit[100]){

int v;
for(v=0;v<oldQ;v++){
    if(produit[v].quantite<3){
       printf("---------Produit%d---------\n",v+1);
       printf("Code: %s\n",produit[v].code);
       printf("Nom: %s\n",produit[v].nom);
       printf("Quantite: %d\n",produit[v].quantite);
       printf("Prix: %f\n",produit[v].prix + 0.15 *produit[v].prix);
       printf("--------------------------\n\n\n");
    }
}

}

void ordreParPrixPourLesStatiques(struct Produit produit[100]){
int conteur;
int k;
int swap;

do{
   conteur=0;
   for(k=0;k<oldQ-1;k++){
    if(produit[k].tableau - produit[k+1].tableau>0){
    conteur++;

    }else{
    swap=produit[k+1].tableau;
    produit[k+1].tableau = produit[k].tableau ;
    produit[k].tableau = swap;
    }

}
}while(conteur>oldQ-1 && k<oldQ-1);
Max=produit[0].tableau;
Min=produit[k-1].tableau;
}
int main()
{
printf("         ******************\n");
printf("         * Bonjouuuuur :D *\n");
printf("         ******************\n");


struct Produit produit[100];
int access=0; // access au austre choise si il ya deja un produit
char choixDeService;
//int nmbrDeNouveauxProduit;
//int *q;
//q=&nmbrDeNouveauxProduit;
do{
//Menu de choix

puts("-----------------------------------------");
puts("-Pour Ajouter un  produit press ---- [A]-");
puts("-                                       -");
puts("-Pour Afficher les produits press -- [B]-");
puts("-                                       -");
puts("-Pour Acheter un produit press ----- [C]-");
puts("-                                       -");
puts("-Pour Alimenter le stock press ----- [M]-");
puts("-                                       -");
puts("-Pour rechercher un produit press -- [R]-");
puts("-                                       -");
puts("-Pour Etat du stock  press --------- [E]-");
puts("-                                       -");
puts("-Pour Supprimer un produit press --- [S]-");
puts("-                                       -");
puts("-Pour les Statistique press -------- [U]-");
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
    beg:

    access=1;
    system("cls");
    printf("\n-------------------------------------------\n");
    printf("Taper le nombre des nouvaux produits ajoute \n");
    printf("-------------------------------------------\n");
    scanf("%d",&nmbrDeNouveauxProduit);
   if (nmbrDeNouveauxProduit>100 || nmbrDeNouveauxProduit <0){ //tka3rir
    system("cls");
    printf("--------------------------------\n");
    printf("please un nombre entrer 0 et 100\n");
    printf("--------------------------------\n");
    system("pause");
    goto beg;
   }

    ajoutezProduit(produit,nmbrDeNouveauxProduit);

    system("pause");
    system("cls");
   }

   break;

case 'B'://Afficher
    {
    system("cls");
    if(access==0){
        printf("---------------------------------\n");
        printf("- Aucun produit pour l'afficher -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
    //printf("%s\n",produit[0].code);

    afficherProduits(produit);
    }
    break;

case 'R'://Rechecher
    {
        system("cls");
        if(access==0){
        printf("---------------------------------\n");
        printf("- Aucun produit pour rechercher -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
        //Choisir la methode de recherche
        char choixDeRecherche;
        system("cls");
        printf("------------------------------------\n");
        printf("Determnier la methode de rechechrche\n");
        printf("------------------------------------\n");
        printf("Tapez [C] si la recherche est avec La code\n");
        printf("Tapez [Q] si la recherche est avec La quantiter\n");
        scanf("%s",&choixDeRecherche);
        system("cls");

        //Recherche aven quantiter
        if (choixDeRecherche == 'Q'){
          int quantiterRcherche;
          printf("------------------\n");
          printf("Tapez la quantiter\n");
          printf("------------------\n");
          scanf("%d",&quantiterRcherche);
          rechercheParQuantiter(produit,quantiterRcherche);

          if(exciste==-10){
            puts("-----------------------------");
            puts("Cette quantiter ne trouve pas");
            puts("-----------------------------");
          system("pause");
          system("cls");
          }else{
          printf("----------Produit%d--------\n",exciste+1);
          printf("le code : %s\n",produit[exciste].code);

          printf("le nom : %s\n",produit[exciste].nom);

          printf("le quantite : %d\n",produit[exciste].quantite);

          printf("le prix : %f\n",produit[exciste].prix);
          printf("---------------------------\n");
          system("pause");
          system("cls");
          exciste=-10;
          }

        }else{//Recherche avec Code
           char codeRcherche[30];
          printf("-------------\n");
          printf("Tapez le code\n");
          printf("-------------\n");
          scanf("%s",&codeRcherche);
          rechercheParCode(produit,codeRcherche);
          if(excisteCode==-11){
            puts("---------------------");
            puts("Ce code ne trouve pas");
            puts("---------------------");
          system("pause");
          system("cls");
          }else{
          printf("----------Produit%d--------\n",excisteCode+1);
          printf("le code : %s\n",produit[excisteCode].code);

          printf("le nom : %s\n",produit[excisteCode].nom);

          printf("le quantite : %d\n",produit[excisteCode].quantite);

          printf("le prix : %f\n",produit[excisteCode].prix);
          printf("---------------------------\n");
          system("pause");
          system("cls");

          excisteCode=-11;
          }
        }

    }
    break;

case 'S'://Supprimer
    {
        system("cls");
        if(access==0){
        printf("---------------------------------\n");
        printf("- Aucun produit pour  supprimer -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }

    system("cls");
    char codeASupprimer[30];
    puts("(----------------------------------------------------");
    puts("Tapez le code du produit que vous voulez le supprimer");
    puts("(----------------------------------------------------");
    scanf("%s",&codeASupprimer);
    rechercheParCode(produit,codeASupprimer);
    if(exciste==-11){
            puts("---------------------");
            puts("Ce code ne trouve pas");
            puts("---------------------");
          }else{
          char ouiOuNon;
          printf("----------Produit%d--------\n",excisteCode+1);
          printf("le code : %s\n",produit[excisteCode].code);

          printf("le nom : %s\n",produit[excisteCode].nom);

          printf("le quantite : %d\n",produit[excisteCode].quantite);

          printf("le prix : %f\n",produit[excisteCode].prix);
          printf("---------------------------\n");

          puts("Est ce que ca le produit que vous voulez le supprimer ?");

          puts("Tapez [o] si oui ou bien [n] si non");
          scanf("%s",&ouiOuNon);
          system("cls");
          switch (ouiOuNon){

          case 'o':{
          supprimer(produit);
          puts("-----------------------");
          puts("Le produit est suprimer");
          puts("-----------------------");
          system("pause");
          system("cls");
          }break;

          case 'n':{


          }break;



          }
          if(excisteCode==0){access=0;}


          excisteCode=-11;
          }




    }
    break;

case 'L'://Lister
    {
        system("cls");
        if(access==0){
        printf("---------------------------------\n");
        printf("-   Aucun produit pour lister   -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
        char choixDeListe;

     puts("------------------------Choisir la methode de l'orde---------------------------------");
     puts("Pour lister tous les produits selon l’ordre alphabetique  croissant du nom, press [N]");
     puts("Pour lister tous les produits selon l’ordre  decroissant du prix, press --------- [P]");
     puts("-------------------------------------------------------------------------------------");

     scanf("%s",&choixDeListe);
     system("cls");
      //printf("test 0\n");
     switch (choixDeListe){
      //printf("test 1\n");
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
     system("clS");
     if(access==0){
        printf("---------------------------------\n");
        printf("-  Aucun produit pour l'achter  -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
     char codeProduit[100];

     puts("------------------------\n");
     puts("Tapez le code du produit\n");
     puts("------------------------\n");

     scanf("%s",&codeProduit);
     puts("---------------------------------\n");
     puts("Donner la quantiter a ete acheter\n");
     puts("---------------------------------\n");

     scanf("%d",&quantiterAcheter);

     system("pause");
     system("cls");

     rechercheParCode(produit,codeProduit);

     prixTotal= prixTotal + ((produit[excisteCode].prix+0.15*produit[excisteCode].prix) * quantiterAcheter);

     sommeQuantiterAcheter = sommeQuantiterAcheter + quantiterAcheter;

     prixMoyenne =  prixTotal / sommeQuantiterAcheter;
     //Pour stocker prix * quantiter d'un chaque produit
     produit[O].tableau = (produit[O].prix + 0.15 * produit[O].prix )*quantiterAcheter ;

     acheter(produit);

     quantiterAcheter=0;
     O++;
     excisteCode=-11;
    }break;

case 'M'://Alimentez
    {
        system("cls");
        if(access==0){
        printf("---------------------------------\n");
        printf("- Aucun produit pour allimenter -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
     char codeProduit[100];

     puts("------------------------\n");
     puts("Tapez le code du produit\n");
     puts("------------------------\n");
     scanf("%s",&codeProduit);

     puts("---------------------------------\n");
     puts("Donner la quantiter a ete ajouter\n");
     puts("---------------------------------\n");
     scanf("%d",&quantiterAjouter);

     system("pause");
     system("cls");

     rechercheParCode(produit,codeProduit);

     alimenterStock(produit);

     quantiterAcheter=0;
     excisteCode=-11;

    }break;

case 'E':// etat du stock
    {
        system("cls");
        if(access==0){
        printf("----------------------------------------\n");
        printf("- Aucun produit pour afficher son etat -\n");
        printf("----------------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
        etatDuStocke(produit);
        system("pause");
        system("cls");
    }break;

case 'U'://statistique
    {
        system("cls");
        if(access==0){
        printf("---------------------------------\n");
        printf("- Au debut, ajouter des produit -\n");
        printf("---------------------------------\n");
        system("pause");
        system("cls");
        break;
    }
    printf("Le prix total est:%f\n",prixTotal);
    printf("Le prix moyenne est:%f\n",prixMoyenne);
    ordreParPrixPourLesStatiques(produit);
    printf("Max est :%f", Max);
    printf("Min est :%f",Min);

    }break;
case 'Q': //quiter le programme
    {
        for(int y=0;y<5;y++){
      system("cls");
      sleep(1);
      printf("         ******************\n");
      printf("         * Bye Byeeeee :D *\n");
      printf("         ******************\n");
      sleep(1);

        }
        exit(0);
    }break;
default:
system("cls");
puts("--------------------------------");
puts("|                              |");
puts("| Please entrer l'exacte choix |");
puts("|                              |");
puts("--------------------------------");

sleep(2);

}//fin de switch

}while(choixDeService != '+');

    return 0;
}
