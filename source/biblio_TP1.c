#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include "affichage.h"
#include "biblio_TP1.h"


    /*********La variable Globale*******************************/
    tabchaine tabIndex[TAILLE_MAX_L]={""};/*Matrice d'Index*/
//    char chemin[40]="";//Le chemin relatif du fichier à indexer
    int indexB=0,nbreLigne=0;
    /*************************************************************************************/
    /*-------------------Les fonctions du TP_1 du SFSD-----------------------------------*/
    /*************************************************************************************/



/*******************************************************************************/
/*******************************************************************************/

int mot_vide(char *word)//verifier si le mot est vide
{
    char chaine[TAILLE]="",*tokenV,delims[]=" ";//le tableau ne contient que d'ESPACE
    FILE *fich;
    int fin=0;

    fich = fopen("mots_vides1.txt","r");
    if(fich != NULL)
    {
        fgets(chaine,TAILLE,fich);//lire le fichier qui est conatitué d'une seule ligne dans "chaine"
        if(strstr(chaine,word) != NULL)//charcher le mot "word" dans la chaine "chaine"
        {
            fin = 1;
        }
    }
    else
    {
        puts("ERREUR D'OUVERTURE !");
    }
    fclose(fich);

    return fin;
}

/*******************************************************************************/
/*******************************************************************************/

void permut_ch(int i,int j)//permuter entre les chaines des cases 'i' et 'j'
{
    char chaine[TAILLE_MAX_C]="",ch1[TAILLE_MAX_C]="",ch2[TAILLE_MAX_C]="";
    int l=0;

    for(l=0;l<TAILLE_MAX_C;l++)
    {
        ch1[l] = tabIndex[i][l];
        ch2[l] = tabIndex[j][l];
    }


    for(l=0;l<TAILLE_MAX_C;l++)
    {
        chaine[l] = ch1[l];
    }
    for(l=0;l<TAILLE_MAX_C;l++)
    {
        ch1[l] = ch2[l];
    }

    for(l=0;l<TAILLE_MAX_C;l++)
    {
        ch2[l] = chaine[l];
    }
    /*******************Mise à jour de la matrice*******************/
    for(l=0;l<TAILLE_MAX_C;l++)
    {
        tabIndex[i][l] = ch1[l];
        tabIndex[j][l] = ch2[l];
    }
}

/*******************************************************************************/
/*******************************************************************************/


int comp_ch(char *ch1,char *ch2)//comparer entre les chaines des cases 'k' et 'l'
{
    return strcmp(ch1,ch2);
}


/*******************************************************************************/
/*******************************************************************************/

void tri_tabIndex(int taitabIndex)
{
    int echange_effectue=0,i=0;

    do
    {
        echange_effectue=0;
        for(i=0;i<taitabIndex-1;i++)
        {
            if(comp_ch(i,i+1) == 2)
            {
                permut_ch(i,i+1);
                echange_effectue=1;
            }
        }
    }while(echange_effectue == 1);
}

/*******************************************************************************/
/*******************************************************************************/

void affich_tab(tabchaine t[],int k)//k: nombre de case à afficher
{
    int m=0,n=0;

    for(m=0;m<k;m++)
    {
       for(n=0;n<TAILLE_MAX_C;n++)
       {
            printf("%c",t[m][n]);
       }
       printf("\n");
    }
}

/*******************************************************************************/
/*******************************************************************************/

void indexer(const char *fname,int *m,int i)//indexer le fichier nomé "fname" et retourne le nombre des  cases du tableau d'Index
{
    FILE *f=NULL/*Pointeur sur le fichier à Indexer*/,*fIndex=NULL/*Pointeur sur le fichier Index*/;
    int k=0,j=0,p=0,cptL=-1,posM=0/*Le curseur du premier caractere du mot*/;
    int *pointeur = &i;
    char chaine[TAILLE_MAX_L]="",delims[]=" \\!@\n/#$%?&*(){}[]+-,.;:'’\"«»<>`°"/*Tableau des delimiteurs*/,nbL[NbreMax]="";

    *m=&i;
    f = fopen(fname,"r");
    if(f != NULL)
    {
        strcpy(chaine,"");
        while(fgets(chaine,TAILLE_MAX_L,f) != NULL)
              {
                    char nbM[NbreMax]="",*token;
                    p=0;
                    posM=0;
                    while(strchr(delims,chaine[posM]) != 0)
                    {
                        posM++;
                    }
                    cptL++;
                    token = strtok(chaine,delims);
                    while(token != NULL)
                    {
                        if((strlen(token) > 2) && (mot_vide(token) == 0)) //verifier si le mot est vide
                        {
                            p=0;
                            for(j=0;j < strlen(token);j++)
                            {
                                token[j] = tolower(token[j]);
                                tabIndex[i][j] = token[j];
                            }
                            tabIndex[i][j]=' ';//Espacement
                            j++;
                            for(p=0;p < strlen(fname);p++)
                            {
                                tabIndex[i][p+j] = fname[p];
                            }
                            j=j+p;
                            tabIndex[i][j] = '*';//Separateur
                            j++;
                            sprintf(nbL, "%d", cptL);//convertir l'entier cptL en chaine de caractere
                            for(p=0;p<nbrepos(cptL);p++)
                            {
                                tabIndex[i][p+j] = nbL[p];
                            }
                            j=j+p;
                            tabIndex[i][j] = ' ';
                            j++;
                            sprintf(nbM, "%d", posM);//convertir l'entier cptL en chaine de caractere
                            //printf("strlen=%d\n",strlen(nbM));
                            for(p=0;p<strlen(nbM);p++)
                            {
                                tabIndex[i][p+j] = nbM[p];
                            }

                            j=j+p;
                            tabIndex[i][j] = '#';
                            i++;

                        }

                        posM = strlen(token)+posM;
                        while(strchr(delims,chaine[posM]) != 0)
                        {
                            posM++;
                        }
                        token = strtok(NULL,delims);
                    }
              }
              //printf("i=%d\n",i);
              *m=*pointeur;
              fclose(f);
    }
    else
    {
        puts("ERREUR D'OUVERTURE !");
        puts("Veuillez donner un chemin correct !");
        printf("\n\n\n\nAppuyer sur une touche pour retourner au menu principal    \n\n");
        getche();
        menuSwitch();
    }
}

/*******************************************************************************/
/*******************************************************************************/


void chargement(tabchaine t[])//Chargement du fichier Index dans la MC
{
    FILE *f;
    char str[TAILLE_MAX_C]="";
    int i=0,j=0,p=0;
    f = fopen("Index.txt","r");
    if(f != NULL)
    {
        while(fgets(str,TAILLE_MAX_C,f) != NULL)
        {
            //printf("\nstr=%s\n",str);
            j=0;
            while(str[j] != '\n')
            {
                t[i][j] = str[j];
                j++;
            }
            //printf("\nt[i][j]=%s\n",t[i]);
            j=0;
            p=0;
            while(t[i][j]!=' ')
            {
                t[i][j]=tolerence(t[i][j]);
                j++;
            }
            i++;
        }
        qsort(t,nbreLigne,sizeof(tabchaine),comp_ch);
        /*printf("Voulez-vous afficher le tableau de chargement:  (1/0)\n");
        trait();
        if(getch()=='1')
        {
            affich_tab(t,nbreLigne);
        }
        trait();*/
    }
    else
    {
        puts("ERREUR D'OUVERTURE !");
        puts("Faites l'indexation avant !");
        printf("\n\n\n\nAppuyer sur une touche pour retourner au menu principal    \n\n");
        getche();
        menuSwitch();
    }
}

/*******************************************************************************/
/*******************************************************************************/


void rech(char *cle,int *i,int *j,int *tr,tabchaine tLoad[])//recherche la cle dans le tableau "tLoad" et retourne i:1ere occurence de la cle ,j:derniere occurence ,tr:le mot est trouve ou pas
{
    int p=0,inf=0,m=0,sup=0,tmp=0,k=0,trouve=0,*pointeurSurTmp=&tmp,*pointeurSurK=&k,*pointeurSurTrouve=&trouve;
    int posit=0,n=0;
    char nomFichier[30]="",nbL[NbreMax]="",poS[NbreMax]="";
    *i=&tmp;
    *j=&k;
    *tr=&trouve;
    /*for(p=0;p < strlen(cle);p++)
    {
        cle[p] = tolower(cle[p]);
    }*/

    strcpy(tLoad[nbreLigne],cle);//insérer la clé dans la derniére case de la mtrice
    tLoad[nbreLigne][strlen(cle)] = ' ';
    inf=0;
    sup=nbreLigne-1;
    while((inf <= sup) && (trouve == 0))
    {
        tmp=(inf + sup)/2;
        if(comp_ch_1(tLoad,tmp,nbreLigne) > 0)
        {
            sup = tmp - 1;
        }
        else if(comp_ch_1(tLoad,tmp,nbreLigne) == -1)
        {
            inf = tmp + 1;
        }
        else if(comp_ch_1(tLoad,tmp,nbreLigne) == 0)
        {

           k = tmp;
           trouve=1;
           if(tmp>=0)
           {
               while((tmp != 0) && (comp_ch_1(tLoad,tmp,tmp-1) == 0))
                {
                    tmp--;
                }
           }
           while((comp_ch_1(tLoad,k,k+1) == 0) && (k<nbreLigne-1))
           {
               k++;
           }
        }
    }

    if(trouve == 0)
    {
        tmp=-1;
        k=-1;
    }
    *i=*pointeurSurTmp;
    *j=*pointeurSurK;
    *tr=*pointeurSurTrouve;
}


/*******************************************************************************/
/*******************************************************************************/


int comp_ch_1(tabchaine t[],int k,int l)
{
    char ch1[25]="",ch2[25]="";
    int i=0;

    for(i=0;t[k][i] != ' ';i++)
    {
        ch1[i] = t[k][i];
    }
    ch1[i+1]='\0';
    for(i=0;t[l][i] != ' ';i++)
    {
        ch2[i] = t[l][i];
    }
    ch2[i+1]='\0';
    return strcmp(ch1,ch2);
}

void remplir_fichierIndex(tabchaine t[],int m)
{
    FILE *fIndex=NULL;//Pointeur sur le fichier Index
    int k=0,j=0;
    /****************************************************************************************/
    /*****************L'Ecriture du Tableau d'Index dans le fichier d'Index******************/
    /****************************************************************************************/
    fIndex = fopen("Index.txt","w");
    if(fIndex != NULL)
    {
        for(k=0;k<m;k++)
        {
            j=0;
            while(t[k][j] != '#')
            {
                fprintf(fIndex,"%c",t[k][j]);
                j++;
            }
            fprintf(fIndex,"%c",'#');
            fprintf(fIndex,"%c",'\n');
        }
    }

    fclose(fIndex);
}



/*******************************************************************************/
/*******************************************************************************/

void dir()  //recherche les fichiers .txt qui se trouvent dans un dossier
{
      struct _finddata_t D;
      int done = 0,hd=0,i=0,p=0,num[nbreMot];
      char save[40]="",save2[40]="",chemin[40]="";
      tabchaine nomFiles[nbreMot];
      printf("Donner le dossier :\t");
      gets(chemin);
      puts("Les fichiers trouves sont :\n");
      strcpy(save,chemin);
      strcat(save,"/");
      strcat(chemin,"/*.txt");
      nbreLigne=0;
      hd = _findfirst(chemin,&D);
      while (!done)
      {
        strcpy(save2,save);
        strcat(save,D.name);
        strcpy(chemin,save);
        i++;
        strcpy(nomFiles[i],chemin);
        indexer(chemin,&nbreLigne,nbreLigne);
        indexB=1;
        printf("fichier %d:\t%s\n",i,nomFiles[i]);
        strcpy(save,save2);
        done = _findnext(hd,&D);
      }

       //printf("nbre de ligne =%d\n",nbreLigne);
        printf("\nVoulez-vous afficher le tableau no trie:  (1/0)\n");
        trait();
        if(getch()=='1')
        {
            affich_tab(tabIndex,nbreLigne);
        }
        trait();
        //tri_tabIndex(m);
        qsort(tabIndex,nbreLigne,sizeof(tabchaine),comp_ch);
        printf("Voulez-vous afficher le tableau trie:  (1/0)\n");
        trait();
        if(getch()=='1')
        {
            affich_tab(tabIndex,nbreLigne);
        }
        trait();
        remplir_fichierIndex(tabIndex,nbreLigne);

}




/*******************************************************************************/
/*******************************************************************************/

void affiche_mots(tabchaine t[],int preOcc[],int derOcc[],int q,case_mot_rech tab[])//i:Ligne  , q:nombre de mots à afficher
{
    FILE *f=NULL;
    char ligne[TAILLE]="",nbL[NbreMax]="",poS[NbreMax]="",nomFichier[30]="",rep='0';
    int cptL=-1,p=0,l=0,k=0,line=0,cur=0,cpt=0,fin=0,v=0,occ=0;
    for(l=0;l<q;l++)
    {
        tbcolor(0);
        printf("Les resultats de la recherche du mot %d :\n",l+1);
        getche();
        occ=derOcc[l] - preOcc[l]+1;
        fin=0;
        cpt=0;
        while((preOcc[l]<=derOcc[l]) && (cpt < occ) && (fin==0))//preOcc:contient les premiéres occurences des mots , derOcc:contient les derniéres occurences des mots
        {
            k=0;
            line=0;
            cur=0;

            while(t[preOcc[l]][k]!=' ')
            {
                k++;
            }
            k++;
            p=0;
            while(t[preOcc[l]][k]!='*')
            {
                nomFichier[p]=t[preOcc[l]][k];
                p++;
                k++;
            }
            nomFichier[p]='\0';
            k++;
            p=0;
            while(t[preOcc[l]][k]!=' ')
            {
                nbL[p] = t[preOcc[l]][k];
                p++;
                k++;
            }
             nbL[p]='\0';
            //printf("nbL=%s\n",nbL);
            k++;
            p=0;
            //printf("\nc=%c \n1",t[preOcc[l]][k]);
            while(t[preOcc[l]][k]!='#')
            {
                poS[p] = t[preOcc[l]][k];
                p++;
                k++;
            }
            poS[p]='\0';
            line=atoi(nbL);
            //printf("ligne=%d\n",line);
            cur=atoi(poS);
            f = fopen(nomFichier,"r");
            if(f != NULL)
            {
                cptL=-1;
                while((fgets(ligne,TAILLE,f)!=NULL) && (cptL<line-1))
                {
                    cptL++;
                }
                trait();
                printf("Le fichier contenant le mot:\t%s\n",nomFichier);
                printf("La ligne contenant le mot :\t%d\n",line);
                printf("La phrase ou se trouve le mot:\n\n");
                for(p=0;p<cur;p++)
                {
                    printf("%c",ligne[p]);
                }
                tbcolor(2);
                for(p=cur;p<cur+strlen(tab[l]);p++)
                {
                    printf("%c",ligne[p]);
                }
                tbcolor(0);
                for(p=cur+strlen(tab[l]);p<strlen(ligne)-1;p++)
                {
                    printf("%c",ligne[p]);
                }
                puts("");
                trait();
            }
            else
            {
                printf("ERREUR D'OUVERTURE !");
            }
            fclose(f);
            preOcc[l]++;
            cpt++;
            if((cpt == 4) && (occ > 4))
            {
                printf("\nVoulez-vous d'autres resultats ? (0/1)\t");
                printf("\n");
                rep = getch();
                switch(rep)
                {
                    case '0':
                        fin=1;
                        break;
                    default:
                    fin=0;
                    break;
                }
            }
        }
    }
}


/*******************************************************************************/
/*******************************************************************************/

void rech_mult()
{
    char *token,delims[]=",? .;:'*-_&$#@()!\/<>\n«»",phrase[TAI_PH]="";
    case_mot_rech tab[nbreMot];
    tabchaine tLoad[TAILLE_MAX_L];
    int i=0,j=0,p=0,ligne=0,*l,*tr,*m,*n;
    int preOcc[nbreMot],derOcc[nbreMot];
    chargement(tLoad);
    textcolor();
    printf("Entrer le(s) mot(s) a chercher :\t");
    gets(phrase);
    token = strtok(phrase,delims);
    while(token!=NULL)
    {
        strcpy(tab[i],token);
        j=0;
        while(tab[i][j]!='\0')
            {
                tab[i][j] = tolower(tab[i][j]);

                //printf("c=%d\n",tab[i][j]);
                tab[i][j]=tolerence_saisie(tab[i][j]);
                //printf("c%d= %d\n",j,tab[i][j]);
                j++;
            }
        i++;
        token = strtok(NULL,delims);
    }
    //printf("token=%s\n",tab[0]);
    if(i != 1)
    {
        for(j=0;j<i;j++)
        {
            rech(tab[j],&m,&n,&tr,tLoad);
            if(tr==1)
            {
                strcpy(tab[p],tab[j]);
                preOcc[p]=m;
                derOcc[p]=n;
                p++;
            }
        }
    }
    else
    {
        rech(tab[p],&preOcc[p],&derOcc[p],&tr,tLoad);
        p++;
    }
    if((p==1) && (tr==0))
    {
        textcolor(1);
        printf("---------------------\n");
        puts("| Mot introuvable ! |");
        printf("---------------------\n");
        textcolor();
    }
    else
    {
        affiche_mots(tLoad,preOcc,derOcc,p,tab);
    }
}



char tolerence(char car)
{
    //printf("caractere =%d\n",car);
    switch(car)
    {
        case -32:
            return 97;
            break;
         case -22:
            return 101;
            break;
         case -23:
            return 101;
            break;
        case -24:
            return 101;
            break;
         case -25:
            return 99;
            break;
         case -18:
            return 105;
            break;
         case -12:
            return 111;
            break;
         case -5:
            return 117;
            break;
         case -7:
            return 117;
            break;
        default:
            return car;
            break;
    }
}


char tolerence_saisie(char car)
{
    //printf("caractere =%d\n",car);
    switch(car)
    {
        case -123:
            return 97;
            break;
        case -125:
            return 97;
            break;
        case -73:
            return 97;
            break;
        case -74:
            return 97;
            break;
        case -46:
            return 101;
            break;
        case -112:
            return 101;
            break;
         case -118:
            return 101;
            break;
         case -120:
            return 101;
            break;
        case -126:
            return 101;
            break;
         case -121:
            return 99;
            break;
         case -128:
            return 99;
            break;
        case -41:
            return 105;
            break;
         case -116:
            return 105;
            break;
        case -30:
            return 111;
            break;
         case -109:
            return 111;
            break;
         case -105:
            return 117;
            break;
         case -106:
            return 117;
            break;
        case -22:
            return 117;
            break;
        case -21:
            return 117;
            break;
        default:
            return car;
            break;
    }
}

int nbrepos(int a)
{
    int cpt=1,div;
    div = a/10;
    while(div != 0)
    {
        cpt++;
        div=div/10;
    }
    return cpt;
}
