#include	<stdio.h>

char a[202][202],C; 
int F,R,Qx[40002],Qy[40002],n,T,r[]={-1,-1,0,0,1,1},c[]={-1,0,-1,1,0,1};

void bfs(int y,int x)
{
	int i;
	F = R = 0;
	Qx[R] = x,	Qy[R] = y,	R++;
	a[y][x] = '#';
	
	while(F<R)
	{
		y = Qy[F], x = Qx[F], F++;
		
		for(i=0;i<6;i++)
			if( y+r[i] < n && y+r[i] > -1 && x+c[i] < n && x+c[i] > -1 && a[y+r[i]][x+c[i]] == 'w' )
			{
				if( x+c[i] == n-1 )
					{
						T = 1 ;	
						return ;
					}
				Qx[R] = x+c[i],	Qy[R] = y+r[i],	R++;
				a[y+r[i]][x+c[i]] = '#' ;
			}
		
	}
	
}

int main()
{
	int j=1,i;

	while(scanf("%d",&n)==1 && n)
	{
		T = 0 ;
		for(i=0;i<n;i++)	
			scanf("%s",a[i]);

		for(i=0;i<n;i++)
			if(a[i][0] == 'w')
				bfs(i,0);
				
		if(T)
			printf("%d W\n",j++);
		else 
			printf("%d B\n",j++);
		
	}

	return 0;
}
