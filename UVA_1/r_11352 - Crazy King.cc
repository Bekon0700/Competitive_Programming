#include<stdio.h>
#include<string.h>

char bo[103][103];
int a[]={-1,-2,-2,-1,1,2,2,1},I[]={-1,-1,-1,0,0,1,1,1},Qy[10002],Qx[10001],F,R,n,m;
int b[]={2,1,-1,-2,-2,-1,1,2},J[]={-1,0,1,-1,1,-1,0,1},val[103][103];

int bfs(int y,int x)
{
	int i;
	F = R = 0 ;
	Qy[R] = y;
	Qx[R++] = x;
	bo[y][x] = 'X';
	
	memset(val,0,sizeof(val));
	
	while(F<R)
	{
		y = Qy[F];
		x = Qx[F++];

		for(i=0;i<8;i++)	
			if(y+I[i]<m && y+I[i]>-1 && x+J[i]<n && x+J[i]>-1 && bo[y+I[i]][x+J[i]] != 'X')
			{
				val[y+I[i]][x+J[i]] = val[y][x] + 1 ;
				if(bo[y+I[i]][x+J[i]] == 'B')
					return val[y+I[i]][x+J[i]];
				bo[y+I[i]][x+J[i]] = 'X';
				Qx[R] = x+J[i];
				Qy[R] = y+I[i];
				R++;
			}
		
	}
	
	return 0;
}

int main()
{
	int i,j,t,k,d,y,x;
	
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&m,&n);
		
		for(i=0;i<m;i++)
			scanf("%s",bo[i]);
		
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(bo[i][j] == 'Z')
				{
					bo[i][j] = 'X';
					for(k=0;k<8;k++)
						if(i+a[k] > -1 && i+a[k]<m && j+b[k]>-1 && j+b[k]<n )
							if( bo[i+a[k]][j+b[k]] == '.' )
								bo[i+a[k]][j+b[k]] = 'X';
				}
				else if(bo[i][j] == 'A')
				{
					x = j;
					y = i;					
				}
		d=bfs(y,x);
		if(d)		
			printf("Minimal possible length of a trip is %d\n",d);
		else 
			printf("King Peter, you can't go now!\n");
		
	}
	return 0;
}
