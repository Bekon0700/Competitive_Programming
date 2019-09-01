#include	<stdio.h>

#define INF 20000000
#define  P(a)	a>>1
#define  L(a)	a<<1
#define  R(a)	(a<<1)+1

int mat[12][12],par[12],dis[12],heap[1200],hs,tp,s,t,pr[12];
bool tst[12] ;

void ini(int n)
{
	int i,j;

	for(i=1;i<n;i++)	
	{
		for(j=1;j<n;j++)		
			mat[i][j] = INF;
		par[i] = dis[i] = INF;
		mat[i][i] = 0;
		tst[i] = true;
	}
}


void HINS(int k)
{
	heap[++hs] = k;
	int i = hs;

	while(i > 0 && dis[ heap[P(i)] ] > dis[ heap[i] ])	
	{
		tp = heap[P(i)];  heap[P(i)] = heap[i];  heap[i] = tp;
		i = P(i);		
	}
}

void HFY()
{
	int l,r,m,k=1;	
	
	while(true)
	{
		l = L(k);	r = R(k);	m=k;
		
		if(l<=hs && dis[heap[l]] < dis[heap[m]])
			m = l;
		if(r<=hs && dis[heap[r]] < dis[heap[m]])
			m = r;
		if(m==k)
			return ;
		tp = heap[m]; heap[m] = heap[k]; heap[k] = tp;
		k = m;
	}
}

int EM()
{
	int m;
	
	m = heap[1];
	heap[1] = heap[hs--];
	HFY();	
	return m;
}


void DIJKSTRA(int n)
{
	int i,u;
	hs = 0;
	dis[s] = 0;
	HINS(s);
	while(hs)
	{
		u = EM();

		for(i=1;i<n;i++)
		{
			
			if(dis[i] > dis[u] + mat[u][i])
			{
				par[i]	= u;
				dis[i] = dis[u] + mat[u][i];
				HINS(i);

			}
		}
	}
	
	tp = 0;
	i = t;
	while(i != INF)
	{
		pr[++tp] = i;	
		i = par[i] ;
	}
	if(s==t)  printf(" %d",s);  
 	while(tp)
		printf(" %d",pr[tp--]);
}






int main()
{
	int i,j,k=1,n,m,u,v,w;
	
	while(scanf("%d",&n)==1 && n)
	{
		ini(n+1);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&m);	
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&v,&w);	
				mat[j][v] = w;
				
			}
			
		}
		scanf("%d%d",&s,&t);
		printf("Case %d: Path =",k++);
		DIJKSTRA(n+1);
		printf("; %d second delay\n",dis[t]);
	}		

	return 0;
}
