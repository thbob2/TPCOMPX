#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	/* code */
	long n,nb,i,j=0;
	long int tab1[10]={1000003,2000003,4000037,8000009,16000057,32000011,64000031,128000003,256000001,512000002};
	double tab2[10];
	double delta;
	//printf(" veuillez introduire un nombre :\n"); //1
 	//scanf("%d",&n);	//1
	clock_t t1, t2;
	while(j<10)
	{	n=tab1[j];
		t1= clock();
		i = 1;		//2
		nb = 0;		//2
		while(i<=n) 		//n+1
		{	if(n%i == 0)	//2n
			{
				nb = nb+1;	//pire cas: 2(n/2 +1)		|meilleur cas : 2*2 
			}
			i++;		//2
	
		}
		if(nb > 2){printf(" le nombre %ld non premier\n",n );} //1
			else if(nb == 2){ printf(" le nombre %ld est premier\n",n);}//1  
		
		t2 =clock();
		delta = (double)(t2-t1)/CLOCKS_PER_SEC;
		printf("%lf\n",delta );
		tab2[j]=delta;
		j++;
	}
	return 0;			//meilleur cas T1(n) = 5n+11 
											//     } O(n)
						//pire cas T2(n) = 6n+9      
}