#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void TriGnome(int *T,int N){
	int i = 0;
	while(i<n){
		if(i==0) {i++;}
		if(T[i] >=T[i-1]) {i++;}
		else{
			int x = T[i-1];
			T[i-1] = T[i];
			T[i] = x;
			i--;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}