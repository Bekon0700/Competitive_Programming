#include	<stdio.h>
#include	<string.h>

char bo[9][9];
int t=1;

void f(bool x)
{
	if(x)
		printf("Game #%d: black king is in check.\n",t++);	
	else
		printf("Game #%d: white king is in check.\n",t++);
}

bool process(char k,int x,int y)
{
	if(k=='K')
	{
		if(bo[y-1][x-1]=='p' && x > 0 && y > 0)	
		{
			f(false);	
			return true;
		}			
		else if(bo[y-1][x+1]=='p' && x < 7 && y >0)	
		{
			f(false);	
			return true;
		}
		else if(bo[y-1][x+2]=='n' && x < 6 && y > 0)	
		{
			f(false);	
			return true;
		}
		else if(bo[y + 1][x+2]=='n' && x < 6 && y <7)	
		{
			f(false);	
			return true;
		}
		else if(bo[y-2][x+1]=='n' && x < 7 && y > 1 )	
		{
			f(false);	
			return true;
		}
		else if(bo[y+2][x+1]=='n' && x < 7 && y <6)	
		{
			f(false);	
			return true;
		}
		else if(bo[y + 1][x-2]=='n' && x >1 && y < 7)	
		{
			f(false);	
			return true;
		}
		else if(bo[y-2][x-1]=='n' && x > 0  && y >1)	
		{
			f(false);	
			return true;
		}
		else if(bo[y+2][x-1]=='n' && x > 0 && y < 6 )	
		{
			f(false);	
			return true;
		}
		else if(bo[y-1][x-2]=='n' && x > 1 && y>0)	
		{
			f(false);	
			return true;
		}
		else
		{
			int i,j;
			for(i=x+1,j=y+1;i<8 && j<8;i++,j++)	
				if(bo[j][i] == 'b' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x+1,j=y-1;i<8 && j>-1;i++,j--)	
				if(bo[j][i] == 'b' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i= x-1,j=y-1;i>-1 && j>-1;i--,j--)	
				if(bo[j][i] == 'b' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x-1,j=y+1; i >-1 && j < 8 ;i--,j++)	
				if(bo[j][i] == 'b' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x,j=y+1;j<8;j++)	
				if(bo[j][i] == 'r' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x,j=y-1;j>-1;j--)	
				if(bo[j][i] == 'r' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x+1,j=y;i<8 ;i++)	
				if(bo[j][i] == 'r' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x-1,j=y;x>-1;i--)	
				if(bo[j][i] == 'r' || bo[j][i] == 'q' )
				{
					f(false);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
		}
		
			
	}		
	else
	{
		if(bo[y+1][x-1]=='P' && x > 0 && y < 7 )	
		{
			f(true);	
			return true;
		}			
		else if(bo[y+1][x+1]=='P' && x < 7 && y <7 )	
		{
			f(true);	
			return true;
		}
		else if(bo[y-1][x+2]=='N' && x < 6 && y > 0)	
		{
			f(true);	
			return true;
		}
		else if(bo[y + 1][x+2]=='N' && x < 6 && y <7)	
		{
			f(true);	
			return true;
		}
		else if(bo[y-2][x+1]=='N' && x < 7 && y > 1 )	
		{
			f(true);	
			return true;
		}
		else if(bo[y+2][x+1]=='N' && x < 7 && y <6)	
		{
			f(true);	
			return true;
		}
		else if(bo[y + 1][x-2]=='N' && x >1 && y < 7)	
		{
			f(true);	
			return true;
		}
		else if(bo[y-2][x-1]=='N' && x > 0  && y >1)	
		{
			f(true);	
			return true;
		}
		else if(bo[y+2][x-1]=='N' && x > 0 && y < 6 )	
		{
			f(true);	
			return true;
		}
		else if(bo[y-1][x-2]=='N' && x > 1 && y>0)	
		{
			f(true);	
			return true;
		}
		else
		{
			int i,j;
			for(i=x+1,j=y+1;i<8 && j<8;i++,j++)	
				if(bo[j][i] == 'B' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x+1,j=y-1;i<8 && j>-1;i++,j--)	
				if(bo[j][i] == 'B' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i= x-1,j=y-1;i>-1 && j>-1;i--,j--)	
				if(bo[j][i] == 'B' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x-1,j=y+1; i >-1 && j < 8 ;i--,j++)	
				if(bo[j][i] == 'B' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x,j=y+1;j<8;j++)	
				if(bo[j][i] == 'R' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x,j=y-1;j>-1;j--)	
				if(bo[j][i] == 'R' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x+1,j=y;i<8 ;i++)	
				if(bo[j][i] == 'R' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
			for(i=x-1,j=y;x>-1;i--)	
				if(bo[j][i] == 'R' || bo[j][i] == 'Q' )
				{
					f(true);
					return true;
				}
				else if(bo[j][i] != '.')
					break;
		}
	}
	return false;
}

void fun()
{
	int i,j;
	
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(bo[i][j] == 'k' || bo[i][j] == 'K')
				if(process(bo[i][j],j,i))	
					return;
	printf("Game #%d: no king is in check.\n",t++);
}


int main()
{
	int i;
	bool x;
	while(scanf("%s%s%s%s%s%s%s%s",bo[0],bo[1],bo[2],bo[3],bo[4],bo[5],bo[6],bo[7]) == 8 )
	{
		x = false;
		for(i=0;i<8;i++ )
			if(strcmp("........",bo[i]))
			{
				x = true;
				break;
			}
		if(x)				
			fun();
		else
			break;
	}
	return 0;
}
