#include<stdio.h>

int main()
{
	int t,kase,f,total,n,c;

	scanf("%d",&kase);
	
	while(kase--)
	{
		
		scanf("%d%d%d",&c,&f,&n);
		
		total = 0;
		while(f+c >= n)
		{
			f += c ;
			c = f/n;
			f %=n;
			total += c;
		
		}
		printf("%d\n",total);
	
	}

	return 0;
}