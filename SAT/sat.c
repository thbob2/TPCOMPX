#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define m 10000
#define n 20000

/*on represente une instance de sat a l'aide d'une matrice
de taille n*m 
n: nombre de clause 
m: nombre de proposition 
les elements de la matrice ${0,1,2}
0 p aparait negativement dans la clause
1 p aparait positivement 
2 p n'aparait pas */

int **C;
int *instvec;

int** buildmat(int nbl,int nbc){
	int **mat = malloc(nbl*sizeof(int*));
	for (int i = 0; i < nbl;i++){
		mat[i] = malloc(nbc *sizeof(int));	
	}
	for (int i=0;i<nbl;i++)
		for(int j=0;j<nbc;j++)
			mat[i][j]= (rand()%3);
	return mat;	
}

void printmat(int **mat,int nbl,int nbc){
	for (int i=0;i<nbl;i++){
		printf("| ");
		for(int j=0;j<nbc;j++){
			printf("%d\t",mat[i][j] );
		
		}
		printf("|\n");
	}
}

int* buildinst(int nbc){
	int *inst=malloc(nbc*sizeof(int));
	for (int i = 0; i <nbc ;i++){
		inst[i] = 1;//rand()%2;		
	}
	return inst;
} 
void printints(int *t,int nbc){
	for (int i = 0; i <nbc ;i++){
		printf("%d\t",t[i]);
	}
	printf("\n");
}

int validation(int nbl,int nbc, int **mat,int *inst){
	int sol = 1;
	int i=0;
	while((sol)&&(i<nbl)){
		int clause_sat=0; //
		int j=0;
		while((!clause_sat)&&(j<nbc)){
			if(( (inst[j] == 0) && ( mat[i][j] == 0) ) || (( inst[j] == 1) && ( mat[i][j] == 1))){
				clause_sat=1;
			}else{j++;}

		}
		if(!clause_sat){
			sol=0;
		}else{i++;}
	}
	return sol;
}
int main(int argc, char const *argv[])
{	time_t t1,t2;
	C = buildmat(n,m);
	instvec = buildinst(m);
	//printints(instvec,m);
	/*t1=clock();
	
	t2=clock();
	double delta= (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%lf\n",delta);*/
	printf("%d",validation(n,m,C,instvec));
	
	return 0;
}