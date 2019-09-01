#include<stdio.h>

int main()
{
	int a[102][102],i,j,x,y;

	for(i=1;i<101;i++)
	{
		a[i][1]=1;
		a[1][i]=i;
	}

	for(i=2;i<101;i++)
		for(j=2;j<101;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1];
			if(a[i][j]>999999)
				a[i][j]%=1000000;
		}

	while(scanf("%d%d",&x,&y)==2 && (x||y))
	{
		printf("%d\n",a[x][y]);
	}

	return 0;
}
