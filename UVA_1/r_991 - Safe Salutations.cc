#include<stdio.h>

int dp[12];

void VVR()
{
	int i,j,x,l;

	dp[0] = dp[1] = 1;	dp[2] = 2;
	
	for(i=3;i<11;i++)
	{
		x = 0;
		l = i/2;
		
		for(j=0; j<l ;j++)
			x += dp[j] * dp[i-j-1] ;

		x *= 2;

		if(i&1)
			x += dp[l] * dp[l];

		dp[i] = x ;
	}
}

int main()
{
	VVR();
	int n,t=0;
							
	while( scanf("%d",&n) == 1 )
	{
		if(t++)
			printf("\n");
		printf("%d\n",dp[n]);
	}
	return 0;
}
