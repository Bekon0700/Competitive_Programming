#include<stdio.h>

#define max(a,b) a>b ? a : b

int c[102],mat[102][25500];

int main()
{
	int i,t,n,mm,total,w;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		total = 0 ;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			total += c[i];
		}
		mm = total / 2 ;
		for(i=0;i <= n;i++)	mat[i][0] = 0;
		for(i=0;i <= mm;i++)	mat[0][i] = 0;
			
		for(i=1;i<=n;i++)
			for(w=1;w <= mm;w++)
				if(c[i] > w)
					mat[i][w] = mat[i-1][w]; 
				else
					mat[i][w] = max(mat[i-1][w] , mat[i-1][w-c[i]]+c[i]);				
				
		printf("%d\n",total - 2*mat[n][mm]);
	
	
	}

	return 0;
}
