#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10001],b[10001];

int main()
{
	int n=0,m,i,j,k,l,e;		
	char c;
	
	//freopen("in.txt","r",stdin);
	while(scanf("%d%c",&a[n],&c)==2)
	{
		n++;
		if(c !='\n')
		{
			while(scanf("%d%c",&a[n],&c)==2)	
			{
				n++;
				if(c == '\n')	
					break;
			}
		}
		m=0;
		while(scanf("%d%c",&b[m],&c)==2)
		{
			m++;
			if(c == '\n')			
				break;
		}
		sort(&a[0],&a[n]);		sort(&b[0],&b[m]);
		
			
			for(i=l=k=0;i<n;i++)
			{
				for(j=k;j<m;j++)
					if(a[i] == b[j])
					{
						l++;
						k = j+1;						
						break;
					}
			}
			
		if(l)
		{
			if(l==m && n==m)	
				printf("A equals B\n");
			else if(l==n && n < m)
				printf("A is a proper subset of B\n");
			else if(l==m && m < n)
				printf("B is a proper subset of A\n");
			else
				printf("I'm confused!\n");
		}
		else
			printf("A and B are disjoint\n");
		
		
		n=0;		
	}

	return 0;
}
