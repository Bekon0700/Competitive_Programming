#include<stdio.h>


int main()
{
	int t,h,m,oh,om,x,y;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d:%d",&h,&m);	
		
		if(h==12)
			h=0;
		
		y = h*60 + m ;
		x = 720 - y ;
		oh = x / 60;
		om = x - oh*60;
		if(oh==0)
			oh = 12;
		if( oh < 10)	printf("0");
		printf("%d:",oh);	
		if( om < 10)	printf("0");
		printf("%d\n",om);
	}

	return 0;
}
