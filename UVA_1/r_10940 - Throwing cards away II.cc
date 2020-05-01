#include<stdio.h>

int main()
{
	int i,j,a[21],n;
	a[0]=1;
	for(i=1;i<20;i++)
		a[i]= a[i-1] << 1;
	while(scanf("%d",&n)==1 && n)	
	{
		i=1;
		if(n<3)
			printf("%d\n",n);
		else
		{
			while(a[i] < n)
				i++;
			if( a[i] == n)
				printf("%d\n",n);
			else
			{
				j = 2 * (n - a[i-1]) ;
				printf("%d\n",j);
			}	
		}
	}
	return 0;
}
