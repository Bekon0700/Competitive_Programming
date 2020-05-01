#include<stdio.h>

int main()
{
	char a[100000];
	int i=0,j;
	
	while(gets(a))
	{
		for(j=0; a[j]!='\0';j++)
			if(a[j] != '"')
				printf("%c",a[j]);
			else
			{
				if(i%2)	
					printf("''");
				else
					printf("``");
				i++;
			}
		printf("\n");
		
	}
	return 0;	
}
