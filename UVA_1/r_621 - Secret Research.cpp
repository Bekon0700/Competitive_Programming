#include<stdio.h>
#include<string.h>

int main()
{
	int k,l,n;
	char a[1000];

	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		scanf("%s",a);
		l = strlen(a);
		if( strcmp(a,"4") == 0 ||strcmp(a,"78") == 0 )
			printf("+\n");

		else if(a[l-2]=='3' && a[l-1]=='5')
				printf("-\n");
			else if(a[0]=='9' && a[l-1]==4)
					printf("*\n");
				else if(a[0]=='1' )
					{
						if(a[1]=='9' && a[2]=='0')
							printf("?\n");
						else
						printf("+\n");
					}
					else
						printf("*\n");
	}				

	
	return 0;
}

