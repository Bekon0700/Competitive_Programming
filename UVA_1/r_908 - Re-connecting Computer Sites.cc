#include	<stdio.h>
#include	<stdlib.h>


typedef struct{
	int u,v,w;
}NOD;

NOD nod[1001000];
int rank[1001000],par[1001000],N,S;

int comp(const void *a,const void *b)
{
	NOD *x = (NOD*)a;
	NOD *y = (NOD*)b;
	return x->w - y->w;
}

void MS()
{
	int i;
	for(i=1;i<N;i++)
	{
		rank[i] = 0;
		par[i] = i;
	}
}

int FSET(int x)
{
	if(x!= par[x])
		par[x] = FSET(par[x]);
	return par[x] ;
}

void U(int x,int y)
{
	if(rank[x] > rank [y])
		par[y] = x;
	else{
		par[x] = y;
		if(rank[x] == rank[y])
			rank[y] ++ ;
	}
}
void LINK(int x,int y)
{
	U(FSET(x),FSET(y));
}

int KRUSKEL()
{
	long long m=0;
	int i,j,k,u;
	
	for(i=0;i<S;i++)
		if(FSET(nod[i].u) != FSET(nod[i].v))
		{
			m += nod[i].w;
			LINK(nod[i].u,nod[i].v);			
		}
	return m;
}

int main()
{
	int i,j,k,t=0,u,v,w,m,n;
	long long a,b;
	NOD K[12];
	
	while(scanf("%d",&n)==1)
	{
		if(t++)
			printf("\n");
		N = n+1;
		MS();
		
		for(i=1;i<n;i++)
			scanf("%d%d%d",&u,&v,&w);
		
		scanf("%d",&k);	

		for(i=0;i<k;i++)
			scanf("%d%d%d",&K[i].u,&K[i].v,&K[i].w);

		scanf("%d",&m);	

		for(i=0;i<m;i++)
			scanf("%d%d%d",&nod[i].u,&nod[i].v,&nod[i].w);

		S = m;
		qsort(nod,S,sizeof(NOD),comp);
		
		a = KRUSKEL();
		for(i=0;i<k;i++,S++)
		{
			nod[S].u=K[i].u;
			nod[S].v=K[i].v;
			nod[S].w=K[i].w;
		}
		qsort(nod,S,sizeof(NOD),comp);
		
		MS();
		b= KRUSKEL();
		printf("%lld\n%lld\n",a,b);
	}
	return 0;
}
