#include<stdio.h>


int main()
{
	int n,m,c,max,cc,i,j,cap[21],t=1;
	bool tst[21];
	
	while(scanf("%d%d%d",&n,&m,&c)==3 && (n||m||c))
	{
		n++;
		for(i=1;i<n;i++)
		{
			scanf("%d",&cap[i]);
			tst[i] = false;
		}
		cc=max=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&n);
			if(tst[n])
			{
				cc -= cap[n];
				tst[n] = false;
			}
			else
			{
				cc += cap[n];
				tst[n] = true;
			}
			if(cc>max)
				max  =cc;
		}
		printf("Sequence %d\n",t++);
		if(max>c)
			printf("Fuse was blown.\n\n");
		else
		{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n",max);
		}
	}
	return 0;
}
