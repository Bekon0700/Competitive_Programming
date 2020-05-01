#include<stdio.h>
#include<math.h>

int  prime[80000], dp[80000], c=1, index[1000010] ;
bool  flag[1000010];

void seive();

int main()
{
	int k,a,b,t,x,y;
	
	seive();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		
		k = dp[index[b]] - dp[index[a]] ;
		y = dp[index[a]] - dp[index[a-1]];
		
		if( !k && y )
		{	
			printf("1\n");
			continue;
		}
		if(y)	
			k++;
		printf("%d\n",k) ;
	}

	return 0 ;
}

void seive()
{
	int i,j,k,p=1000001,x,d=1,y,add;
	
	flag[2]=true;
	for( i = 3 ; i < p ; i += 2 )	
		flag[i] = true ;
	x = sqrt(p) ; x ++ ;
	index[1]=0;
	prime[1]=2;
	index[2]=1;
	dp[0]=0;
	dp[1]=1;
	for ( i = 3 ; i < p ; i += 2 )
		if(flag[i])
		{
			prime [ ++ c ] = i;
			index [ i ] = c;
			add = 0 ;
			y = i ;
			while( y )
			{
				add += ( y % 10 ) ;
				y /= 10 ;
			}
			if(flag[add])
				dp[c] = ++ d ;
			else
				dp[c] = d ;
			
			if( i < x )
			{
				k = i << 1;
				for( j = i * i ; j < p ; j += k )
					flag[j] = false ;
			}
		}
		else
			index[i] = c;
		for( i = 4 ; i < p ; i += 2 )
			index[i]=index[i-1];
}
