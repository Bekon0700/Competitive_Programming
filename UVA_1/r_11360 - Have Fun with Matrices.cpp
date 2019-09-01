#include<stdio.h>


int main()
{
	int  t, m, n, T, x, y, a, i, j, k;
	char  c[12],mat[10][11],p;
	
	scanf("%d",&T);
	for( a = 0 ; a < T ; a ++ )
	{
		scanf("%d",&n);
		for( i = 0 ; i < n ; i ++ )
			scanf("%s",mat[i]);
		scanf("%d",&m);
		for(k=0;k<m;k++)
		{
			scanf("%s",c);
			switch(c[0])
			{
				case 114:	scanf("%d%d",&x,&y);
							x--;y--;
							for(i=0;i<n;i++)
							{
								p = mat[x][i] ;	
								mat[x][i] = mat[y][i] ;
								mat[y][i] = p ;
							}
							break;
				case 99:	scanf("%d%d",&x,&y);
							x--;y--;
							for(i=0;i<n;i++)
							{
								p = mat[i][x] ;	
								mat[i][x] = mat[i][y] ;
								mat[i][y] = p ;
							}
							break;
				case 105:	for( i = 0 ; i < n ; i ++ )
								for( j = 0 ; j < n ; j ++ )
								{
									mat[i][j] ++ ;
									if( mat[i][j] == 58)									
										mat[i][j] = '0';
								}
							break ;
				case 100:	for( i = 0 ; i < n ; i ++ )
								for( j = 0 ; j < n ; j ++ )
								{
									mat[i][j] -- ;
									if( mat[i][j] == 47)									
										mat[i][j] = '9';
								}
							break ;
				case 116:	x = 0 ;
							for( i = 0 ; i < n ; i ++, x ++ )
								for( j = x ; j < n ; j ++ )
								{
									p = mat[i][j];
									mat[i][j]=mat[j][i];									
									mat[j][i]=p;
									
								}
							break ;
			}
		
		}
		printf("Case #%d\n",a+1);
		for( i = 0 ; i < n ; i ++ )
			printf("%s\n",mat[i]);
		printf("\n");
	}

	return 0;
}
