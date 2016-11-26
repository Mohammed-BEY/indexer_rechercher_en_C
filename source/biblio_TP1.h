#include <dirent.h>
#define TAILLE 1024 //Nombre maximal de caractéres que peut contenir une ligne de fichier à indexer
#define NbreMax 5 //Nombre maximale de position du premier caractére du mot à indexer
#define TAILLE_MAX_L 20000//Nombre maximal de lignes de la matrice
#define TAILLE_MAX_C 70 // Nombre maximal de colonnes de la matrice
#define TAI_PH 50 //taille maximale de tous les mots que l'utilisateur peut introduire à la recherche
#define nbreMot 10//nombre maximal de mots a chercher

typedef char tabchaine[TAILLE_MAX_C];
typedef char case_mot_rech[25];//designe la cese du tableau qui contient les mots à rechercher
typedef  int (*compar)(const void*,const void*);

int searchc( int ch) ;   //donner la position d'un car dans une chaine.
int mot_vide(char mot[]);//verifier si le mot est vide ou pas
void permut_ch(int i,int j);//permuter deux chaines de caracteres
//int comp_ch(int k,int l);//comparer entre deux case de la matrice 1:case(k)<case(l) , 2:case(k)>case(l)
int comp_ch( char *ch1,  char *ch2);//comparer entre les chaines des cases 'k' et 'l'
void tri_tabIndex(int taitabIndex);//trier le tableau d'Index
void affich_tab(tabchaine t[],int k);//afficher le contenu du tableau d'Index
void indexer(const char *fname,int *m,int i);//indexer le fichier nomé "fname" et retourne le nombre des  cases du tableau d'Index
void dir();  //recherche les fichiers .txt qui se trouvent dans un dossier donné
void chargement(tabchaine t[]);//Chargement du fichier Index dans la MC
int comp_ch_1(tabchaine t[],int k,int l);//comparer les mots des case 'k' et 'l' champ (mot) :  1:case(k)<case(l) , 2:case(k)>case(l) , 0:identique
void rech(char *cle,int *i,int *j,int *tr,tabchaine tLoad[]);//recherche la cle dans le tableau "tLoad" et retourne i:1ere occurence de la cle ,j:derniere occurence ,tr:le mot est trouve ou pas
int compterFichier(DIR* dir);//Compter le nombre de fichiers
int isDir(struct dirent* ent);//Vérifier si le nom du fichier a une extension (.txt).
void remplir_fichierIndex(tabchaine t[],int m);//L'Ecriture du Tableau d'Index dans le fichier d'Index
void index_plus_fichier(int *s);//indexer plusieurs fichiers et retourner le nombre des lignes du fichier Index total
void dir() ; //recherche les fichiers .txt qui se trouvent au dossier test
void affiche_mots(tabchaine t[],int preOcc[],int derOcc[],int q,case_mot_rech tab[]);//i:Ligne  , q:nombre de mots à afficher
char erreur_fra(int c);//corriger les fautes de frappe
void rech_mult();//recherche d'un ou plusieurs mots
char tolerence(char car);//rendre le tableau de chargement sans les caracteres speciaux
char tolerence_saisie(char car);//permet la tolerence de faute de frappe
int nbrepos(int a);//retourner le nombre de position du nombre 'a'
