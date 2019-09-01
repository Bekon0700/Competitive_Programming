#include	<stdio.h>
#include	<ctype.h>
#include	<string.h>

int al[26][26],dg[26],Q[26],F,R;
bool tst[26],co[26];

void BFS(int s)
{
	int i,u;
		
	co[s] = false;
	F=R=0;
	Q[R++] = s;
	
	while(F<R)
	{
		u = Q[F++];
		for(i=0;i<dg[u];i++)		
			if(co[al[u][i]])
			{
				co[al[u][i]]=false;
				Q[R++] = al[u][i];
			}
	}
}

int main()
{
	int i,t,j,k,l,A,T;
	char a[80],u,v;
	//freopen("in.txt","r",stdin);
	
	scanf("%d\n",&t);
	
	while(t--)
	{
		memset(co,false,sizeof(tst));
		memset(dg,0,sizeof(dg));
		
		while(gets(a) && a[0] != '*')
		{
			i=0;
			while(!isupper(a[i]))	i++;
			u = a[i];
			i++;
 			while(!isupper(a[i]))	i++;
			v = a[i];
			co[u-65] = true; co[v-65] = true; 
			al[u-65][dg[u-65]++] = v-65;
			al[v-65][dg[v-65]++] = u-65;
		}
		gets(a);
		i=A=T=0;
		while(a[i] != '\0')
		{
			if( isupper(a[i]) )
				if( !co[a[i] - 65])
					A++;
			i++;
		}
		for(i=0;i<26;i++)
			if(co[i])
			{
				T++;
				BFS(i);
			}
		printf("There are %d tree(s) and %d acorn(s).\n",T,A);
	}


	return 0;
}
