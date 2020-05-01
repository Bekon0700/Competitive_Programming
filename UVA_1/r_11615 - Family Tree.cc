#include<stdio.h>
#include<math.h>

int main()
{
	long long i,j,k,l,n,m,u,v,t,x,y;
	
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&u,&v);	
		if(u>v)	v=u;
		x = 1<<n ;
		x -= 1;
		k = log2(v)+1;
		i = n - k + 1 ; 
		j = 1<< i;
		j -= 2 ;
		x -= j;
		printf("%lld\n",x);
	}

		
	return 0;
}
