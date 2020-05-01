#include<stdio.h>
#include<string.h>

int ans[12][12],d[11];
int i,j,lp,la,n,m,l,k;
char a[108],p[109];

void GEN()
{
	d[0]=1; d[1]=1; d[2]=4; d[3]=4; d[4]=2; d[6]=1; d[5]=1; d[7]=4; d[8]=4; d[9]=2;
	
	for(i=1;i<10;i++)	ans[0][i] = 0;
	for(i=0;i<10;i++)	ans[1][i] = 1;
	for(i=0;i<10;i++)	ans[5][i] = 5;
	for(i=0;i<10;i++)	ans[6][i] = 6;
	
	ans[2][0] = 6; ans[2][1] = 2; ans[2][2] = 4;ans[2][3] = 8;
	ans[3][0] = 1; ans[3][1] = 3; ans[3][2] = 9;ans[3][3] = 7;
	ans[4][0] = 6; ans[4][1] = 4;
	ans[7][0] = 1; ans[7][1] = 7; ans[7][2] = 9;ans[7][3] = 3;
	ans[8][0] = 6; ans[8][1] = 8; ans[8][2] = 4;ans[8][3] = 2;
	ans[9][0] = 1; ans[9][1] = 9;
}

int main()
{
	GEN();
	bool tt;
	
	while(scanf("%s%s",a,p)==2)
	{
		if(	!strcmp(a,"0") && !strcmp(p,"0") )
			break;
		if(!strcmp(a,"0"))
		{
			printf("0\n");
			continue;	
		}
		tt=true;
		
		la= strlen(a);
		lp= strlen(p);
		for(i=0;i<lp;i++)
			if(p[i] != '0')
			{
				tt=false;
				break;				
			}
		if(tt)
		{
			printf("1\n");
			continue;	
		}
		n = a[la-1] - 48;
		m = 0;
		l = lp-2;
		if(l<0)
			l++;
		while( l < lp )
		{
			m *= 10 ;
			m  += ( p[l]-'0' ) ;			
			l ++ ;
		}
		printf("%d\n",ans[n][ m % d[n] ]);
	}
	return 0;
}
