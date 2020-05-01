#include<stdio.h>
#include<string.h>


char str[12][12];
int val[12][12];

int main()
{
	int i,j,k,m,n,s,c,x,y,l;
	
	while(scanf("%d%d%d",&n,&m,&s)==3 && (n||m||s))
	{
		for(i=0;i<n;i++)	
			scanf("%s",str[i]);
		memset(val,0,sizeof(val));
		x = s-1;
		y = l = 0;
		k = 1;
		while(x >-1 && y>-1 && x < m && y < n)
		{
			if(val[y][x])	
			{
				l = k - val[y][x];
				break;
			}
			else
			{
				if(str[y][x] == 'N')
				{
					val[y][x] = k++;
					y--;	
				}
				else if(str[y][x] == 'S')
				{
					val[y][x] = k++;
					y++;	
				}
				else if(str[y][x] == 'W')
				{
					val[y][x] = k++;
					x--;	
				}
				else
				{
					val[y][x] = k++;
					x++;	
				}
			}
		}
		if(!l)
			printf("%d step(s) to exit\n",k-1);
		else
			printf("%d step(s) before a loop of %d step(s)\n",val[y][x]-1,l);			
	}

	return 0;	
}
