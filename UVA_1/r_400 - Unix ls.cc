#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	char str[61];
	int len;
}V;

V f[100];
int comp(const void *a,const void *b)
{
	V* x = (V*) a;
	V* y = (V*) b;
	return strcmp( x->str,y->str);	
}


int main()
{
	int  i,j,k,n,x,u,l,I,y,z;
	
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<60;i++)	
			printf("-");
		printf("\n");
		l=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",f[i].str);
			f[i].len = strlen(f[i].str) ;
			if(l < f[i].len )
				l = f[i].len;
		}

		qsort(f,n,sizeof(V),comp);

		l+=2;		
		x = 62/l;
		y = ceil((double)n/x);
		
		for(i=0;i<y;i++)
		{
			for(j=0,k=i;j<x && k<n;k+=y)
			{
				printf("%s",f[k].str);
				if(k+y<n && j<x-1 && k<n-1)
				{
					for(I=0;I < l-f[k].len;I++)
						printf(" ");
				}
				j++;
			}				
			printf("\n");
		}
	}

	return 0;
}
