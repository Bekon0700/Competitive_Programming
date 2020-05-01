#include<stdio.h>
#include<math.h>

#define		pi	acos(0)/90
#define  	P	90/acos(0)


int main()
{
	int i,j,t,n,p,ua,us,TT;
	double x,y,d,T,X,Y,SX,CX,cs,ss,AX;
	char dir[10],dymention[120],s;
	
	scanf("%d",&t);
	while( t -- )
	{
		x = y = T = 0 ;
		scanf("%d",&n);
		p = 0 ;
		for(i=0; i < n ;i++)
		{
			scanf("%s%s",dir,dymention);
			if(dymention[0] != '?')
			{
				j = d = 0 ;
				if(dymention[0] == '-')
					j ++ ;
				while( dymention[j] != '\0' )	
				{
					d *= 10 ;
					d += ( dymention[j] - '0' );
					j++;
				}
				if( dir[0] == 'b')	d = - d ;
				if(dymention[0] == '-')  d =- d ;
			}
			else if( dir[0] == 'f' || dir[0] == 'b' )
			{
				s = dir[0] ;
				p = 1 ;
				AX = T;
				TT = T + 0.1;
				continue;
			}
			else 
			{
				p = 2;	X = -1*x;	  Y = -1*y;
				s=dir[0];
				SX = CX = 0 ;		
				y += (d * sin( pi * T ) ) ;
				x += (d * cos( pi * T ) ) ;
				continue;
			}
			if(!p)
			{
				if( dir[0] == 'r' )
					T -= d ;
				else if(dir[0] == 'l')			
					T += d ;
				else 
				{
					y += (d * sin( pi * T)) ;
					x += (d * cos( pi * T)) ;
				}
			}
			else if(p == 1 )
			{
				if(dir[0] == 'r' )
					T -= d ;
				else if(dir[0] == 'l')			
					T += d ;
				else
				{
					y += (d * sin( pi * T ) ) ;
					x += (d * cos( pi * T ) ) ;
				}
			}
			else
			{
				if(dir[0] == 'r' )
					T -= d ;
				else if(dir[0] == 'l')			
					T += d ;
				else 
				{
					SX += (d * sin( pi * T ) ) ;
					CX += (d * cos( pi * T ) ) ;
				}
			}
		}
		if(p == 2 )
		{
			ss = (Y*CX - X*SX) / (SX*SX +CX*CX);	
			cs = (Y*SX + X*CX) / (SX*SX +CX*CX);
			x = asin(ss)*P;		
			if(cs < 0 && ss < 0 )
				x = asin(ss) * P ;  
			else if(cs < 0)
				x = 90 + ( acos(ss) * P) ;			
			else if( ss < 0 )
				x = 360 - acos(cs) * P  ;
			if(s == 'r' && fabs(x) > 0.0001)
				x = 360 - x ;
		}
		else 
		{
			X = Y = 0 ;
			if(fabs(x) > 0.00001)
				X = - x ;
			if(fabs(x) > 0.00001)
				Y = - y ;
			if( fabs( sin( AX *pi ) ) > 0.0001 )
				x = Y / sin( AX *pi ) ;
			else
				x = X / cos( AX *pi ) ;
			if(s == 'b' && fabs(x) > 0.00001)
				x = -x ;
		}
		printf("%.0lf\n",x);		
	}

	return 0 ;
}
