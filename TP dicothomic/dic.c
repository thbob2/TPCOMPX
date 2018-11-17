#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>



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

/*  Recherche Séquentielle */

double recherche_dichotomique(double* tableau, int taille , double x)
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
             
             return pos;
            }
    }
   

    return pos;
}
/* fonction qui execute le tout */
double execution(double* table,int taille,double valeur)
{
    //double* res=malloc(sizeof(double)*taille);
    //int i=0;
    double xx,val;
    clock_t t1,t2;
    struct timeval stop, start;

        t1=clock();
        //gettimeofday(&start, 0);
        val = recherche_dichotomique(table,taille-1,valeur);
       // gettimeofday(&stop, 0);
        t2=clock();
        xx=(double)(t2-t1)/CLOCKS_PER_SEC;
        //printf("%lf",xx);
    return xx;

//////
}
////
int recherche_dichotomique_recursive(double* tableau, double x, int min, int max)
{
    int pos= -1;
    int i=0;

        if(min >= max)// vide
        {
            return -1;
            // printf("\n\tla valeur %.0f ....pas ...\n",x);
        }
        int milieu = (min + max) / 2;
        if (tableau[milieu] == x)
        {
            return milieu;
            // printf("\n\tla valeur %.0f existe a la position %d .\n",x,milieu);
        }
        else if (tableau[milieu] > x)
            return recherche_dichotomique_recursive(tableau, x, min, milieu);
        else
            return recherche_dichotomique_recursive(tableau, x, milieu + 1, max);
   // printf("\n\tla valeur %.0f ....pas ...\n",x);

    return pos;
}
// O(log n)
//////
int main()
{
     double tab[]={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,6),25.6*pow(10,6),51.2*pow(10,6),102.4*pow(10,6),204.8*pow(10,6)};

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
		res1[i]=execution( table1,taille,table1[49999]);
        printf(" %lf |\n",res1[i]);
		/*printf("\t pire cas : ");
		res2[i]=execution(table1,taille,table1[2]);
		printf("%lf\n",res2[i]);*/
	}

}