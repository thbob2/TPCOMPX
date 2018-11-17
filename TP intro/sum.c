#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
	int i,s,n;
	clock_t t1,t2;
	double delta; 
	long tab1[10]={1.0E+6,2.0E+6,1.0E+7,2.0E+7,1.0E+8,2.0E+8};
	double tab2[10];
	double tab3 [10];
	//printf("donner n");
	//scanf("%d",&n)
	for(int j=0; j<10;j++)
	{
		t1=clock();
		s=0; i=1;
		while(i <= tab1[j])
		{
			s=s+i;
			i++;
		}
		//printf("(%d)\n",s );
		t2=clock();
		delta = (double)(t2-t1);
		tab2[j] = delta/CLOCKS_PER_SEC;
		//tab3[j]= (5*tab1[j]+6)*2;
	}

	for(int j=0; j<10;j++){
		printf("le n = %ld |le temp éxperimental= %lf| \n",tab1[j],tab2[j]);
	}
	return 0;
}