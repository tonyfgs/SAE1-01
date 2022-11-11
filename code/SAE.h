#include <stdio.h>
#include <stdlib.h>


void frecherche(int tabAdherent[], int tlog, int val, int *pos, int *code_retour);
void Alim_Carte(int tabAdherent[], int tabCarte[], int tabEtat[], int tlog);
void prix_Point(int nbPoint, int *prix);
void AchatBoissons(int tabAdherent[], int tabEtat[], int tabAge[],int tabCarte[], int tlog,int adherent,int *nb_soft,int *nb_alcool);
void Concert(int tabAdherent[], int tabEtat[], int tabAge[],int tabCarte[], int tlog, int adherent, int *activité_concert);
void Activite(int activité_concert,int nb_soft,int nb_alcool);
int creerAdherent(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog, int max);
int chargement(int tabAdherent[], int tabCarte[], int tabAge[], int tabEtat[], int size);
void affichage(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog, int saisie);
void sauvegarder(int tabCarte[], int tabPoint[], int tabAge[], int tabEtat[], int tlog);
void Change_Etat(int tabAdherent[], int tabEtat[], int tlog);
void global(void);

