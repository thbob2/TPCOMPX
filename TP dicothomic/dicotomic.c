
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE -1


/* creer un tableau trié */
double* table_trier(int n)
{
    double* res=malloc(n*sizeof(double));
    int i;
    for(i=0;i<n;i++)
    {
        res[i]=i;
    }
    return res;
}

int recherche_dichotomique(double* tableau, int taille , double x)
{
    int pos= -1;
    int i=0,min=0,max=taille,milieu=0;

    while ((min<=max) && (pos==-1))
    {
        milieu=(max+min)/2;
        if (x < tableau[milieu])  max=milieu-1;
        else if (x > tableau[milieu])  min=milieu+1;
        else{
             pos=milieu;
             // printf("\n\tla valeur %.0f existe a la position %d .\n",x,milieu);
             return pos;
            }
    }
   // printf("\n\tla valeur %.0f ....pas ...\n",x);

    return pos;
}

int main()
{
    double tab[]={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,6),25.6*pow(10,6),51.2*pow(10,6),102.4*pow(10,6),204.8*pow(10,6)};
    double xx;
    clock_t t1,t2;

    double* table1=NULL;
    //double* table2=NULL;
    double* res1=malloc(13*sizeof(double));
    double* res2=malloc(13*sizeof(double));
    int i;

    printf("\nLe temps d'execution de Recherche Dichotomique :\n\n");
    for(i=0;i<11;i++)
    {   int taille=(int)tab[i];
        printf("T(%d)\tmeillleur cas : ",taille);
        table1=table_trier( taille );
        
        t1=clock();
        recherche_dichotomique(tab,taille-1,valeur);
        t2=clock();
        xx=(double)(t2-t1)/CLOCKS_PER_SEC;
        res1[i] =xx;    

        printf("\t pire cas : ");
        res2[i]=execution(table1,taille,table1[taille-1]+5);
        printf("\n");
    }

}