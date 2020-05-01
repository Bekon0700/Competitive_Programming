#include<stdio.h>
#include<algorithm>
using namespace std;

int cost[20010];

int main()
{
	int i,n,t,discount;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&cost[i]);
		sort(&cost[0],&cost[n]);
		discount = 0;
		for(i=n-3;i>-1;i -= 3)
			discount += cost[i];
		printf("%d\n",discount);
	}
	return 0;
}
