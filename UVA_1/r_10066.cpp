#include<stdio.h>

int mat[104][104],i,j,l1,l2,m,t=1;

int main()
{
	int  s1[105],s2[105];

	while(scanf("%d%d",&l1,&l2)==2 && ( l1 | l2 ) )
	{
		for(i=0;i<l1;i++)
			scanf("%d",&s1[i]);
		for(i=0;i<l2;i++)
			scanf("%d",&s2[i]);
		

		if( l1 > l2 )	
			m=l1;
		else	
			m=l2;

		for(i=0; i < m ;i++)
			mat[i][0] = mat[0][i] = 0;

		for(i=1;i<=l1;i++)
			for(j=1;j<=l2;j++)
				if(s1[i-1] == s2[j-1])
					mat[i][j] = mat[i-1][j-1]+1;
				else if( mat[i][j-1] <=mat[i-1][j] )
						mat[i][j] = mat[i-1][j] ;
					else
						mat[i][j] = mat[i][j-1] ;
		
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",t++,mat[l1][l2]);	
	}
	return 0 ;
}
