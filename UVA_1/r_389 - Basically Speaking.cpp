#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int fb , I;
char a[10];

void base(_int64 x) ;

int main()
{
	int i,j,l,z,sb;
	_int64 x;
	char in[12];
	bool vali=true;

	while(scanf("%s%d%d",in,&sb,&fb)==3)
	{
		I=i=x=0;
		l=strlen(in);
		j=l;
		for( i = 0 ; i < l ; i ++ )
		{
			if( isdigit( in[i] ) )	z = in[i] - 48 ;
			else  z = in[i] - 55 ;
			
			x += (z * pow(sb, -- j) ) ;
			
		}

				base(x);
		if(I<8)		
		{
			for(i=0 ; i < 7-I;i++)	printf(" ");
			a[I]='\n';
			printf("%s\n",a);
		}
		else
			printf("  ERROR\n");
	}

	return 0;
}

void base(_int64 x)
{
	int y;

	y = x % fb;
	x /= fb ; 
	
	if(x != 0)
		base(x);
	if( y < 10 )
		a[I++] = 48 + y ;
	else
	switch(y)
	{
		case 10: a[I++]='A';
				break;
		case 11: a[I++]='B';
				break;
		case 12: a[I++]='C';
				break;
		case 13: a[I++]='D';
				break;
		case 14: a[I++]='E';
				break;
		case 15: a[I++]='F';
				
	}
}