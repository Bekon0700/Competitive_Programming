#include<math.h>
#include<stdio.h>
#define er 1e-5

double f[15][10];
int nf;
char c[15];

double tri(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double s,a,b,c;
	a = sqrt( ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) );
	b = sqrt( ((x3-x2)*(x3-x2)) + ((y3-y2)*(y3-y2)) );
	c = sqrt( ((x1-x3)*(x1-x3)) + ((y1-y3)*(y1-y3)) );
	s = (a+b+c) / 2 ;
	return sqrt(s*(s-a)*(s-b)*(s-c));	
}

void FIG()
{
	char w[3];
	nf=1;
	while(scanf("%s",w) == 1 )
	{
		
		c[nf] = w[0];
		if(c[nf] == 'c')
			scanf("%lf%lf%lf",&f[nf][0],&f[nf][1],&f[nf][2]);
		else if(c[nf] == 'r')
			scanf("%lf%lf%lf%lf",&f[nf][0],&f[nf][1],&f[nf][2],&f[nf][3]);
			else if(c[nf] == 't')
			{
				scanf("%lf%lf%lf%lf%lf%lf",&f[nf][0],&f[nf][1],&f[nf][2],&f[nf][3],&f[nf][4],&f[nf][5]);
				f[nf][6] = tri( f[nf][0],f[nf][1],f[nf][2],f[nf][3],f[nf][4],f[nf][5] );
			}
			else if(c[nf] == '*')
			{
				nf ++ ;
				return;
			}
		
		++ nf ;
	}
	
}

void IF()
{
	int i,t=1;
	double x,y,p,q,r;
	bool z ;
	
	while(scanf("%lf%lf",&x,&y) == 2)	
	{
		
		if(x == 9999.9 && y == x)	
			return;		
		z = true ;
		for(i=1;i<nf;i++)
		{
			if(c[i] == 'r')
			{
				if( x > f[i][0] && y < f[i][1] && x < f[i][2] && y > f[i][3] )
				{
					z = false;
					printf("Point %d is contained in figure %d\n",t,i);
				}
			}
			else if(c[i] == 'c')
			{
				if( sqrt( ( (x - f[i][0]) * (x - f[i][0]) ) + ( (y - f[i][1]) * (y-f[i][1]) ) ) < f[i][2] )
				{
					z = false;
					printf("Point %d is contained in figure %d\n",t,i);
				}
				
			}
			else
			{
				p = tri( x,y,f[i][2],f[i][3],f[i][4],f[i][5] );
				q = tri( f[i][0],f[i][1],x,y,f[i][4],f[i][5] );
				r = tri( f[i][0],f[i][1],f[i][2],f[i][3],x,y);
				if( fabs( p+q+r - f[i][6]) < er)
					if(p > er && q >er && r > er)
					{
						z = false;
						printf("Point %d is contained in figure %d\n",t,i);
					}
			}
		}
		if(z)
			printf("Point %d is not contained in any figure\n",t);
		t++;
	}
}

int main()
{
	FIG();
	IF();
	return 0;	
}
