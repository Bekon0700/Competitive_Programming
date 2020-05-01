#include	<iostream>
#include	<stdio.h>
#include	<string.h>
#include	<map>

using namespace std;

char a[100002][11],b[100002][11];
int n ;
char c[1000];

int main()
{
	int i,j,k,e,f;
	map <string,int > E;
	map <string,int > F;

	n = 1;
	while(gets(c) && c[0] != '\0')	
	{
		for(i=0;c[i] != ' ';i++)
			a[n][i] = c[i];	
		a[n][i] = '\0';			
		i++;
		E[a[n]] = n;
		for(j=0;c[i] != '\0';i++,j++)
			b[n][j] = c[i];		
		b[n][j] = '\0';		
		F[b[n]] = n;

		n++;	
	}
	
	
	while(scanf("%s",c)==1)
	{
		if(E[c])
			printf("%s\n",b[E[c]]);
		else if(F[c])
			printf("%s\n",a[F[c]]);
		else
			printf("eh\n");
	}
	return 0;
}
