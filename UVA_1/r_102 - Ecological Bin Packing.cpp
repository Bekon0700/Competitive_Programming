#include<stdio.h>


int main()
{
	int b[3][3],c,i,j,k,x,y[2],m,n[2],z[2],f,C;
	char s[]="BCG",a[] = "BCG" ;
	
	while(scanf("%d%d%d%d%d%d%d%d%d",&b[0][0],&b[0][2],&b[0][1],&b[1][0],&b[1][2],&b[1][1],&b[2][0],&b[2][2],&b[2][1]) == 9 )
	{
		
		m = 2147483647;
		for( c = 0 ; c <  3 ; c ++ )
		{
			x =	b[1][c] + b[2][c] ;
			
			for( j = 0 , k = 0 ; j < 3 ; j ++)
				if(j != c)
				{
					y[k] = b[0][j] +b[2][j] + b[0][3-c-j]+b[1][3-c-j]; 
					n[k] = j ;
					z[k] = x + y[k];
					
					k ++ ;
				}
			
			if(z[0]>z[1])
			{
				f = z[1] ;	
				C = n[1] ;
			}
			else
			{
				f = z[0] ;
				C = n[0] ;
			}		

			if( f < m)
			{
				m = f ;
				a[0] = s[c];
				a[1] = s[C] ;
				a[2] = s[3-c-C];
				
			}
		}
		printf("%s %d\n",a,m);
	}

	return 0 ;
}
