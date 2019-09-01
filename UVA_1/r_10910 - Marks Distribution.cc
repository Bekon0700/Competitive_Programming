#include<stdio.h>

int main()
{
	int a[72][72],i,j,n,m,p,t,I,J;

	for(i=0;i<71;i++)
	{
		a[i][1] = i ;
		a[1][i] = a[i][0] = 1 ;
	}
	for(i=2,I=1;i<71;i++,I++)	
		for(j=2,J=1;j<71;j++,J++)	
			a[i][j] = a[I][j] + a[i][J];	
		
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&p,&m);
		m *= n;
		p -= m;
		printf("%d\n",a[n][p]);
	}
	return 0;
}
