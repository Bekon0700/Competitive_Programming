#include<stdio.h>
#include<string.h>

char a[33][33][33];
int dis[33][33][33];
int X[28000],Y[28000],Z[28000],F,R,l,c,r;
int xx[]={1,-1,0,0,0,0};
int yy[]={0,0,1,-1,0,0};
int zz[]={0,0,0,0,1,-1};	


int BFS(int z,int y,int x)
{
	int i,j,k;	
	
	memset(dis,0,sizeof(dis));

	F = R = 0 ;
	a[z][y][x] = '#';

	dis[z][y][x] = 0 ;

	X[R] = x;
	Y[R] = y;
	Z[R] = z;
	R++;
	
	while(F<R)
	{
		x = X[F];	
		y = Y[F];	
		z = Z[F];
		F++;
		
		for(i=0;i<6;i++)
			if( z+zz[i] < l && x+xx[i] < c && y+yy[i]<r && z+zz[i] >-1 && x+xx[i] >-1 && y+yy[i]>-1)
				if(a[z+zz[i]][y+yy[i]][x+xx[i]] != '#')
				{
					X[R] = x+xx[i];
					Y[R] = y+yy[i];
					Z[R] = z+zz[i];
					R++;
					dis[z+zz[i]][y+yy[i]][x+xx[i]] = dis[z][y][x] + 1 ;
					if( a[z+zz[i]][y+yy[i]][x+xx[i]] == 'E' )
						return dis[z+zz[i]][y+yy[i]][x+xx[i]];
					a[z+zz[i]][y+yy[i]][x+xx[i]] = '#';	
				}
	}

	return 0;
}

int main()
{
	int i,j,k,d;	
	
	while(scanf("%d%d%d",&l,&r,&c)==3 && (l||r||c))
	{
		
		for(i=0;i<l;i++)	
			for(j=0;j<r;j++)
				scanf("%s",a[i][j]);
		d=0;	
		for(i=0;i<l;i++)
			for(j=0;j<r;j++)
				for(k=0;k<c;k++)
					if(a[i][j][k] == 'S')
					{
						d = BFS(i,j,k);	
						break;
					}
					
		if(d)
			printf("Escaped in %d minute(s).\n",d);
		else
			printf("Trapped!\n");
	}

	return 0;
}
