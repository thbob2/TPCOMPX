#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>

void TriBulle(int *T, int N){
	int change=1; 
	while(change==1){
		change = 0;
		for (int i=0; i<N-1;i++){
			if(T[i]>T[i+1]){
				int x = T[i];
				T[i] =	T[i+1];
				T[i+1] = x;
				change = 1;
			}
			
		}
	}

}
void TriBulleOpt(int T,int N){
	int m=N-1;
	int change = 1;
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
{
	return 0;
}