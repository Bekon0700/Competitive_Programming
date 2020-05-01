#include<stdio.h>

int  value[150];

int main()
{
	int i,t,n,T=1;
	char a[120],c;
	value['a'] = value['d'] = value['g'] = value['j'] = value['m'] = value['p'] = value['t'] = value['w'] = value[' '] = 1;
	value['b'] = value['e'] = value['h'] = value['k'] = value['n'] = value['q'] = value['u'] = value['x'] = 2;
	value['c'] = value['f'] = value['i'] = value['l'] = value['o'] = value['r'] = value['v'] = value['y'] = 3;
	value['s'] = value['z'] = 4;
	scanf("%d",&t);
	scanf("%c",&c);
	while(t--)
	{
		n=0;
		while(scanf("%c",&c)==1 && c!= '\n' )
			n += value[c];
		printf("Case #%d: %d\n",T,n);
		T++;
	}
	return 0;
}
