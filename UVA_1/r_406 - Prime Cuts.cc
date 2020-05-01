#include<stdio.h>
#include<math.h>

int prime[500];
bool flag[1100];

void MAIN()
{
	int a,m,k,n,c,i,u,l,t=0;
	
	while(scanf("%d%d",&n,&c) == 2 )	
	{
		printf("%d %d:",n,c);
		m = n + 1 ;		
		i=1;
		while( prime[i] < m )
			i++;
		n = i - 1;
		
		if( n & 1 )
		{
			m = n / 2 ;
			m += 1 ;
			k = 2*c - 1 ; 
			u = m + c;
			l = m - c + 1 ;
		}
		else 
		{
			m = n /2 ;	
			k = 2*c ; 
			u = m + c + 1;
			l = m - c + 1 ;
		}
		if(n > k )
		{
			for(i= l; i < u ; i ++ )
				printf(" %d",prime[i]);	
			printf("\n\n");
		}
		else 
		{
			n++;
			for(i=1;i<n;i++)
				printf(" %d",prime[i]);	
			printf("\n\n");
		}
	}
}

void SEIVE()
{
	int i,j,k,x,c=1,m=1100;
	
	for(i=3;i<m;i += 2)	flag[i] = true;
	prime[c++] = 1; prime[c++] = 2;
	x = sqrt(m) + 1 ;
	for(i=3;i<m;i += 2)
		if(flag[i])
		{
			prime[c++] = i;	
			if(i < x )
				for(j=i*i, k=i<<1 ;j < m ;j += k)	
					flag[j] = false ;		
		}
}

int main()
{
	SEIVE();
	MAIN();

	return 0;
}
