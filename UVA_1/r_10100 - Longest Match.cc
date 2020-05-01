#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char a[1002][21],b[1002][21],A[1002],B[1002];
	int t=1,i,j,k,la,lb,M,N,m,n,l,mat[1003][1003];
	
	while(gets(A) && gets(B))
	{
		la =strlen(A) +1;
		lb =strlen(B) +1;
		for(i=m=l=0;i<la;i++)
		{
			if( !isalnum(A[i]) )	
			{
				for(j=m,k=0;j<i;j++,k++)	
					a[l][k] = A[j];
				if(k)
				{
					a[l][k] = '\0';
					l++;
				}
				m = i+1;
			}
		}
		la = l;
		
		for(i=m=l=0;i<lb;i++)
		{
			if( !isalnum(B[i]) )	
			{
				for(j=m,k=0;j<i;j++,k++)	
					b[l][k] = B[j];
				if(k)
				{
					b[l][k] = '\0';
					l++;
				}
				m = i+1;
			}
		}
		lb = l;
		
		if(la > lb)
			l = la;
		else
			l = lb;
		for(i=0;i<l;i++)
			mat[i][0] = mat[0][i] = 0;
		for(i=1;i <= la;i++)
			for(j=1;j <= lb;j++)
				if(!strcmp(a[i-1],b[j-1]))
					mat[i][j] = mat[i-1][j-1]+1	;
				else if(mat[i-1][j] >= mat[i][j-1])
					mat[i][j] = mat[i-1][j];
				else 
					mat[i][j] = mat[i][j-1];
		if(mat[i-1][j-1])
			printf("%2d. Length of longest match: %d\n",t++,mat[i-1][j-1]);
		else
			printf("%2d. Blank!\n",t++);
	}

	return 0;
}
