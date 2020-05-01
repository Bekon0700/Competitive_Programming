#include<stdio.h>
#include<string.h>

int mat[1040][1040],i,j,l1,l2,m,t=1;

int main()
{
	char s1[1010],s2[1010];

	while(gets(s1) && strcmp(s1,"#") != 0)
	{
		gets(s2);
		//scanf("%s",s2);
		l1 = strlen(s1);
		l2 = strlen(s2);

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
		/*			
		for(i=0;i<=l1;i++)				
		{
			for(j=0;j<=l2;j++)
				printf("%d ",mat[i][j]);
			printf("\n");
			
		}
		*/		

		printf("Case #%d: you can visit at most %d cities.\n",t++,mat[l1][l2]);	
	}
	return 0 ;
}
