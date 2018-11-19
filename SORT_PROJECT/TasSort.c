#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// function to insert in the TAS 
void insertInTas(double *T,int x,int a,int b){
	for (int i=2*a;i<=b;i++){
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
void BuildTas(double *T, int N){
	for (int i = N/2; i>1;i--){
		insertInTas(T,T[i],i,N);
	}
}


// The sort function 
void TasSort(double *T,int N){
	int x;
	// we build the tas to start with 
	BuildTas(T,N);
	for (int i=N;i>=1;i--){
		x = T[i];
		T[i] =T[1];
		insertInTas(T,x,1,i-1);
	}

}