#include	<stdio.h>
#include	<stdlib.h>
#include	<vector>

#define INF 20000000
#define Par(a) a>>1
#define Left(a) a<<1
#define Right(a) (a<<1)+1

typedef struct 
{
	int u,v,w; 
}NOD;

NOD nod[20010];

int cost[101],heap[20050],hsize,tp,start[103],K,par[103];
bool col[102];

int comp(const void *a,const void *b)
{
	NOD *x = (NOD *) a;
	NOD *y = (NOD *) b;
	return x->u - y->u;
}

void HINS(int k)
{
	int i;
	heap[++hsize] = k;
	i = hsize;
	
	while( i>1 && cost[heap[Par(i)]] < cost[heap[i]] )
	{
		tp = heap[Par(i)]; heap[Par(i)] = heap[i]; heap[i] = tp;
		i = Par(i);
	}
}

void HFY(int k)
{
	int l,r,m;

	while(true)	
	{
		l = Left(k);	r = Right(k);		m = k;
		if(l <= hsize && cost[heap[l]] > cost[heap[m]])
			m = l;
		if(r<=hsize && cost[heap[r]] > cost[heap[m]])
			m = r;
		if(m == k)	return;
			
		tp = heap[m];	heap[m] = heap[k];	heap[k] = tp;
		k = m;
	}
}

int EMAX()
{
	int m,i;
	m = heap[1]	;
	heap[1] = heap[hsize -- ];
	HFY(1);
	
	return m;	
}

void INI(int n)
{
	int i;
	hsize  = 0;
	cost[0] = INF;
	col[0] = true;
	HINS(0);
	for(i=1;i<n;i++)
	{
		cost[i] = -1;	
		col[i] = true;
		HINS(i);
	}
}

int PRIMS(int n)
{
	int i,j,k,u,v,m=INF,x;	
	
	while(hsize)	
	{
		u = EMAX();
		if(col[u])
		{
			col[u] = false;	
			for(i = start[u]; i<K && nod[i].u == u ;i++)
				if(col[nod[i].v] && nod[i].w > cost[nod[i].v] )
				{
					cost[ nod[i].v ] = nod[i].w;	
					HINS(nod[i].v);
				}
			
		}
	}
	for(i=0;i<n;i++)
	{
		if(m>cost[i])
			m = cost[i];
	}
	return m;
}


int main()
{
	int i,j,n,m,x,max,t=1,T,u,v,w,k;
	
	//freopen("in.txt","r",stdin);	
	
	scanf("%d",&T);
	T++;
	for(t=1;t<T;t++)
	{
		scanf("%d%d",&n,&m);
		INI(n);
		for(i=K=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if(u==v)  continue;				
			nod[K].u = u;	nod[K].v = v;	nod[K].w = w;   K++;
			nod[K].u = v;	nod[K].v = u;	nod[K].w = w;   K++;
		}
		qsort(nod,K,sizeof(NOD),comp);	

		for(i=0,j=0;i<K;i++)
		{	
			if(nod[i].u == j)
			{
				start[j] = i;	
				j++;
			}
		}
		max = PRIMS(n);
		printf("Case #%d: %d\n",t,max);
	}

	return 0;
}
