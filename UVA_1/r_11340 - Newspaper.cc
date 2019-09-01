#include	<stdio.h>
#include	<string.h>

char a[10001],c[13];
int val[128];


int main()
{
	int t,i,j,m,v,n;
	double x;
	
	scanf("%d",&t);
	while(t--)	
	{
		scanf("%d",&n);	
		memset(val,0,sizeof(val));
		
		for(i=0;i<n;i++)
		{
			scanf("%s%d",c,&v);	
			val[c[0]] = v;
		}
		
		scanf("%d\n",&n);
		
		v = 0;
		while(n--)
		{
			gets(a);
			for(j=0;a[j] != '\0';j++)	
				v += val[a[j]];
		}
		
		x = (double)v/100; 
		printf("%.2lf$\n",x);
	}

	return 0;
}
