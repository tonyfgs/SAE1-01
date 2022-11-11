/**
 *\file Alim_Carte.c
 *\brief contient toutes les fonctions permettant de changer l'état et d'alimenter en points les cartes
 *\author Tony FAGES
 *\date 15 octobre 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "SAE.h"

/**
 *\brief recherche une valeur dans un tableau trié
 *\param tabAdherent[] tableau trié des numéros de carte
 *\param tlog taille logique du tableau
 *\param val valeur cherchée
 *\param *pos retourne par pointeur la position de la valeur dans le tableau
 *\param *code_retour retourne par pointeur si la valeur est dans le tableau (1) ou non (0)
 *\author Tony FAGES
 */
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
            *pos = i-1;
            *code_retour = 0;
            return;
        }
    }
    *pos = tlog;
    *code_retour=0;
    return;
}

/**
 *\brief calcul et renvoie le prix en fonction du nombre de points
 *\param nbPoint nombre de points
 *\param *prix retourne par pointeur le prix d'achat des points
 *\author Tony FAGES
 */
void prix_Point(int nbPoint, int *prix)
{
    int point = 2;
    *prix = nbPoint * point;
}

/**
 *\brief alimente une carte en point si son état lui permet
 *\param tabAdherent[] tableau trié des numéros de carte
 *\param tabCarte[] tableau des points de chaque carte
 *\param tabEtat[] tableau de l'état des cartes
 *\param tlog taille logique des tableaux
 *\author Tony FAGES
 */
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

/**
 *\brief change l'état d'une carte
 *\param tabAdherent[] tableau trié des numéros de carte
 *\param tabEtat[] tableau de l'état des cartes
 *\param tlog taille logique des tableaux
 *  une carte peut avoir 3 états, 1 indique une carte qui fonctionne normalement
 *                                0 indique une carte qui est bloqué, c'est à dire qu'elle est inutilisable
 *                                2 indique une carte qui est sanctionné, c'est à dire que l'adhérent ne pourra assister qu'à un seul concert par jour
 *\author Tony FAGES
 */
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

/**
 *\brief cette fonction affiche le nombre d'entée au concert ainsi que le nombre de boissons avec et sans alcool vendu dans la journée
 *\param activité_concert nombre d'entrée au concert dans une journée
 *\param nb_soft nombre de boissons soft vendues dans une journée
 *\param nb_alcool nombre de boissons alcoolisées vendues dans une journée
 *\author Tony FAGES
 */
void Activite(int activité_concert,int nb_soft,int nb_alcool)
{
            printf("Affluences concerts : %d\t\t", activité_concert);
            printf("Nombres de boissons alcoolisés : %d\t\t", nb_alcool);
            printf("Nombres de boissons sans alcool : %d\n", nb_soft); 
}
