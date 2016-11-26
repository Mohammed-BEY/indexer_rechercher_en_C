#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "biblio_TP1.h"

/********************La variable Globale*******************************/
/********/    tabchaine tabIndex[TAILLE_MAX_L];  /***Matrice d'Index***/

    int *m;
    char nomF[30]="",cle[25]="";
    tabchaine t[TAILLE_MAX_L],tLoad[TAILLE_MAX_L];
    extern indexB;

char affichage_Menu()
{
    char Choix = '0';

    system("cls");
    system("color 9f");
    do
	{
    system("cls");
    system("color 3f");
    printf("\n\n\n\n\n\n\n");
    printf("                          ******************                       \n");
    printf("                          |  1- Indexer    |                          \n\n\n");//L'Index sera trié automatiquement
    printf("                          |  2- Recherche  |                        \n\n\n");
    printf("                          |  3- Quitter    |                         \n");
    printf("                          ******************                       \n");
    printf("\n\n\n\n\n\n\nChoix :\t");

    while(Choix <'1' || Choix >'3')
    {

        time_t t =time(NULL);
        gotoxy(45,27);
        printf("Date is : %s\n", ctime(&t));
        Choix=getch();
    }
    //Choix=getch();




  	} while (Choix <'1' || Choix >'3');
	system("cls");
	return Choix;
}

/*******************************************************************************/
/*******************************************************************************/

void menuSwitch()
{

    char ch='0';
    do
    {
    char qt = '0',nomF[30]="";
    int rep=0,l=0;
        ch=affichage_Menu();
        switch(ch)
        {
            case '1':
                system("color 9f");
                dir();
                gotoxy(0,24);
                printf("\n\n\n\nAppuyer sur une touche pour retourner au menu principal    \t");
                getche();

                break;
            case '2':
                system("color 0f");
                if(indexB==1)
                {
                    rech_mult();
                }
                else
                {
                    puts("Aucun fichier indexe !");
                }

                printf("\n\n\n\nAppuyer sur une touche pour retourner au menu principal    \t");
                getche();

                break;
            case '3':
                system("color Cf");
                printf("\nvoulez vous vraiment quitter ?   ( 1/0 )");
            qt=getch();

            if(qt=='0')
            {
                ch='0';
            }
            if(ch!='0')
            {
                system("cls");
                system("color 08");
//while(getche())
//{
                //system("cls");
                dessin(0);
                dessin(61);
                system("color FC");


    printf("\t\t\trealise par:\n");
printf("*\t _____   ____        __                                               *\n");
printf("*\t|  _ \ | |____|   || / /                                               *\n");
printf("*\t| |_| | | |__    ||/ /                                                *\n");
printf("*\t|  _  { |  __|   |/ /         Ahmed Khernache Mohammed                *\n");
printf("*\t| |_| | | |___   / /                                                  *\n");
printf("*\t|_____/ |_____| /_/                                                   *\n");
puts("*                                                                             *");
    printf("*\t    ___   _____   _    _____      ___  ___       ___   _   _          *\n");
    printf("*\t   /   | |  _  \| | |  / _  /     /   |/   |     /   | | | | |         *\n");
   printf("*\t  / /| | | |_| | | | | |___     / /|   /| |    / /| | | | | |         *\n");
  printf("*\t / / | | |  _  { | | \___  \     / |__/ | |     / | | | | | |   Walid   *\n");
 printf("*\t/ /  | | | |_| | | |  ___| |  / /       | |  / /  | | | | | |___      *\n");
printf("*      /_/   |_| |_____/ |_| /_____/ /_/        |_| /_/   |_| |_| |_____|     *\n");
puts("*                                                                             *\n*                                                                             *\n*                                                                             *");
//}

printf("*******************************************************************************");
exit(1);

            }
        break;


            default:
            break;
        }
    }while(ch!='3');

}
/*******************************************************************************/
/*******************************************************************************/

void dessin(int i)
 {
   textcolor(2);
   gotoxy(i,0);
   printf(" _____   _____   _\n");
   gotoxy(i,1);
   printf("| ____| /  ___/ | |\n");
   gotoxy(i,2);
   printf("| |__   | |___  | |\n");
   gotoxy(i,3);
   printf("|  __|  \___  \ | |\n");
   gotoxy(i,4);
   printf("| |___   ___| | | |\n");
   gotoxy(i,5);
   printf("|_____| /_____/ |_|\n");
   textcolor();
 }


void prepresentatation()
{
    system("color 2f");
    puts("");
    puts("               Republique Algerienne Democtratique et Populaire\n\n");

    puts("                   Ecole nationale Supeieure d'Informatique\n\n");

    puts("                     Classes Preparatoires Integrees 2CPI\n");
    printf("                                 Groupe: 04                   \n\n");
puts("                        _____   _____        ___ ");
puts("                       |_   _| |  _   \     |_   |");
puts("                         | |   | |_|  |       | |");
puts("                         | |   |  ___/        | |");
puts("                         | |   | |            | |");
puts("                         |_|   |_|            |_|");


    puts("\n\n                     Encadre par M. :Boulekradeche Mohammed");
    puts("\n\n\n\n\n\n\n                 Annee universitaire :2013-2014  /*\\ 1434-1435 ");
    getche();
    system("cls");
    system("color f5");
    puts("");
    puts("Voici les notes a tenir en compte :\n");
    puts("\n\n1->A l'indexation veuillez donner le chemin relatif du repertoire contenant les fichiers.");
    puts("\n\n2->Tous les fichiers texte (.txt) se trouvant dans le repertoire designe seront indexes");
    puts("\n\n3->Les lignes du fichier d'Index sont numerotes a partier de '0'");
    getche();
}


void trait()
{
    int i;
    //printf("\n");
    for (i=0;i<80;i++)
    printf("%c",196);
    //printf("\n");
}
