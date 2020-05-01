#include<stdio.h>
#include<math.h>

int sq[10050];
int main()
{
	int  a, i, j, k, n, x, y, l, p, q, z ;

	for(i=1;i<10006;i++)
		sq[i] = i * i ;

	while(scanf("%d",&n)==1)
	{
		l = n >> 1 ;
		z = pow(10,n);	
		for(i=0;i<n;i++)
			printf("0");
		printf("\n");
		for( k = 1 ; sq[k] < z ; k ++ )
		{
			q = i = 0 ;
			p=sq[k];
			while(i<l) 
			{
				a = p % 10 ;
				p /= 10 ;
				q += a * pow(10,i ++ );
			}
			
			if(p + q == k)
			{
				
				p=log10(sq[k]) + 1;
				
				for(i=0;i<n-p;i++)
					printf("0");
				
				printf("%d\n",sq[k]);
			}
		}
	}

	return 0;
}