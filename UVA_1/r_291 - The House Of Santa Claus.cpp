#include<stdio.h>

int  test[11],adj[7][7], z = 48;
void BACKTRACK(int k,char a[],int u);

int main()
{
	int i,j,k;
	char a[11];
	a[9]='\0';
	a[0]='1';
	adj[1][2] = 1 ;adj[1][3] = 1 ;adj[1][5] = 1 ;
	adj[2][1] = 1 ;adj[2][3] = 1 ;adj[2][5] = 1 ;
	adj[3][1] = 1 ;adj[3][2] = 1 ;adj[3][4] = 1 ;adj[3][5] = 1 ;
	adj[5][1] = 1 ;adj[5][2] = 1 ;adj[5][3] = 1 ;adj[5][4] = 1 ;
	adj[4][3] = 1 ;adj[4][5] = 1 ;
	
	adj[1][2]=adj[2][1]=0; BACKTRACK(1,a,2); adj[1][2]=adj[2][1]=1;
	adj[1][3]=adj[3][1]=0; BACKTRACK(1,a,3); adj[1][3]=adj[3][1]=1;	
	adj[1][5]=adj[5][1]=0; BACKTRACK(1,a,5); 			
	
	return 0;
}

void BACKTRACK(int k,char a[],int u)
{
	int i,j;

	a[k] = u + z;

	if(k==8)	
	{
		printf("%s\n",a);
		return ;
	}
	else
	{
		for(i=1;i<6;i++)	
			if(adj[u][i])
			{
				adj[u][i] = adj[i][u] = 0; 	
				BACKTRACK(k+1,a,i);
				adj[u][i] = adj[i][u] = 1; 	
			}
	}
}
