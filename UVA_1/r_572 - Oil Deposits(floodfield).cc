#include<stdio.h>
#include<string.h>

int n,m,c,Q[10020][2],F,R;
char adj[102][102];

int main()
{
	int i,j,ui,uj,v,k,l,p,q,N,M,w,f; 

	while(scanf("%d%d",&m,&n)==2 && m)
	{
		for(i=0;i<m;i++)
			scanf("%s",adj[i]);
		
		c = 0;
		w=f=0;
		N = n-1;
		M = m-1;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(adj[i][j] == '@')
				{
					c ++ ;
					F = R = 0;
					Q[++R][0] = i ;
					Q[R][1] = j ;
					w = 0 ;
					while(F <  R)
					{
						
						ui = Q[++F][0];
						uj = Q[F][1];
						adj[ui][uj] = '*';
						
						if( ui > 0 && uj > 0)
						if(adj[ui-1][uj-1] == '@')
						{
							Q[++R][0] = ui-1 ;
							Q[R][1] = uj-1 ;
							
						}
						if( ui > 0)
						if(adj[ui-1][uj] == '@' )
						{
							Q[++R][0] = ui -1 ;
							Q[R][1] = uj ;
							
						}
						if( ui>0 && uj < N )
						if(adj[ui-1][uj+1] == '@' )
						{
							Q[++R][0] = ui-1 ;
							Q[R][1] = uj+1 ;
							
						}
						if(  uj > 0)
						if(adj[ui][ uj - 1 ] == '@')
						{
							Q[++R][0] = ui ;
							Q[R][1] = uj-1 ;
							
						}
						if( uj < N)
						if(adj[ui][uj+1] == '@' )
						{
							Q[++R][0] = ui ;
							Q[R][1] = uj +1 ;
							
							
						}
						if( ui < M && uj > 0 )
						if(adj[ui+1][uj-1] == '@' )
						{
							Q[++R][0] = ui + 1;
							Q[R][1] = uj - 1;
							
						}
						if( ui < M)
						if(adj[ui+1][uj] == '@' )
						{
							Q[++R][0] = ui + 1 ;
							Q[R][1] = uj ;
							
						}
						if( ui<M && uj< N)
						if(adj[ui+1][uj+1] == '@' )
						{
							Q[++R][0] = ui +1;
							Q[R][1] = uj +1;
							
						}
						
					}
					
				}
		printf("%d\n",c);
	}
	return 0;
}
