#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;
#define sz 1000100

vector<int>V[sz];
int N,n,m,id[sz],Q[sz],F,R; 

void ST()
{
	int i,u;

	F=R=0;
	for(i=1;i<=n;i++)
		if(!id[i])
			Q[R++] = i;
	
	while(F<R)
	{
		u = Q[F++];
		
		for(i=0;i<V[u].size();i++)
		{
			id[ V[u][i] ] -- ;
			
			if(!id[V[u][i]])
				Q[R++] = V[u][i];
		}
	}

	if(R<n)
		printf("IMPOSSIBLE\n");
	else
	{
		for(i=0;i<R;i++)
			printf("%d\n",Q[i]);
	}
}

int main()
{
	int i,u,v;
	
	while(scanf("%d%d",&n,&m)==2 && (n||m))
	{
		for(i=1;i<=n;i++)
			V[i].clear();

		memset(id,0,sizeof(int)*(n+2));

		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			V[u].push_back(v);
			id[v]++;
		}
		ST();
	}
	return 0;
}