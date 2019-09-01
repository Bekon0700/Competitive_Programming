#include	<stdio.h>

char a[2000002];

int main()
{
	int n,i,min,d,r;
	
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%s",a);
		min = 2000001;
		r = d = -2000001;
		for(i=0;i<n;i++)
			if(a[i] != '.')
			{
				if(a[i] == 'R')
				{
					r = i;
					if(r-d < min)					
						min = r-d;
				}
				else if(a[i]=='D')
				{
					d = i;
					if(d-r < min)					
						min = d-r;
				}
				else 
				{
					min = 0;
					break;
				}
			}
		printf("%d\n",min);
	}


	return 0;
}
