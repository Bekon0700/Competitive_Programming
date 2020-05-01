#include<stdio.h>
#include<algorithm>
using namespace std;

long long h[350];

void ss()
{
	h[1]=1;
	long long i,j,k=2,f2,f3,x,m=3000000000;
	
	for(f2=1;f2<m;f2 *= 2)
	{
		
		for(f3=1;f3<m;f3 *=3 )	
		{
			x = f2*f3;	
			if(x<m)	h[k++] = x;
		}
	}
	sort(&h[1],&h[k]);
}

long long BS(long long x)
{
	int l=1,hi=331,m;
	while(l <= hi)	
	{
		m=(l+hi)>> 1;
		if(h[m] < x)
			l= m+1;
		else if(h[m]>x)
			hi = m-1;
		else 
			return h[m];
	}
	if(h[m]<x)
		return h[ m+1 ];
	else
		return h[ m ];
}

int main()
{
	ss();
	long long i,n;
	while(scanf("%lld",&n)==1 && n)
	{
		n = BS(n);
		printf("%lld\n",n);
	}
	return 0;
}
