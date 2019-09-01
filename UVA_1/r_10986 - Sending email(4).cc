#include	<stdio.h>
#include	<stdlib.h>

#define		left(a)		(a<<1)
#define		right(a)	((a<<1)+1)
#define		par(a)		(a>>1)
#define		inf			2147483647

typedef struct
{
	int u,v,w;
}Var;

Var nod[100010]; 
int start[50010],dis[50010],hsize,vv,n,h[50010],temp; 

void INITIALISE(int x)
{
	for(int i=0;i<n;i++)	dis[i] = inf;
	dis[x] = 0;
}

int comp(const void *a,const void *b)
{
	Var *x = (Var*) a;	
	Var *y = (Var*) b;	
	return x->u - y->u;
}

void HEAP_INCREASE_KEY(int k)
{
	int i;
	
	i = hsize ;
	h[i] = k;
	
	while(i > 1 && dis[ h[par(i)] ] > dis[ h[i] ]) 	
	{
		temp = h[par(i)] ;	h[par(i)] = h[i] ;  h[i] = temp ;
		i = par(i);		
	}
}
void HEAP_INSURT(int s)
{
	hsize ++;
	HEAP_INCREASE_KEY(s);	
}

void MIN_HEAPIFY(int i)
{
	int l,r,min;
	l = left(i)	;
	r = right(i) ;
	if(l <= hsize && dis[ h[l] ] < dis[ h[i] ])
		min = l;
	else 
		min = i;
	if(r <= hsize && dis[ h[r] ] < dis[ h[min] ])
		min = r;
	if(min != i)
	{
		temp = h[min]; h[min] = h[i] ; h[i] = temp ;
		MIN_HEAPIFY(min);		
	}
}

int HEAP_EXTRACT_MIN()
{
	int i,j,k,min;
	min = h[1];
	
	h[1] = h[hsize];
	hsize --;
	
	MIN_HEAPIFY(1);
	
	return min;
}

void DIJKSTRA(int x,int m,int t)
{
	int i,j,k,l,u,v,w,min;
	
	hsize = 0;
	
	HEAP_INSURT(x); 
	
	while(hsize)
	{
		u = HEAP_EXTRACT_MIN();		
		if(u == t) return ;
		for(i = start[u] ; i < m ; i ++)
		{
			if(nod[i].u != u)	break;
			if( dis[nod[i].v] > dis[u] + nod[i].w )
			{
				dis[nod[i].v] = dis[u ] + nod[i].w ;
				HEAP_INSURT(nod[i].v); 
			}
		}
	}
}


int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,u,v,w,t=1,N,m,S,T;

	scanf("%d",&N);	
	
	while(N--)
	{
		scanf("%d%d%d%d",&n,&m,&S,&T);	
		INITIALISE(S);
		k = 0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			nod[k].u = u ; 	nod[k].v = v ;	nod[k].w = w; 	k++;	
			nod[k].u = v ; 	nod[k].v = u ;	nod[k].w = w; 	k++;	
		}
		qsort(nod,k,sizeof(Var),comp);	
		
		for(i=0,j=0,vv=k; i < k ;i++)
			if(nod[i].u == j)
			{
				start[j]=i;	
				j ++ ;
			}
		
		DIJKSTRA( S,k,T);
		
		if(dis[T] != inf )
			printf("Case #%d: %d\n",t,dis[T]);
		else
			printf("Case #%d: unreachable\n",t);
		t++;
	}
	
	return 0;
}
