#include<stdio.h>

int X[10001],Y[10001],F,R,x,y;
char a[102][102],C='*';
int rr[]={-1,-1,-1,0,0,1,1,1};
int cc[]={-1,0,1,-1,1,-1,0,1}; 	

int BFS(int r,int c)
{
	int i,count;
	
	a[r][c] = '.';	
	count = F= R =0;
	X[R] = c;
	Y[R ++ ] = r;
	
	while(F<R)
	{
		c = X[F];	
		r = Y[F++];
		count ++;
		for(i=0;i<8;i++)
			if(r+rr[i]>-1 && r+rr[i]<y && c+cc[i] >-1 && c+cc[i] < x && a[r+rr[i]][c+cc[i]] == C)
			{
				X[R] = c+cc[i];
				Y[R ++ ] = r+rr[i];	
				a[r+rr[i]][c+cc[i]] = '.';
				
			}
	}
	return count;
}

int main()
{
	int i,j,k,l,t,cot;	
	
	while(scanf("%d%d",&y,&x)==2 && (x||y))
	{
		for(i=0;i<y;i++)
			scanf("%s",a[i]);
		cot = 0;
		for(i=k=0;i<y;i++)
			for(j=0;j<x;j++)
				if(a[i][j]=='*')
					if( BFS(i,j) == 1)	
						cot++;
					
		printf("%d\n",cot);
	}
	return 0;
}
