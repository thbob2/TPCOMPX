
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
/*
	int* tab=binaire(6,m);
	for (j=m-1;j>=0;j--)
	{
		printf("%d",tab[j]);
	}
	}*/

int* tab;
i=0;
int f=0;
while((i<val)&&(f!=1))
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
	if (v==1){
		f=1;
		printf(" C est vrai pour l interpretation %d \n",i);
	}
	i++;
}




/*	m[0][0]=0;m[0][1]=0;m[0][2]=0;
	m[1][0]=0;m[1][1]=0;m[1][2]=1;
	m[2][0]=0;m[2][1]=1;m[2][2]=0;
	m[3][0]=0;m[3][1]=1;m[3][2]=1;
	m[4][0]=1;m[4][1]=0;m[4][2]=0;
	m[5][0]=1;m[5][1]=0;m[5][2]=1;
	m[6][0]=1;m[6][1]=1;m[6][2]=0;
	m[7][0]=1;m[7][1]=1;m[7][2]=1;
	
	int i,j,c;
	c=0;
	for (i=0;i<8;i++)
	{
		c=((m[i][0]+m[i][1]+non(m[i][2]))%2)*((non(m[i][0])+m[i][1]+m[i][2])%2)*((m[i][0]+non(m[i][1])+m[i][2])%2 );
		if (c==1)
		printf(" C est vrai pour l interpretation : %d %d %d \n",	m[i][0],m[i][1],m[i][2]);
*/

	return 0;
}
