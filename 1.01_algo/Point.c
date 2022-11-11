/**
 *\file Point.c
 *\brief ce fichier contient les fonctions permettant d'acheter des boissons et de participer à un concert
 *\author Tony FAGES
 *\date 15 octobre 2022
 */

#include "SAE.h"

/**
 *\brief cherche la position d'un adherent dans le tableau tabAdherent
 *\param tabAdherent[] tableau trié des numéros de carte
 *\param tabEtat[] tableau des état des cartes
 *\param tabAge[] tableau de l'age de chaque adhérent
 *\param tlog taille logique des tableaux
 *\param adherent le numéro de l'adhérent cherché
 *\param *age renvoie par pointeur l'age de l'adhérent cherché
 *\return la position de l'adherent dans le tableau ou -1 en cas d'erreur
 *\author Tony FAGES
 */
int Info_Adhérent(int tabAdherent[],int tabEtat[], int tabAge[], int tlog,int adherent,int *age)
{
    int pos, code_retour;
    frecherche(tabAdherent, tlog, adherent, &pos, &code_retour);
    if (code_retour == 0) 
    {
        printf("Adhérent non enregistré achat impossible\n");
        return -1;
    }
    else 
        if (tabEtat[pos] == 0)
        {
            printf("Achat impossible carte bloquée\n");
            return -1;
        }
    *age = tabAge[pos];
    return pos;
}

/**
 *\brief débite la carte d'un adhérent en fonction de l'achat de boissons
 *\param tabAdherent[] tableau trié des numéros de carte
 *\param tabEtat[] tableau des état des cartes
 *\param tabAge[] tableau de l'age de chaque adhérent
 *\param tlog taille logique des tableaux
 *\param adherent le numéro de l'adhérent débité
 *\param *nb_soft renvoie par pointeur le nombre de boissons soft achetée au total dans une journée
 *\param *nb_alcool renvoie par pointeur le nombre de boissons alcoolisées achetée au total dans une journée
 *\author Tony FAGES
 */
void AchatBoissons(int tabAdherent[], int tabEtat[], int tabAge[],int tabCarte[], int tlog, int adherent,int *nb_soft,int *nb_alcool )
{
    int limite = 0, code_ret, age, choix, prix_alcool = 13, prix_soft = 6, nombre, prix_tot;
    code_ret = Info_Adhérent(tabAdherent, tabEtat, tabAge, tlog,adherent, &age);
    if (code_ret == -1) return;
    printf("Position == %d",code_ret);
    printf("Voulez-vous une boisson soft(6 points) ou alcoolisée(13 point) (0: soft, 1: alcoolisée, 9:annuler)\n");
    scanf("%d",&choix);
    while(choix != 9)
    {
        printf("Entrer le nombre de boisson :");
        scanf("%d",&nombre);
        
        if (choix == 1 && age >= 18 && tabCarte[code_ret] >= 13)
        {
            prix_tot = prix_alcool * nombre;
            printf("Achat accepté retrait de %d points sur votre carte \n", prix_tot);
            tabCarte[code_ret] = tabCarte[code_ret] - prix_alcool;
            *nb_alcool = *nb_alcool + nombre;
        }
        else
        {
          if (choix == 1 && age < 18)
          {
              printf("Vous n'avez pas l'age legal pour commander de l'alcool, achat impossible\n");
              break;
          }
          if(choix == 1 && tabCarte[code_ret] < 13)
          {
              printf("Vous n'avez pas assez de point sur votre carte veuillez la recharger \n");
              break;
          }
          if(choix == 1 && limite > 5)
          {
              printf("Vous ne pouvez acheter que 5 boissons alcoolisée par jour. Achat Impossible \n");
              break;
          }
        }
        if (choix == 0 && tabCarte[code_ret] >= 6)
        {
            prix_tot = prix_soft * nombre;
            printf("Achat accepté retrait de %d points sur votre carte \n", prix_tot);
            tabCarte[code_ret] = tabCarte[code_ret] - prix_soft;
            *nb_soft = *nb_soft +nombre;
        }
        else 
          if(choix == 0 && tabCarte[code_ret] < 6)
          {
              printf("Vous n'avez pas assez de point sur votre carte veuillez la recharger \n");
          } 
        printf("Voulez-vous une boisson soft(6 points) ou alcoolisée(13 point) (0: soft, 1: alcoolisée, 9:annuler)\n");
        scanf("%d",&choix);
    }
}

/**
 *\brief débite la carte d'un adhérent en fonction de l'achat de place de concert
 *\param tabAdherent[] tableau trié des numéros de carte
 *\param tabEtat[] tableau des état des cartes
 *\param tabAge[] tableau de l'age de chaque adhérent
 *\param tlog taille logique des tableaux
 *\param adherent le numéro de l'adhérent débité
 *\param *activité_concert renvoie par pointeur le nombre total de place acheté dans une journée 
 *\author Tony FAGES
 */
void Concert(int tabAdherent[], int tabEtat[], int tabAge[],int tabCarte[], int tlog, int adherent, int *activité_concert)
{
    int code_ret, age, choix, prix_entree = 66, prix_reduc = 40, prix_tot, nbplace ;
    code_ret = Info_Adhérent(tabAdherent, tabEtat, tabAge, tlog,adherent, &age);
    if (code_ret == -1) return; 
    printf("Voulez-vous participer au concert des Eagles pour la somme de %d points (sauf si vous pouvez bénéficiez des reducs) :  (1=oui/0=non)i\n",prix_entree);
    scanf("%d",&choix);
    printf("Entrer le nombre de place que vous voulez : \n");
    scanf("%d",&nbplace);
    if (nbplace <= 0)
    {
        printf("Le nombre de place doit-être positif \n");
        return;
    }
    while(choix != 0)
    {
        if (tabEtat[code_ret] == 3) 
        {
            printf("Limite de concert atteinte pour la journée reservation impossible ");
            break;
        }
        if(tabEtat[code_ret] == 2) tabEtat[code_ret] = 3;
        printf("%d",tabEtat[code_ret]);
        printf("Êtes-vous éligibles aux tarifs reduits : (1=oui/0=non)\n");
        scanf("%d",&choix);

        if (choix == 1 ) prix_tot = prix_reduc * nbplace;
        if (choix == 0) prix_tot = prix_entree * nbplace;
        
        if (choix == 1 && tabCarte[code_ret] < prix_tot) 
        {
            printf("Nombre de points insuffisant \n");
            break;
        }
        if (choix == 1 && tabCarte[code_ret] >= prix_tot) 
        {
            printf("Achat accepté retrait de %d points sur votre carte \n", prix_tot);
            tabCarte[code_ret] = tabCarte[code_ret] - prix_tot;
        }
        
        if (choix == 0 && tabCarte[code_ret] < prix_tot) 
        {
            printf("Nombre de points insuffisant \n");
            break;
        }
        
        if (choix == 0 && tabCarte[code_ret] >= prix_tot)
        {
            printf("Achat accepté retrait de %d points sur votre carte \n",prix_tot);
            tabCarte[code_ret] = tabCarte[code_ret] - prix_tot; 
        }

        *activité_concert = *activité_concert + nbplace;

    printf("Voulez-vous participer a d'autre concert pour la somme de %d points (sauf si vous pouvez bénéficiez des reducs) :  (1=oui/0=non)i\n",prix_entree);
    scanf("%d",&choix);
    printf("Entrer le nombre de place que vous voulez : \n");
    scanf("%d",&nbplace);
        
    }
}
