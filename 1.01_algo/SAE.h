#include <stdio.h>
#include <stdlib.h>


void global(void);
int chargement(int tabAdherent[], int tabCarte[], int tabAge[],int tabEtat[], int size);
void affichage(int tabAdherent[], int tabCarte[], int tabAge[],int tabEtat[], int tlog);
void frecherche(int tabAdherent[], int tlog, int val, int *pos, int *code_retour);
void Alim_Carte(int tabAdherent[], int tabCarte[], int tabEtat[], int tlog);
void prix_Point(int nbPoint, int *prix);
void Sauvegarde(int tabAdherent[], int tabCarte[], int tabAge[], int tabEtat[], int tlog);
int Info_Adhérent(int tabAdherent[],int tabEtat[], int tabAge[], int tlog,int adherent,int *age);
void AchatBoissons(int tabAdherent[], int tabEtat[], int tabAge[],int tabCarte[], int tlog,int adherent,int *nb_soft,int *nb_alcool);
void Concert(int tabAdherent[], int tabEtat[], int tabAge[],int tabCarte[], int tlog, int adherent, int *activité_concert);
void Activite(int activité_concert,int nb_soft,int nb_alcool);



