#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define k 3

int key(int x,int i){
	return ((x%(int)(pow(10,i)))/(int)pow(10,i-1));
}
void Triaux(int *T,int N,int i){
	int *output =malloc(N*sizeof(int));
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

void TriBase(int *T,int N,int k){
	for (int i=0;i<K;i++){
		Triaux(T,N,i);
	}
}


int main(int argc, char const *argv[])
{
	
	printf("%d\n",key(163,2));
	return 0;
}