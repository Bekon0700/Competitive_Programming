#include<stdio.h>
#include<string.h>

double v(char a[])
{
	double x=0;
	for(int i=0;a[i] != '\0';i++)
	{
		x *=10;
		x += (a[i]-'0');
	
	}
	return x;
}
int main()
{
	char a[1000],b[1000],o[2];
	double xa,xb,x;

	while(scanf("%s%s%s",a,o,b)==3)
	{
		printf("%s %s %s\n",a,o,b);	

		xa = v(a);
		xb = v(b);
		if(xa>2147483647)
			printf("first number too big\n");
		if(xb>2147483647)
			printf("second number too big\n");
		if(o[0]=='*')
			x = xa * xb;
		else
			x = xa + xb;
		if(x>2147483647)
			printf("result too big\n");

	}

	return 0;
}