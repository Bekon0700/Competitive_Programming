#include	<iostream>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<map>

#define		PI			2*acos(0)
#define		ERR			1e-10
#define		PAR(a)		a>>1
#define		LEFT(a)		a<<1	
#define		RIGHT(a)	(a<<1)+1
#define		INF			2000000000;

using namespace std;

typedef struct
{
	int u,v,w;	
}V;

V E[40010];

int comp(const void *a,const void *b)
{
	V *x = (V*)a;	
	V *y = (V*)b;	
	return x->u - y->u;
}

int start[210],par[210],heap[40010],hz,tp,n,m,N,M,dis[210],S,T,K,MIN;

void INI()
{
	int i;
	
	for(i=1;i<=n;i++)	
	{
		dis[i] = 0;	
		par[i] = 0;
	}
}

void HINS(int k)
{
	heap[++hz] = k;
	int i = hz ;	
	
	while(i > 1 && dis[heap[PAR(i)]] < dis[heap[i]])
	{
		tp = heap[i];  heap[i]=heap[PAR(i)];  heap[PAR(i)] = tp;	
		i = PAR(i);
	}
}

void MHFY(int k)
{
	int l,r,m;

	while(true)	
	{
		l = LEFT(k);	
		r = RIGHT(k);	
		m = k; 
		if( l <= hz && dis[heap[l]] > dis[heap[m]] )	m = l;
		if( r <= hz && dis[heap[r]] > dis[heap[m]] )	m = r;
		if( m == k )	return ;
		tp = heap[k];   heap[k] = heap[m]; heap[m] = tp;
		k=m;
	}
}

int EMX()
{
	int m,i;	

	m = heap[1];
	heap[1]= heap[hz--];
	MHFY(1);
	return m;
}

void MAK(int i)
{
	while( i > 1 && dis[heap[PAR(i)]] < dis[heap[i]] )
	{
		tp = heap[i];  heap[i]=heap[PAR(i)];  heap[PAR(i)] = tp;	
		i = PAR(i);
	}
	
}

int SCH(int x)
{
	int i;  
	
	for(i=1;i <= hz;i++)
		if( x == heap[i] )
			return i;
	
	return 0;
}

void PRIMS()
{
	int u,v,i,x;
	dis[S] = INF;
	hz = 0 ;
	
	for(i=1;i<=n;i++)
		 HINS(i);
	
	while(hz)
	{
		u = EMX();

		for(i=start[u]; i<K && E[i].u == u; i++)		
		{
			if( E[i].w > dis[E[i].v] )
			{
				x = SCH(E[i].v);
				if(x)
				{
					dis[ E[i].v ] = E[i].w;
					par[ E[i].v ] = E[i].u;
					MAK(x);
				}
			}
		}
	}
}

void BFS()
{
	int t=T;
	while(t != S)
	{
		if(dis[t] < MIN)	
			MIN = dis[t];
		t = par[t];
	}
}

int main()
{
	int i,j,k,t=1,w,u,v;
	char s1[203],s2[203];
	map<string,int>MP;


	while(scanf("%d%d",&n,&m)==2 && (n||m))
	{
		MP.clear();
		N=n+1;
		INI();	
		k=1;K=0;
		for(i=0;i<m;i++)
		{
			scanf("%s %s %d",s1,s2,&w);
			if(!MP[s1])		
				MP[s1]= k++;
			if(!MP[s2])		
				MP[s2]= k++;
			u = MP[s1];			v = MP[s2];

			E[K].u =u;   E[K].v=v;   E[K].w = w;  K++;
			E[K].u =v;   E[K].v=u;   E[K].w = w;  K++;
		}
		scanf("%s%s",s1,s2);
		S = MP[s1];   T = MP[s2];
		
		qsort(E,K,sizeof(V),comp);
		
		for(i=0,j=1;i<K;i++)
			if(E[i].u == j)
				start[j++] = i;
		PRIMS();
		MIN = INF;	
			
		
		
		BFS();	
		printf("Scenario #%d\n%d tons\n\n",t++,MIN);
	}
	
	return 0;
}
