#include<stdio.h>
#include<math.h>

bool flag[1000100];
int prime[80000];
void SEIVE();

int main()
{
	int  i, x, m, n ;
	
	SEIVE();
	
	while(scanf("%d",&n) == 1 && n)	
	{
		printf("%d:\n",n);
		if(n & 1)
		{
			if(flag[n-2])	
				printf("2+%d\n",n-2);
			else
				printf("NO WAY!\n");
		}
		else if(n!=4)
		{
			m = n >> 1 ;
			m++;
			x = 0 ;
			for( i = 2 ; prime[i] < m ;i++)	
				if( flag[ n - prime[i] ] )
				{
					printf("%d+%d\n",prime[i], n - prime[i]);
					break;
				}
			
		}
		else	
			printf("2+2\n");	
			
	}
	
	return 0;
}

void SEIVE()
{
	int i,j,k,c=1,x,m = 1000010;
	
	x = sqrt(m) + 1;
	for(i=3;i<m;i += 2 )
		flag[i]=true;
	flag[2] = true ;
	prime[c++] = 2;
	for(i=3;i<m;i += 2)
		if(flag[i])	
		{
			prime[c++] = i;
			if(i<x)
				for(k = i<<1, j=i*i; j < m; j += k )	
					flag[j] = false ;
		}
}
