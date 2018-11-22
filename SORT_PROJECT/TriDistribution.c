#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define k 7 // greater value is 2.048 *10^6
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
		arr[i] = rand()%N +1;
	}
	return arr;
}

void printArr(long *T,double N){ for (int i = 0; i < N; ++i) printf("%l\t",T[i]);}
// in order to print the execution time to each data sample 
void printDelta(double *d,long *t){ for (int i = 0; i <D;i++)printf("N = %ld | delta = %lf\n",d[i],t[j]);}

int key(long x,int i){return ((x%(int)(pow(10,i)))/(int)pow(10,i-1));}


void Triaux(long *T,long N,long i){
	long *output = malloc(N*sizeof(long));
	int cpt[10];
	for(int j=0;j<10;j++) cpt[j]=0;
// store the occurrences in cpt[]	
	for (int j=0;j<N;j++){
		cpt[key(T[j],i)]++; 
	}
// change cpt so it containes actual postion of this digit in output
	for(j=1;j<10;j++){
		cpt[j]=cpt[j-1];
	}
//build the output array
	for(j=n-1;j>=0;j--){
		output[cpt[key(T[j],i)]-1]=T[j];
		cpt[key(T[j],i)]--;
	}

//copy the output into the main arraay T
	for (int i=0;i<N;i++){
		T[i] = output[i];
	}
// it s a procedure so we don't have to return anything
}
// base sort or distribution sort it's the same 
void TriBase(long *T,long N,long k){
	for (long i=0;i<K;i++){
		Triaux(T,N,i);
	}
}


int main(int argc, char const *argv[])
{	double *T ;
	for(int j=0;j<D;j++){
	//generating the array
		T = CreateArray(Tables[j]);
	// calclate the excution time
		t1 = clock();
		TriBase(T,Tables(j));
		t2 = clock();
		deltas[j] = double (t2-t1)/CLOCKS_PER_SEC;
		printf(" \njust %d remaining ...\n",D-j+1 );	
	}
	printDelta(deltas,tables); 
	
	return 0;
}