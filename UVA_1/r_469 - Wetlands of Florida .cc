#include	<stdio.h>

using namespace std;

int N,M,g;
char a[120][120];
bool t[120][120];

void DFS(int u,int v)
{
	g ++ ;
	t[u][v] = false;
	
	if(u > 0 && v > 0 && a[u-1][v-1] == 'W' && t[u-1][v-1])	
		DFS(u-1,v-1);		
	
	if(u > 0  && a[u-1][v] == 'W' && t[u-1][v])	
		DFS(u-1,v);		
	
	if(u > 0 && v < M  && a[u-1][v+1] == 'W' && t[u-1][v+1])	
		DFS(u-1,v+1);		
	
	if( v > 0 && a[u][v-1] == 'W' && t[u][v-1])	
		DFS(u,v-1);		
	
	if( v < M && a[u][v+1] == 'W' && t[u][v+1])	
		DFS(u,v+1);		
	
	if(u < N && v > 0 && a[u+1][v-1] == 'W' && t[u+1][v-1])	
		DFS(u+1,v-1);		
	
	if(u < N && a[u+1][v] == 'W' && t[u+1][v])	
		DFS(u+1,v);		
	
	if(u < N  && v < M && a[u+1][v+1] == 'W' && t[u+1][v+1])	
		DFS(u+1,v+1);		
}

void PRO(int U,int V)
{
	int i,j;
	g=0;
	
	if(a[U][V] == 'W')
	{
		for(i=0;i<102;i++)
			for(j=0;j<102;j++)
				t[i][j]=true;
	
		DFS(U,V);
	}
	printf("%d\n",g);
}

void str(char s[],int j)
{
	int i=0,x=0,y=0,k;

	i=0;	
	while(s[i] != ' ')
	{
		x *= 10 ;
		x += (s[i] - '0');		
		i++;
	}
	i++;
	while(i < j )
	{
		y *= 10 ;
		y += (s[i] - '0');		
		i++;
	}
	
	PRO(x-1,y-1);
}

int main()
{
	int i,j,tt,T,test;
	
	scanf("%d\n",&T);
	test=T;

	for(tt=0,i=0,j=0;tt<T;tt++)
	{
		while(scanf("%c",&a[i][j]) == 1 )
		{
			if(a[i][j] == '\n')
			{
				if(a[i][0] == '\n')
				{
					i = 0;
					j = 0;
					break;	
				}
				else 
				{
					if(a[i][0]=='W' || a[i][0]=='L')
					{
						N = i;
						M = j - 1 ;
						j = 0;
						i++;	
						
					}
					else
					{
						str(a[i],j);	
						j = 0;
						i = 103;
					}
				}
				
			}
			else
				j++;
		}
		if(--test)
			printf("\n");
	}

	return 0;
}
