#include<stdio.h>
#include<algorithm>

using namespace std;
int h[5850];

void H();

int main()
{
	int n;
	H();
	while(scanf("%d",&n)==1 && n)	
	{
		printf("The %d",n);
		if(n%100>10 && n%100 < 14)
			printf("th");
		else if(n%10==1 )
				printf("st");
			else if(n%10 == 2)
				printf("nd");
				else if(n%10 == 3)
					printf("rd");
					else
						printf("th");
		
		printf(" humble number is %d.\n",h[n]);
	}

	return 0;
}
void H()
{
	long long i,j,k,l,p2,p3,p7,p5,I=1, m = 2000000001,p;
	
	p = 0 ;
	for(i=1 ; i < m ; i*=2)
	{
		
		for(j=1; j < m ;j*=3)
		{
			for(k=1; k < m ;k*=5)
			{
				for(l=1; l < m ;l*=7)
				{
					p = i*j*k*l;
					if( p < m && p > 0 )
						h[I++] = p;
				}
			}
		}
	}
	sort(&h[1],&h[I]);
}
