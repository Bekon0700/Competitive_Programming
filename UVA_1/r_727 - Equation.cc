#include<stdio.h>
#include<ctype.h>

char stk[60];
int sign[100];

int main()
{
	int i,j,k,n,t,T;
	char a[60][3],c[60];
	sign['+'] = 1;sign['-'] = 1;sign['/'] = 4;sign['*'] = 4;
	
	scanf("%d\n",&t);
	
	while(t--)
	{
		k=j=0;
		T=0;
		stk[++T] = '(';
		while(gets(a[k]) && a[k][0] != '\0')	
		{
			
			if(a[k][0]>47 && a[k][0] < 58)
				c[j++] = a[k][0];
			else if(a[k][0] == '*' || a[k][0] == '+' || a[k][0] == '-' || a[k][0] == '/')
			{
				if(stk[T] == '(')
					stk[++T] = a[k][0];
				else if(sign[stk[T]] >= sign[a[k][0]])
				{
					while(sign[stk[T]] >= sign[a[k][0]])
						c[j++] = stk[T--]  ;
					stk[++T] = a[k][0] ;
				}
				else stk[++T] = a[k][0];
				
			}
			else if(a[k][0] == '(')
				stk[++T] = a[k][0];
			else 
			{
				while(stk[T] != '(')
					c[j++] = stk[T--];					
				T--;
			}
				
			k++;
		}
		while(stk[T] != '(')	
			c[j++] = stk[T--];
		c[j] = '\0'	;
		printf("%s\n",c);
		if(t)
			printf("\n");
	}
	return 0;
}
