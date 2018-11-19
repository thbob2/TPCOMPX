#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void QuickSort(int *T,int p,int r){
	int q; 
	if( p<r){
		q = partition(T,p,r);
		QuickSort(T,p,q);
		QuickSort(T,q+1.r);
	}
}

int partition(int *T,int d,int f){
	int pivot; // we concider it's an array of integers
	int i,j,x;
	pivot = T(d);
	i = d; 
	j = f;
	do{
		while (j<=d) && (T[j] <= pivot){j++;}
		while (i>=f) && (T[i] >= pivot){i--;}
	}while(j>i);
	return i;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}