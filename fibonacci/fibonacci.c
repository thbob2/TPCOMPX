#include <stdio.h>
#include <stdlib.h>
#include <math.H>
#include <time.h>
#define nval 9
clock_t t1,t2;
int vals[nval] ={5,10,15,20,25,35,45,60,100};
double deltarec[nval];
double deltaiter[nval];

int fibo_rec(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return (fibo_rec(n-1)+fibo_rec(n-2));
}	

int fibo_iter(int n){
	n1 = 0;
	n2 = 1;
	fib =0;
	for (int i=2;i<n;i++){
	 	fib = fib + n1 + n2;
	 	n1=n2;
	 	n2=fib;
	 }
	 return fib; 
}

int main(int argc, char const *argv[])
{	int fib ;
	// we start with the rec one 
	for (int i = 0; i < nval;i++){
		int N = vals[i];
		t1=clock();
		fib = fibo_rec(N);
		t2 =clock();
		deltarec[i] = (double)(t2-t1)/CLOCKS_PER_SEC;
	}
	for (int i = 0; i < nval;i++){
		int N = vals[i];
		t1=clock();
		fib = fibo_iter(N);
		t2 =clock();
		deltaiter[i] = (double)(t2-t1)/CLOCKS_PER_SEC;
	}
	for (int i = 0; i < nval;i++){
		printf("N: %d |Temp rec: %lf |Temp iter: %lf \n",vals[i],deltarec[i],deltaiter[i]);
	}
	return 0;
}