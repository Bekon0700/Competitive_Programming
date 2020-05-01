#include<stdio.h>
#include<math.h>

bool flag[32800];
int prime[3600];
void SEIVE();

int main()
{
	int  i, x, m, n ;
	
	SEIVE();
	
	while(scanf("%d",&n) == 1 && n)	
	{
		if(n==4)
		{
			printf("1\n");	
			continue;
		}
		m = n / 2 + 1;
		x = 0 ;
		
		for( i = 2 ; prime[i] < m ;i++)	
			if( flag[ n - prime[i] ] )
			{
				x ++ ; 
				
			}
		
		printf("%d\n",x);		
		
	}
	
	return 0;
}

void SEIVE()
{
	int i,j,k,c=1,x,m = 32800;
	
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
