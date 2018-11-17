#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double** genmat(int ligne,int colonne){
	double **mat;
	mat = malloc(ligne*sizeof(double*));
	for(int i=0;i<ligne;i++){
		mat[i]=malloc(colonne*sizeof(double));
	}
	for (int i = 0; i <ligne ; i++)
	{ for (int j = 0; j < colonne; j++)
		{	//srand(time(NULL));
			mat[i][j]= rand()%50;		
		}
	
	}
return mat;
}


double** genc(int ligne,int colonne){
	double **mat;
	mat = malloc(ligne*sizeof(double*));
	for(int i=0;i<ligne;i++){
		mat[i]=malloc(colonne*sizeof(double));
	}
	for (int i = 0; i <ligne ; i++)
	{ for (int j = 0; j < colonne; j++)
		{	//srand(time(NULL));
			mat[i][j]= 0;		
		}
	
	}
	return mat;
}
int main(int argc, char** argv )
{	
	int M[4]={70,80,100,200};
	int N[4]={90,120,250,350};//,480,650,800};
	int P[4]={100,300,500,600};//,700,800,900};
	time_t t;
	clock_t t1,t2;
	double	delta;
	double deltass[4];
	double **A,**B,**C,**mat;
	int m,n,p;
	//mat = genmat(8,8);	


for(int bord=0;bord<4;bord++){
	n = N[bord];
	m = M[bord];
	p = P[bord];
	A=genmat(n,m);
	B=genmat(m,p);
	C=genc(n,p);
	t1=clock();
	for(int i=0;i<n;i++ ){
		for(int j=0;j<m;j++){				//O(n*m*p) ~ O(n^3) dans le cas où n=m=p
			for(int k=0;k<p;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}

		}
	}
	t2=clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	deltass[bord]=delta;
}
	for (int i = 0; i < 4;i++)
	{
		printf("%lf\n",deltass[i]);
	}
/*
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)
			printf("%lf\t",mat[i][j]);
		printf("\n");
	}
	/* code */
	
	free(A);
	free(B);
	free(C);
	return 0;
}