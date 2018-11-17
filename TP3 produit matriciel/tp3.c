#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>




/*int* remplire(int x,int y,int* mat[][]){
	for (int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			mat[i][j]= random(100);
	return mat;
}*/

int main(int argc, char *argv[])
{	int M[4]={70,80,100,200};
	int N[4]={90,120,250,350};//,480,650,800};
	int P[4]={100,300,500,600};//,700,800,900};
	int n,m,p;
	int A[n][m];
	int B[m][p];
	int C[n][p];
	int i,j,k;
	time_t t;
	clock_t t1,t2;
	double	delta;
	double deltass[7];
	for (i=0;i<n;i++)
		for(j=0;j<m;j++){
			srand((unsigned) time(NULL));
			A[i][j]= 1+ ((rand()% 50));
			
		}
for(int bord=0;bord<4;bord++){
	n = N[bord];
	m = M[bord];
	p = P[bord];
	t1=clock();
	for(i=0;i<n;i++ ){
		for(j=0;j<m;j++){				//O(n*m*p) ~ O(n^3) dans le cas où n=m=p
			for(k=0;k<p;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}

		}
	}
	t2=clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	deltass[bord]=delta;
}
	//printf("(%lf)\n",delta );
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("(%d)  ",A[i][j] );
		}
		puts("\n");
	
	
}
return 0;
}