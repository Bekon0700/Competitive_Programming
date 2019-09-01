#include<stdio.h>
#include<algorithm>
using namespace std;

int maxx,N,n,m[23],a[22],final,ar[23];
bool f;
void BT( int k,int r,int j);
int main()
{
	int i,j,b[22];
	
	while(scanf("%d%d",&N,&n)==2)
	{
		for(i=0;i<n;i++)	
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		f = false ;
		
		sort(&a[0],&a[n]);

		maxx = final = 0 ;

		BT(0,0,0);
		for(j=0;j<n;j++)
			for(i=0;i<final ;i++)
				if(b[j] == m[i])
					printf("%d ",m[i]);
		printf("sum:%d\n",maxx);
	}
	return 0;	
}

void BT( int k,int r,int j)
{
	if(f) 	
		return ;
	int i;
	if( r > N)	
	{
		return ;
	}
	else
	{
		if(r > maxx )
		{
			for(i=0;i<k;i++)
				m[i]=ar[i];
			final = k;
			maxx = r;
			if(maxx==N)
			{
				f=true;	
				return ;
			}
		}
		for(i=j; i < n ;i++)	
		{
			ar[k]=a[i];
			BT(k+1,r+a[i],i+1);			
		}
	}
}
