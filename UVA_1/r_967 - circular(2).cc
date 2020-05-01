#include<stdio.h>

int c[]={0,113,131,197,199,311,337,373,719,733,919,971,
		991,1193,1931,3119,3779,7793,7937,9311,9377,11939,
		19391,19937,37199,39119,71993,91193,93719,93911,99371,
		193939,199933,319993,331999,391939,393919,919393,
		933199,939193,939391,993319,999331,1000001}; 

int t[1000010],tc[1000010]; 

int B()
{
	int x=1,i,j=1,k;
	
	while(j<43)
	{	
		for(i=c[j],k=j+1;i<c[k];i++)		
			t[i]=x;
		j ++ ;
		x ++ ;
	}
	for(i=1;i<43;i++)
		tc[c[i]] = 1 ;
}

int main()
{
	int u,l,x,y;
	B();
	while(scanf("%d",&l)==1 && l != -1)	
	{
		scanf("%d",&u);	
		
		x = t[u] - t[l];
		if(tc[l])	
			x++;
		
		if(x>1)
			printf("%d Circular Primes.\n",x);
		else if(x)
			printf("1 Circular Prime.\n");
			else
				printf("No Circular Primes.\n");
		
	}
	return 0;		
}
