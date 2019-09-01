#include<stdio.h>

int main()
{
	int n, d[]={9,8,7,6,5,4,3,2}, i, j, k, q[8], t ;
	
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		if(n<10)
		{
			printf("%d\n",n);	
			continue;
		}
		for(i=0;i<8;i++)
			q[i] = 0;
		for(i=0;i<8;i++)
		{
			while(n%d[i]==0)
			{
				n /= d[i];
				q[i]++;
			}
		}
		if(n != 1)
			printf("-1\n");
		else
		{
			for(i=7;i>-1;i--)	
				for(j=0;j<q[i];j++)
					printf("%d",d[i]);
			printf("\n");
		}
	}
	return 0;
}
