#include<stdio.h>
#include<math.h>

int pos[100][10],NO;

void MAIN()
{
	int i,j,x,t,max,input[10][10];
	
	scanf("%d",&t);
	while(t--)
	{	
		for(i=1;i<9;i++)
			for(j=1;j<9;j++)
				scanf("%d",&input[i][j]);
		i = 1 ;
		max = input[1][pos[i][1]] +input[2][pos[i][2]] +input[3][pos[i][3]] +input[4][pos[i][4]] +input[5][pos[i][5]] +input[6][pos[i][6]] + input[7][pos[i][7]] +input[8][pos[i][8]]  ;	 ;
			for(i=2;i<93;i++)
			{
				x = input[1][pos[i][1]] +input[2][pos[i][2]] +input[3][pos[i][3]] +input[4][pos[i][4]] +input[5][pos[i][5]] +input[6][pos[i][6]] + input[7][pos[i][7]] +input[8][pos[i][8]]  ;	
				if(x>max)
					max = x;
			}
		printf("%5d\n",max);
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
