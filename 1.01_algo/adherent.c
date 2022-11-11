/**
 *\file adherent.c
 *\brief Ce fichier contient tout le code permettant de gerer l'affichage, de creer ou de supprimer des adhérents ainsi que le menu principal de l'application.
 *\author Khéna BRUNEAU
 *\date 13 octobre 2022
 */

#include"SAE.h"

/**
 *\brief recherche dans un tableau trié une valeur
 *\param tabInt[] tableau d'entiers triés
 *\param val valeur cherchée dans le tableau
 *\param tlog taille logique du tableau
 *\param *trouve indique si la valeur cherchée est dans le tableau ou non
 *\return la position de la valeur dans le tableau ou sa position d'insertion si il n'est pas dans le tableau
 *\author Khéna BRUNEAU
 */
int rechercher(int tabInt[], int val, int tlog, int *trouve)
{
    int i;
    for (i=0; i<tlog; i++)
    {
        if (val==tabInt[i])
        {    *trouve=0;
            return i;}

        if (val<tabInt[i])
        {    *trouve=1;
            return i;}
    }
    *trouve=1;
    return tlog;
}

/**
 *\brief crée un adhérent et enregistre ses informations dans les tableaux
 *\param tabCarte[] tableau trié des numéros de carte des adhérents
 *\param tabPoint[] tableau des points de chaque cartes
 *\param tabAge[] tableau de l'age des adhérents
 *\param tabEtat[] tableau des états des cartes
 *\param tlog taille logique des tableaux
 *\param max taille maximal des tableaux
 *\return la taille logique après ajout
 *\author Khéna BRUNEAU
 */
int creerAdherent(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog, int max)
{
    int numCarte, point, age, trouve, i, j;

    printf("\nSaisir le numéro de carte de l'adhérent (Saisir 0 pour arreter) : ");
    scanf("%d", &numCarte);
    if (numCarte == 0) return tlog;
    i=rechercher(tabCarte, numCarte, tlog, &trouve);
    if (trouve==0)
    {
        printf("\nNuméro d'adhérent déjà existant\n");
        return -1;
    }
    printf("Nombre de point créditer sur la carte : ");
    scanf("%d", &point);
    printf("Saisir l'âge de l'adhérent : ");
    scanf("%d", &age);
    for (j=tlog; j>i; j--)
    {
        tabCarte[j]=tabCarte[j-1];
        tabPoint[j]=tabPoint[j-1];
        tabAge[j]=tabAge[j-1];
        tabEtat[j]=tabEtat[j-1];
    }
    tabCarte[j]=numCarte;
    tabPoint[j]=point;
    tabAge[j]=age;
    tabEtat[j]=1;
    printf("Age : %d",tabAge[i]);
    printf("\nFestivalier bien ajouté !!! \n\nVoici le profil : \nNuméro carte\tNombre de Points\tAge\tEtat de la carte\n");
    printf("%d\t\t%d\t\t\t%d\t%d\n", tabCarte[i], tabPoint[i], tabAge[i], tabEtat[i]);

    if (tlog==max)
    {
        printf("\nTableau plein\n");
        return -1;
    }
    tlog=tlog+1;
    while (numCarte!=0)
        {
            printf("\nSaisir le numéro de carte de l'adhérent (Saisir 0 pour arreter) : ");
            scanf("%d", &numCarte);
            if (numCarte == 0) return tlog;
            i=rechercher(tabCarte, numCarte, tlog, &trouve);
            if (trouve==0)
            {
                printf("\nNuméro d'adhérent déjà existant\n");
                return tlog;
            }
            printf("Nombre de point créditer sur la carte : ");
            scanf("%d", &point);
            printf("Saisir l'âge de l'adhérent : ");
            scanf("%d", &age);

        for (j=tlog; j>i; j--)
        {
            tabCarte[j]=tabCarte[j-1];
            tabPoint[j]=tabPoint[j-1];
            tabAge[j]=tabAge[j-1];
            tabEtat[j]=tabEtat[j-1];
        }
        tabCarte[j]=numCarte;
        tabPoint[j]=point;
        tabAge[j]=age;
        tabEtat[j]=1;
        
        printf("\nFestivalier bien ajouté !!! \nVoici le profil : \nNuméro carte\tNombre de Points\tAge\tEtat de la carte\n");
        printf("%d\t\t%d\t\t\t%d\t%d\n", tabCarte[i], tabPoint[i], tabAge[i], tabEtat[i]);
        
        if (tlog==max)
        {
            printf("\nTableau plein\n");
            return tlog;
        }
        tlog=tlog+1;
    }
        return tlog;
}

/**
 *\brief supprime les informations d'un adhérent si son numéro de carte est dans le tableau des numéros de carte
 *\param tabCarte[] tableau trié des numéros de carte des adhérents
 *\param tabPoint[] tableau des points de chaque cartes
 *\param tabAge[] tableau de l'age des adhérents
 *\param tabEtat[] tableau des états des cartes
 *\param tlog taille logique des tableaux
 *\return la taille logique après suppression
 *\author Khéna BRUNEAU
 */
int supprimerAdherent(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog)
{
    int numCarte, saisie=1, trouve, i, j;
    while (saisie!=0)
    {
        if (tlog==0)
        {
            printf("\nTableau vide\n");
            return -1;
        }
        printf("\nSaisir le numéro de carte de l'adhérent : ");
        scanf("%d", &numCarte);
        printf("Tlog avant recherche :%d",tlog);
        i=rechercher(tabCarte, numCarte, tlog, &trouve);
        printf("Tlog apres recherche :%d",tlog);
        if (trouve==1)
        {
            printf("\nNuméro d'adhérent inexistant\n");
            return tlog;
        }
        for (j=i; j<tlog; j++)
        {
            tabCarte[j]=tabCarte[j+1];
            tabPoint[j]=tabPoint[j+1];
            tabAge[j]=tabAge[j+1];
            tabEtat[j]=tabAge[j+1];
        }
        tlog=tlog-1;
        printf("\nAdhérent bien supprimer\n");
      	printf("\nContinuez de supprimer (1/0) ? ");
      	scanf("%d", &saisie);
      
    }
	return tlog;     
}

/**
 *\brief charge les informations du fichier adherent.txt dans les tableaux
 *\param tabAdherent[] tableau trié des numéros de carte des adhérents
 *\param tabCarte[] tableau des points de chaque cartes
 *\param tabAge[] tableau de l'age des adhérents
 *\param tabEtat[] tableau des états des cartes
 *\param size taille maximal des tableaux
 *\return la taille logique après chargement
 *\author Khéna BRUNEAU
 */
int chargement(int tabAdherent[],int tabCarte[], int tabAge[], int tabEtat[], int size)
{
    FILE *f;
    int i=0, adherent, pntcarte, age, etat;
    f = fopen("adherent.txt", "r");
    if (f == NULL)
    {
        printf("Erreur a l'ouverture du fichier\n");
        return -1;
    }
    fscanf(f, "%d %d %d %d", &adherent, &pntcarte, &age, &etat);
    while(!feof(f))
    {
        tabAdherent[i] = adherent;
        tabCarte[i] = pntcarte;
        tabAge[i] = age;
        tabEtat[i] = etat;
        i=i+1;
        fscanf(f, "%d %d %d %d", &adherent, &pntcarte, &age, &etat);
    }
    fclose (f);
    return i;
}

/**
 *\brief sauvegarde les informations des tableaux dans le fichier adherent.txt
 *\param tabCarte[] tableau trié des numéros de carte des adhérents
 *\param tabPoint[] tableau des points de chaque cartes
 *\param tabAge[] tableau de l'age des adhérents
 *\param tabEtat[] tableau des états des cartes
 *\param tlog taille logique des tableaux
 *\author Khéna BRUNEAU
 */
void sauvegarder(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog)
{
    int i, numCarte, point, age, etat;
    FILE *flot;
    flot=fopen("adherent.txt","w");
    for (i=0; i<tlog; i++)
    {
        numCarte=tabCarte[i];
        point=tabPoint[i];
        age=tabAge[i];
        etat=tabEtat[i];
        if (etat==3) etat=2;
        fprintf(flot, "%d\t%d\t%d\t%d\n", numCarte, point, age, etat);
    }
    fclose(flot);
}

/**
 *\brief affiche les informations des tableaux soit d'un seul adhérent soit de tous
 *\param tabCarte[] tableau trié des numéros de carte des adhérents
 *\param tabPoint[] tableau des points de chaque cartes
 *\param tabAge[] tableau de l'age des adhérents
 *\param tabEtat[] tableau des états des cartes
 *\param tlog taille logique des tableaux
 *\param saisie indique quel affichage faire
 *\author Khéna BRUNEAU
 */
void affichage(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog, int saisie)
{
    int i=0, numCarte, trouve;
    
    if (saisie==2) 
	{
        printf("\nNuméro carte\t Nombre de Points\t Age\t Etat de la carte\n");
        printf("tlog : %d\n",tlog);
	    while (i<tlog)
	    {
		    printf("%d\t\t %d\t\t\t %d\t %d\n",tabCarte[i], tabPoint[i], tabAge[i], tabEtat[i]);
		    i=i+1;
	    }
    }

    if (saisie==1)
    {
        printf("\nSaisir le numéro de l'adherent : ");
        scanf("%d", &numCarte);        
        frecherche(tabCarte, tlog, numCarte,&i, &trouve);
        if (trouve==0)
        {
            printf("\nAdhérent inexistant\n");
            return;
        }
        printf("\nNuméro carte\t Nombre de Points\t Age\t Etat de la carte\n");
        printf("%d\t\t %d\t\t\t %d\t %d\n", tabCarte[i], tabPoint[i], tabAge[i], tabEtat[i]);
    }
}

/**
 *\brief affiche et permet de naviguer dans le menu principal de l'application
 *\author Khéna BRUNEAU et Tony FAGES
 */
void global(void)
{
    int tlog, choix, sousChoix, size=50, tabAdherent[size], tabAge[size], tabCarte[size], tabEtat[size];
    int pos, code_retour, val, adherent, activité_concert=0, nb_soft = 0, nb_alcool=0;

    tlog=chargement(tabAdherent, tabCarte, tabAge, tabEtat, size);
    printf("\nBienvenue dans le gestionnaire du festival Les gens d'Air\n");
    printf("---------------------------------------------------");
    printf("\n\tGestion du festival \n1)\tAdhérents \n2)\tActivitées \n3)\tGestion \n9)\tQuitter \n");
    printf("Que voulez vous faire ? ");
    scanf("%d", &choix);
    while (choix!=9)
    {
        sousChoix = 0;
        if (choix==1)
            while (sousChoix!=9)
            {
                printf("---------------------------------------------------");
                printf("\n\tAfficher les informations \n1)\tD'un adhérent \n2)\tDe tout les adhérents\n3)\tAjouter un adhérent\n4)\tSupprimer un adhérent\n9)\tRetour \n");
                scanf("%d", &sousChoix);
                if (sousChoix==1 || sousChoix==2) affichage(tabAdherent, tabCarte, tabAge, tabEtat, tlog, sousChoix);
                if (sousChoix == 3) tlog =  creerAdherent(tabAdherent,tabCarte,tabAge,tabEtat,tlog,size);
                
                if (sousChoix == 4) tlog = supprimerAdherent(tabAdherent,tabCarte,tabAge,tabEtat,tlog);
            }
        if (choix==2)
            while (sousChoix!=9)
            {
                printf("---------------------------------------------------");
                printf("\n1)\tAfficher les informations sur les activités \n2)\tInscription a un concert\n3)\tAcheter des boissons\n9)\tRetour \n");
                scanf("%d", &sousChoix);
                if (sousChoix==1)  Activite(activité_concert,nb_alcool,nb_soft);
                if (sousChoix == 2)
                {
                   printf("Entrer votre numéro d'ahdérent : \n");
                   scanf("%d",&adherent);
                   Concert(tabAdherent, tabEtat,tabAge,tabCarte,tlog,adherent,&activité_concert);
                }
                if (sousChoix == 3)
                {
                    printf("Entrer votre numéro d'ahdérent : \n");
                    scanf("%d",&adherent);
		    AchatBoissons(tabAdherent,tabEtat,tabAge,tabCarte,tlog,adherent, &nb_soft, &nb_alcool);
                }
            }
        if (choix == 3)
        {
            while (sousChoix != 9)
            {
                printf("\n1)\tAlimenter une carte \n2)\tChanger l'état d'une carte\n9)\tRetour \n");
                scanf("%d", &sousChoix);
                if (sousChoix == 1)
                    Alim_Carte(tabAdherent,tabCarte, tabEtat, tlog);
                if (sousChoix == 2)
                    Change_Etat(tabAdherent, tabEtat, tlog);

            }

        }
        printf("---------------------------------------------------");
        printf("\n\tGestion du festival \n1)\tAdhérents \n2)\tActivitées \n3)\tGestion \n9)\tQuitter \n");
        printf("\nQue voulez vous faire ? ");
        scanf("%d", &choix);
    }
    sauvegarder(tabAdherent, tabCarte, tabAge, tabEtat, tlog);
}
