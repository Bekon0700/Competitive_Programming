#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

typedef struct{	int u,v,c;bool a;}E;
int n,m,N,p[101],r[101],c1,c2,mark[101],mk;
E e[10000];


int comp(const void *a,const void *b)
{
	E *x = (E*) a;
	E *y = (E*) b;
	return x->c - y->c;
}


int FS(int x)
{
	if(p[x] != x)
		p[x] = FS(p[x]);
	return p[x];
}


void U(int u,int v)
{
	if(r[u]>r[v])
		p[v] = u;
	else 
	{
		p[u] = v;
		if(r[u] == r[v])
			r[v]++;
	}
}


void MST()
{
	int i,x,y,j,cur,k;

	mk=0;
	for(i=0;i<m;i++)
		e[i].a = true;
	c1=0;
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++)		p[i] = i;
	
	for(i=0;i<m;i++)
	{
		x = FS(e[i].u);	
		y = FS(e[i].v);	
		if(x != y)
		{
			c1 += e[i].c; 
			U(x,y);
			mark[mk++] = i;

		}
	}

	
	c2=200000000;

	for(j=0;j<mk;j++)
	{
		
		memset(r,0,sizeof(r));
		for(i=1;i<=n;i++)	p[i] = i;

		e[mark[j]].a = false;		
		
		cur = 0;
		for(i=k=0;i<m;i++)
		if(e[i].a)	
		{
			x = FS(e[i].u);	
			y = FS(e[i].v);	
			if(x != y)
			{
				cur += e[i].c; 
				k++;
				U(x,y);
			}
		}
		if(c2 > cur && k == n-1)
			c2 = cur;
		e[mark[j]].a = true;		
	}
}

int main()
{
	int T,i;
	

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d%d",&n,&m);

		for(i=0;i<m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
		qsort(e,m,sizeof(E),comp);
		MST();
		
		printf("%d %d\n",c1,c2);
	}
	return 0;
}