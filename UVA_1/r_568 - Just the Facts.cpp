#include<stdio.h>

int main()
{
	int a, n, i, j, k;
	
	while(scanf("%d",&n)==1)
	{
		k=1;
		for(i=2;i<=n;i++)
		{
			k *= i ;
			while(k%10==0)
			{
				k /= 10 ;
			}
			k %= 100000;
		
		}
		printf("%5d -> %d\n",n,k%10);
	

	}


	return 0;
}
