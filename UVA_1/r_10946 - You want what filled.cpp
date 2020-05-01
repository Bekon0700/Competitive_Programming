#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


typedef struct{ int s;char c;}I;

I itm[2511];
int X[25001],Y[25001],F,R,x,y;
char a[52][52],C;
int rr[]={-1,0,-1,0};
int cc[]={0,1,0,-1}; 	


int comp(const void *a,const void *b)
{
	I *x = (I*) a;	
	I *y = (I*) b;	
	
	if( x-> s != y-> s)
		return y->s - x->s; 
	else return x->c - y->c; 
}

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
	int i,j,k,l,t,T=1;	
	
	while(scanf("%d%d",&y,&x)==2 && (x||y))
	{
		for(i=0;i<y;i++)
			scanf("%s",a[i]);
		for(i=k=0;i<y;i++)
			for(j=0;j<x;j++)
				if(isalpha(a[i][j]))
				{
					itm[k].c = C = a[i][j];
					itm[k++].s = BFS(i,j);	
					
				}

		qsort(itm,k,sizeof(I),comp);		
		printf("Problem %d:\n",T++);
		for(i=0;i<k;i++)
			printf("%c %d\n",itm[i].c,itm[i].s);
	}
	return 0;
}
