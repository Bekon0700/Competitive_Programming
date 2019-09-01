#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int fb ;

void base(_int64 x) ;

int main()
{
	int i,j,l,z,sb;
	_int64 x;
	char in[12];
	bool vali=true;

	while(scanf("%d%d%s",&sb,&fb,in)==3)
	{
		i=x=0;
		l=strlen(in);
		j=l;
		for( i = 0 ; i < l ; i ++ )
		{
			if( isdigit( in[i] ) )	z = in[i] - 48 ;
			else  z = in[i] - 55 ;
			
			x += (z * pow(sb, -- j) ) ;
			if(sb <= z)
			{
				printf("%s is an illegal base %d number\n",in,sb);
				vali= false;
				break ;
			}
		}

		if( !vali )
		{ 
			vali = true ;
			continue ;
		}
		
		printf("%s base %d = ",in,sb);
		base(x);
		printf(" base %d\n",fb);
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
		printf("%d",y);
	else
	switch(y)
	{
		case 10: printf("A");
				break;
		case 11: printf("B");
				break;
		case 12: printf("C");
				break;
		case 13: printf("D");
				break;
		case 14: printf("E");
				break;
		case 15: printf("F");
				break;
	}
}