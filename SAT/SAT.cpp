#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* binaire (int n,int m)
{
	int r,i=m-1,j=0;
	int* tab=(int*) malloc (sizeof(int)*m);
	for (j=0;j<m;j++)
	{
		tab[j]=0;
	}
	while (n!=0)
	{
		r=n%2;
		tab[i]=r;
		n=(n-r)/2;
		i--;
		
	}
return tab;
}

int main(int argc, char** argv) {
	int m,n,val,k,v,s;
	
	printf("Donner le nombre de litteraux \n");
	scanf("%d",&m);
	printf("Donner le nombre clauses \n");
	scanf("%d",&n);	
	int c[n][m];
		int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
		scanf("%d",&c[i][j]);
		
		}
	}
	
val= pow(2,m);

int* tab;
for (i=0;i<val;i++)
{	v=1;
	tab=binaire(i,m);
	j=0;
	while((j<n)&&(v!=0))
	{		s=0;
	k=0;
			while((k<m)&&(s!=1))
			{
				if(c[j][k]==tab[k])
				{
					s=1;
				}else
				{
					k++;
				}
				
			}
			if(s==0)
			v=0;
			j++;
	}
	if (v==1)
		printf(" C est vrai pour l interpretation %d \n",i);
}

	return 0;
}
