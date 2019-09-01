#include<stdio.h>
#include<string.h>

int v[80];
int main()
{
	v['0'] = 0; v['1'] = 1; v['2'] = 2; v['3'] = 3; v['4'] = 4; v['5'] = 5; v['6'] = 6; v['7'] = 7; v['8'] =8 ; v['9'] = 9; v['A'] = 10; v['B'] = 11; v['C'] = 12; v['D'] = 13; v['E'] = 14;v['F'] = 15;  
	char a[15],b[15],ia[6],ib[6] ,o[2];
	int i,j,k,x,t,y,z;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s %s",ia,o,ib);
		memset(a,'0',13);
		memset(b,'0',13);
		a[13]='\0';  b[13] = '\0';
		i=0;
		x=0;
		while(ia[i] != 0)
		{
			x*=16;
			x += v[ia[i]];

			i ++ ;
		}
		y=i=0;
		while(ib[i] != 0)
		{
			y*=16;
			y += v[ib[i]];

			i ++ ;
		}
		if(o[0]=='+')
			z = x +  y ;
		else
			z = x - y ;
		i=12;
		while(x)
		{
			if( x & 1 )
				a[i] = '1';
			else
				a[i] = '0';
			i -- ;
			x >>= 1 ;
		}
		i=12;
		while(y)
		{
			if( y & 1 )
				b[i] = '1';
			else
				b[i] = '0';
			i -- ;
			y >>= 1 ;
		}
		printf("%s %s %s = %d\n",a,o,b,z);
	}

	return 0;
}