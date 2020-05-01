#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f(const void *a,const void *b)
{
	return strcmp( (char*) a, (char*) b);
}

char a[1000000][12],pas[1000000];

int main()
{
	int i,j,n,l,max,m,K,k;
	char out[12];
	
	while(scanf("%d%s",&n,&pas)==2)
	{
		l = strlen(pas);
		m = l-n+1;
		K=0;
		for(i=0;i<m;i++)
		{
			k=i;
			for(j=0;j<n;j++)
			{
				a[K][j] = pas[k++];	
			}
			a[K++][j] = '\0';
		}
		qsort(a,K,sizeof(a[0]),f);
		
		max=0;
		
		for(i=0;i<K;i++)
		{
			j=i+1;
			k=0;
			while(!strcmp( a[i] , a[j] ) && j<K)
			{
				k++;
				j++;
			}
			
			if(max<k)
			{
				max = k;
				strcpy(out,a[i]);
			}
			i=j-1;
		}
		printf("%s\n",out);
	}

	return 0;
}
