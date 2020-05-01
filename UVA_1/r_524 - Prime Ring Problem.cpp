#include<stdio.h>

bool  prime[33];
int n;
void BACKTRACK(int d,int k,int out[],bool test[]);

int main()
{
	int  out[20], i, j, k, t=1;	
	bool test[18];
	prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31] = true ;
	
	while(scanf("%d",&n)==1)
	{
		if(t != 1)
			printf("\n");
		for(i=1;i<=n;i++)
			test[i]=true;
		printf("Case %d:\n",t);
		t ++ ;
		out[0]=1;
		BACKTRACK(1,1,out,test);
		
	}
	return 0;
}

void BACKTRACK(int d,int k,int out[],bool test[])
{
	int i;
	
	if( d == n && prime[out[0]+out[n-1]])
	{
		for(i=0; i < n-1 ;i++)	
			printf("%d ",out[i]);
		printf("%d\n",out[i]);
	}
	else
	{
		for(i=2;i<=n;i++)	
			if(prime[i+k] && test[i])
			{
				out[d]=i;
				test[i]=false;
				BACKTRACK(d+1,i,out,test);
				test[i]=true;								
			}
	}		
}
