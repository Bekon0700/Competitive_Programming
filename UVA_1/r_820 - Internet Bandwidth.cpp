#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#define INF 2000000
#define size 105

int mat[size][size],p[size],s,t,N,fm,Q[size],F,R;
bool tst[size];

bool AUG_PATH()
{
	int i,u;

	memset(tst,true,sizeof(bool)*N);
	memset(p,0,sizeof(int)*(N+2));

	F=R=0;
	Q[R++]=s;
	tst[s] = false;

	while(F<R)
	{
		u = Q[F++];
		for(i=1;i<N;i++)
			if(tst[i] && mat[u][i])
			{
				p[i] = u;
				tst[i] = false;
				Q[R++] = i;
				if(i==t)
					return true;
			}
	}

	return false;
}

void MAKE_RES(int u)
{
	if(!p[u])	return ;

	if(mat[p[u]][u]<fm)	fm = mat[p[u]][u];

	MAKE_RES(p[u]);
	mat[p[u]][u] -= fm;
	mat[u][p[u]] += fm;
}



int FORDFULKERSON()
{
	int mflow=0;

	while(AUG_PATH())
	{
		fm=INF;
		MAKE_RES(t);
		mflow += fm;
	}
	return mflow;
}


int main()
{
	int i,m,T=1,n,j,u,v,c;

	while(scanf("%d",&n)==1 && n)
	{
		N=n+1;
		scanf("%d%d%d",&s,&t,&m);

		for(i=1;i<N;i++)
			memset(mat[i],0,sizeof(int)*N);

		while(m--)
		{
			scanf("%d%d%d",&u,&v,&c);
			mat[u][v] += c;
			mat[v][u] += c;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",T++,FORDFULKERSON());
	}

	return 0;
}



