#include<stdio.h>
#include<math.h>


int main()
{
	int i,j,k,t,xl,xu,yl,yu,x[4],y[4],s,w,u;
	
	scanf("%d",&t);
	t++;
	
	for(k=1;k<t;k++)
	{
		scanf("%d%d%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]);
		
		w = (x[1] - x[0]) * (y[1] - y[0]) + (x[3] - x[2]) * (y[3] - y[2]);
		if(x[0]>x[2])	xl = x[0];	else	xl = x[2];
		if(y[0]>y[2])	yl = y[0];	else	yl = y[2];	
		if(x[1]>x[3])	xu = x[3];	else	xu = x[1];
		if(y[1]>y[3])	yu = y[3];	else	yu = y[1];
		
		if(xl < xu && yl < yu)		
			s = (yu - yl) * (xu - xl);
		else s = 0;
			
		w -= 2*s;
		u = 10000 - w -s;	
		printf("Night %d: %d %d %d\n",k,s,w,u);
	}



	return 0;
}
