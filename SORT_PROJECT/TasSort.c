#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
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

// function to insert in the TAS 
void insertlongas(long *T,long x,long a,long b){
	for (long i=2*a;i<=b;i++){
		if(i<b)
			if(T[i]<T[i+1])i++;
		if(x>=T[i])
			break;
		else{
			T[a] = T[i];
			a = i;
		}
	}
	T[a] = x ;
}
// Fucntion to build the TAS 
void BuildTas(long *T, long N){
	for (long i = N/2; i>1;i--){
		insertlongas(T,T[i],i,N);
	}
}


// The sort function 
void TasSort(long *T,long N){
	long x;
	// we build the tas to start with 
	BuildTas(T,N);
	for (long i=N;i>=1;i--){
		x = T[i];
		T[i] =T[1];
		insertlongas(T,x,1,i-1);
	}

}
int  main(int argc, char const *argv[])
{	double *T ;
	for(int j=0;j<D;j++){
		//generating the array
		T = CreateArray(Tables[j]);
	// calclate the excution time
		t1 = clock();
		TasSort(T,Tables(j));
		t2 = clock();
		deltas[j] = double (t2-t1)/CLOCKS_PER_SEC;
		printf(" \njust %d remaining ...\n",D-j+1 );	
	}
	printDelta(deltas,tables); 
	return 0;
}