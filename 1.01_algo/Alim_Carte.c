#include <stdio.h>
#include <stdlib.h>
#include "SAE.h"



void frecherche(int tabAdherent[], int tlog, int val, int *pos, int *code_retour)
{
    int i;
    for (i=0; i<tlog; i++)
    {
        if (tabAdherent[i] == val)
        {
            *pos = i;
            *code_retour = 1;
            return;
        }

        if ( val < tabAdherent[i])
        {
            printf("Bonjour");
            *pos = i-1;
            *code_retour = 0;
            return;
        }
    }
    *pos = tlog;
    *code_retour=0;
    return;
}

void prix_Point(int nbPoint, int *prix)
{
    int point = 2;
    *prix = nbPoint * point;
}

void Alim_Carte(int tabAdherent[], int tabCarte[], int tabEtat[], int tlog)
{
    int pos, code_retour, nbPoint, nbCarte, prix;
    printf("Entrer le numéro de la carte : \n");
    scanf("%d",&nbCarte);
    frecherche(tabAdherent,tlog,nbCarte,&pos,&code_retour);
    if (tabEtat[pos] == 0 )
    {
        printf("Cette carte est désactiver, impossible de l'alimenter\n");
        return;
    }
    if (code_retour == 1 )
    {
        printf("Entrer le nombre de point a rajouter (1 point = 2€ et 1 point offert tout les 5 points achetési)\n");
        scanf("%d", &nbPoint);
        printf("%d\n", nbPoint);
        prix_Point(nbPoint, &prix);
        nbPoint = nbPoint + (nbPoint/5);
        tabCarte[pos] = tabCarte[pos] + nbPoint;
        printf("Cela vous fera un total de %d€\n", prix);
        printf("Vous avez un crediter votre compte de %d points cela vous fait un total de %d point\n",nbPoint, tabCarte[pos]);
    }
    if (code_retour == 0)
      printf("Carte inexistante \n");
}


void Change_Etat(int tabAdherent[], int tabEtat[], int tlog)
{
    int pos, code_retour, nbAdherent, choix;
    printf("Entrer le numero de l'adherent concerné\n");
    scanf("%d",&nbAdherent);
    frecherche(tabAdherent, tlog, nbAdherent, &pos, &code_retour);
    if(code_retour == 0)
    {
        printf("Adhérent inexistant\n");
        return;
    }
    if(code_retour == 1)
    {
        printf("Voulez vous lui changer l'etat de sa carte ou bien appliquer/enlever une saction (bloquer:0/sanction:1)");
        scanf("%d",&choix);
        if(choix == 0 && tabEtat[pos] == 0)
            tabEtat[pos] = 1;
        else if(choix == 0 && tabEtat[pos] == 1)
                 tabEtat[pos] = 0;
        if(choix == 1 && (tabEtat[pos] == 2 || tabEtat[pos] == 3))
        {
            printf("Retrait de la sanction : limitation des concerts à 1 par jours\n");
            tabEtat[pos] = 1;
            return;    
        }
        
        if(choix == 1 && (tabEtat[pos] == 0 || tabEtat[pos] == 1 ))
        {
            printf("Sanction : limitation des concerts à 1 par jours\n");
            tabEtat[pos] = 2;
            
        }
    }
}

void Activite(int activité_concert,int nb_soft,int nb_alcool)
{
            printf("Affluences concerts : %d\t\t", activité_concert);
            printf("Nombres de boissons alcoolisés : %d\t\t", nb_alcool);
            printf("Nombres de boissons sans alcool : %d\n", nb_soft); 
}
