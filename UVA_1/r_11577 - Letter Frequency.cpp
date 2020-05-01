#include<stdio.h>

int main()
{
	int i,k ,n ,a[129];
	char c[203];
	scanf("%d\n",&n);

	while(gets(c))
	{
		for(i=65;i<123;i++)
			a[i]=0;
		i=0;
		while(c[i] != '\0')
		{
			a[c[i++]] ++ ;
			
		}
		k=0;
		for(i=97; i <123;i++)
		{
			a[i] = a[i-32] + a[i] ;
			if( a[i]> k)
				k = a[i] ;
		}
		for(i=97;i<123;i++)
			if( a[i] == k )
				printf("%c",i);
		if(n--)
			printf("\n");
		else
			break;
	}

	return 0;
}