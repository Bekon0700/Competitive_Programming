#include<stdio.h>

char a[27][27],Qx[100],Qy[100],N;

void BFS(int Y,int X)
{
	int i,j,k,F=0,R=0,x,y;

	a[Y][X] = '0';
	Qy[R]=Y;
	Qx[R]=X;
	R++;
	while(F<R)
	{
		y = Qy[F];	x = Qx[F];   F++;
		
		if(y>0 && x>0  && a[y-1][x-1] == '1')
		{
			a[y-1][x-1] = '0';	
			Qy[R]= y-1;	  Qx[R] = x-1 ;   R++;
		}
		if(y>0 && a[y-1][x] == '1')
		{
			a[y-1][x] = '0';	
			Qy[R]= y-1;	  Qx[R] = x ;   R++;
		}					
		if(y>0 && x < N && a[y-1][x+1] == '1')
		{
			a[y-1][x+1] = '0';	
			Qy[R]= y-1;	  Qx[R] = x+1 ;   R++;
		}					
		if(x>0 && a[y][x-1] == '1')
		{
			a[y][x-1] = '0';	
			Qy[R]= y;	  Qx[R] = x-1 ;   R++;
		}					
		if(x<N && a[y][x+1] == '1')
		{
			a[y][x+1] = '0';	
			Qy[R]= y;	  Qx[R] = x+1 ;   R++;
		}					
		if(y<N && x>0 && a[y+1][x-1] == '1')
		{
			a[y+1][x-1] = '0';	
			Qy[R]= y+1;	  Qx[R] = x-1 ;   R++;
		}					
		if(y<N && a[y+1][x] == '1')
		{
			a[y+1][x] = '0';	
			Qy[R]= y+1;	  Qx[R] = x ;   R++;
		}					
		if(y<N && x<N && a[y+1][x+1] == '1')
		{
			a[y+1][x+1] = '0';	
			Qy[R]= y+1;	  Qx[R] = x+1 ;   R++;
		}					
		
	}
}


int main()
{
	int i,j,k,n,t=1;
	
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)	
			scanf("%s",a[i]);
		k=0;
		N = n-1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][j] == '1')
				{
					BFS(i,j);
					k++;
				}
		printf("Image number %d contains %d war eagles.\n",t++,k);
	}

	return 0;
}
