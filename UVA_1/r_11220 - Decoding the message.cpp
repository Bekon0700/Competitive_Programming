#include<stdio.h>
#include<ctype.h>

int main()
{
	int i,j,k,l,x,y,T,t=0; 
	char a[1000],c;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d\n",&T);
	
	while(T--)
	{
		t++;
		printf("Case #%d:\n",t);
		while(gets(a) && a[0] != '\0')
		{
			
			
			i=0;
			while(a[i]==' ')
				i++;
			printf("%c",a[i]);
			while(a[i] != ' ' && a[i] != '\0')
				i++;
			if(a[i]=='\0')
			{
				printf("\n");	
				continue;
			}
			l=2;
			j = i;
			while(true)
			{
				while(a[i] != ' ' && a[i] != '\0')
					i++;	
				k = i;
				if(k-j-1 >= l)
				{
					printf("%c",a[j+l]);	
					l++;
				}
				while(a[i]==' ')
					i++;
				if(a[i]=='\0')
				{
					printf("\n");
					break;
				}
				j = i - 1 ; 
				i++;
			}
			
		}
		if(T)
			printf("\n");
	}
	return 0;
}
