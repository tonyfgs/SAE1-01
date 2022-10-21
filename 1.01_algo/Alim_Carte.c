#include <stdio.h>
#include <stdlib.h>

int chargement(int tabAdherent[], int tabCarte[], int tabAge[], int tabEtat[], int size)
{
    FILE *f;
    int i=0, adherent, pntcarte, age, etat;
    f = fopen("fichier.txt", "r");
    if (f == NULL)
    {
        printf("Erreur a l'ouverture du fichier");
        return -1;
    }
    fscanf(f, "%d %d %d %d", &adherent, &pntcarte, &age, &etat);
    while(!feof(f))
    {
        tabAdherent[i] = adherent;
        tabCarte[i] = pntcarte;
        tabAge[i] = age;
        tabEtat[i] = etat;
        i++;
        fscanf(f, "%d %d %d %d", &adherent, &pntcarte, &age, &etat);
    }
    return i;
    fclose (f);
}

void affichage(int tabAdherent[], int tabCartet[], int tabAge[], int tabEtat[],int tlog)
{
    int i;

    printf("Adherent\tCarte\tAge\tEtat\n");
    for (i=0; i<tlog; i++)
    {
        printf("%d\t\t%d\t%d\t%d\n", tabAdherent[i], tabCartet[i], tabAge[i], tabEtat[i]);
    }
}


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
        printf("Entrer le nombre de point a rajouter (1 point = 2€)\n");
        scanf("%d", &nbPoint);
        printf("%d\n", nbPoint);
        prix_Point(nbPoint, &prix);
        tabCarte[pos] = tabCarte[pos] + nbPoint;
        printf("Cela vous fera un total de point de %d€\n", prix);
        printf("Vous avez un total de %d point\n", tabCarte[pos]);
    }
    if (code_retour == 0)
      printf("Carte inexistante \n");
}

void Sauvegarde(int tabAdherent[], int tabCarte[], int tabAge[], int tabEtat[], int tlog)
{
    FILE *f;
    int i;
    f = fopen("fichier.txt","w");
    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    for (i=0; i < tlog; i++)
    {
        fprintf(f,"%d\t%d\t%d\t%d\n", tabAdherent[i],tabCarte[i],tabAge[i],tabEtat[i]); 
    }

    fclose(f);
}


void Change_Etat(int tabAdherent[], int tabEtat[], int tlog)
{
    int pos, code_retour, nbAdherent;
    printf("Entrer le numero de l'adherent dont l'état doit être changé \n");
    scanf("%d",&nbAdherent);
    frecherche(tabAdherent, tlog, nbAdherent, &pos, &code_retour);
    if(code_retour == 0)
    {
        printf("Adhérent inexistant\n");
        return;
    }
    if(code_retour == 1)
    {
        if(tabEtat[pos] == 0)
            tabEtat[pos] = 1;
        else if(tabEtat[pos] == 1)
                 tabEtat[pos] = 0;
    }
}
void global(void)
{
    int tlog, choix, size=50, tabAdherent[size], tabAge[size], tabCarte[size], tabEtat[size];
    int pos, code_retour, val;
    printf("Bienvenue au festival Test\nChoissisez une des catégories\n");
    tlog = chargement(tabAdherent, tabCarte, tabAge, tabEtat, size);
    while(choix != 9)
    {
        printf("1- Affichage\n2- Rechercher\n3- Alimenter carte\n4- Changer etats\n5- Sauvegarder\n9- Exit\n");
        scanf("%d", &choix);
        if (choix == 1)
            affichage(tabAdherent, tabCarte, tabAge, tabEtat, tlog);
        if (choix == 2)
        {
            printf("entrer la carte rechercher\n");
            scanf("%d",&val);
            frecherche(tabAdherent, tlog, val, &pos, &code_retour); 
            printf("%d\n", pos);
        }
        if (choix == 3)
            Alim_Carte(tabAdherent,tabCarte, tabEtat, tlog);
        if (choix == 4)
            Change_Etat(tabAdherent, tabEtat, tlog);
        if (choix == 5)
            Sauvegarde(tabAdherent,tabCarte,tabAge,tabEtat, tlog);
    }
}
