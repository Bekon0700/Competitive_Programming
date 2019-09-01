#include<stdio.h>
#include<math.h>

int pos[10000][10],NO;

void MAIN()
{
	int i,m,n,k,j,t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&n,&m);
		k = 0 ;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		for(i=1;i<93;i++)	
			if(pos[i][m]==n)
			{
				k++;
				printf("%2d     ",k);			
				for(j=1;j<9;j++)
					printf(" %d",pos[i][j]);
				printf("\n");
			}
		if(t)
			printf("\n");
	}
	
}

int CC(int k,int cur[],int can[])
{
	int i, c, x ;
	bool f[10] ;
	
	for(i=1; i < 9 ;i++)	
		f[i] = true;
	
	for(i=1; i < k ;i++)	
	{
		f[cur[i]] = false;
		x = k -i;
		if(cur[i] - x > 0)
			f[ cur[i] - x ] = false;
		if(cur[i] + x < 9)
			f[ cur[i] + x ] = false;
	}
	c = 0 ;
	for(i=1; i < 9 ;i++)		
		if( f[i] )
			can[c++] = i;
	return c ;	
}
void BT(int k,int cur[])
{
	int i, candidate;
	if(k==9)
	{
		for(i = 1;i<9;i++)
			pos[NO][i] = cur[i] ;
		NO++;
		return ;
	}		
	else
	{
		int can[10];
		candidate = CC(k,cur,can);
		for(i=0;i < candidate; i++)
		{
			cur[k] = can[i];
			BT(k+1,cur);			
		}
		return ;
	}
}

void GENARET()
{
	int cur[10];
	NO = 1 ;	
	BT(1,cur) ;
}

int main()
{
	GENARET();
	MAIN();

	return 0;
}
