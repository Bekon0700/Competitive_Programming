#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

typedef struct
{
	int u,v;
}VR;

VR nod[10005];

int comp(const void *a,const void *b)
{
	VR *x = (VR*)a;
	VR *y = (VR*)b;
	return x->u - y->u;
}

int start[102],dis[102],m,K,V,nods[102];
bool T[102];

void BFS(int s)
{
	int u,v,i,j;
	queue <int> Q;
	
	for(i=0;i<V;i++)
		T[nods[i]] = true;	
	T[s]=false;
	Q.push(s); 
	dis[s] = 0;
	while(!Q.empty())	
	{
		u=Q.front();	
		Q.pop();
		for(i=start[u];nod[i].u == u && i<K;i++)
			if(T[nod[i].v])
			{
				dis[nod[i].v] = dis[u]+1;
				T[nod[i].v] = false;
				Q.push(nod[i].v);				
			}
	}
}


int main()
{
	int i,j,k,u,v,t=1;
	bool flag[104];
	double x;
	
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&u,&v)==2 && (u||v) )
	{
		for(i=1;i<101;i++)
			flag[i] = false;
		nod[0].u=u;	nod[0].v=v;
		i=1;
		x=0;
		m=u;
		flag[u] = true;
		while(scanf("%d%d",&u,&v)==2 && (u||v))
		{
			nod[i].u =u; nod[i].v = v; i++;	
			flag[u] = true;
		}
		
		K = i;
		//printf("\tK:%d\n",K);
		qsort(nod,K,sizeof(VR),comp);
		
		for(i=1,V=0;i<101;i++)
			if(flag[i])
			{
				nods[V++] = i; 	
				//printf("\t\t%d\n",i);
			}
		//printf("\tV:%d\n",V);
			
		for(i=j=0;j<V;i++)
			if(nod[i].u == nods[j])
			{
				start[nods[j]] = i;
				//printf("j:%d %d\n",nods[j],start[nods[j]]);
				j++;				
			}
		//for(i=0;i<K;i++)	printf("\t\t%d %d\n",nod[i].u,nod[i].v);	
		
		for(i=0;i<V;i++)
		{
			BFS(nods[i]);	
			for(j=0;j<V;j++)
				x += dis[nods[j]];
			//printf("\tX:%lf\n",x);
		}
		
		k = V * (V-1);
		//printf("\tk:%d\n",k);
		x /= k;	
		printf("Case %d: average length between pages = %.3lf clicks\n",t++,x);	
	}

	return 0;
}
