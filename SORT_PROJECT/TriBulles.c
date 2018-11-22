#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#define  D 13
long tables[D]={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*poz(10,5),
			1.6*2*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,6),
			25.6*pow(10,6),51.2*pow(10,6),1.024*pow(10,6),2.048*pow(10,6)};
double deltas[D];
clock_t t1,t2;
double deltasOpt[D];

long *CreateArray(long N){
	long *arr = malloc(N*sizeof(long));
	for(int i =0;i<N;i++) {
		// use srand(time(NULL)) in case rand is not generating random numbers
			arr[i] = N-i-1;
	}
	return arr;
}

void printArr(long *T,double N){for (int i = 0; i < N; ++i) printf("%l\t",T[i]);}
// in order to print the execution time to each data sample 
void printDelta(double *d,long *t){ for (int i = 0; i <D;i++)printf("N = %ld | delta = %lf\n",d[i],t[j]);}

void TriBulle(long *T, long N){
	int change=1; 
	while(change==1){
		change = 0;
		for (long i=0; i<N-1;i++){
			if(T[i]>T[i+1]){
				long x = T[i];
				T[i] =	T[i+1];
				T[i+1] = x;
				change = 1;
			}
			
		}
	}

}

void TriBulleOpt(long T,long N){
	long  m=N-1;
	long change = 1;
	while(change==1){
		change = 0;
		for(int i=0;i<N;i++){
			if(T[i]>T[i+1]){
				int x = T[i];
				T[i]= T[i+1];
				T[i+1] = x;
				change = 1
			}
		}
		m = m-1;
	}
}


int main(int argc, char const *argv[])
{	double *T ;
	for(int j=0;j<D;j++){
		//generating the array
		T = CreateArray(Tables[j]);
	// calclate the excution time
		t1 = clock();
		TriBulle(T,Tables(j));
		t2 = clock();
		deltas[j] = double (t2-t1)/CLOCKS_PER_SEC;
		printf(" \njust %d remaining ...\n",D-j+1 );	
	}
	printDelta(deltas,tables); 
	//do the same for the optimale sort 
	for(int j=0;j<D;j++){
		//generating the array
		T = CreateArray(Tables[j]);
	// calclate the excution time
		t1 = clock();
		TriBulleOpt(T,Tables(j));
		t2 = clock();
		deltasOpt[j] = double (t2-t1)/CLOCKS_PER_SEC;		
	}
	printDelta(deltasOpt,tables); 
	return 0;
}