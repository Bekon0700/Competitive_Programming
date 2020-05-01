#include<stdio.h>


int main()
{
	int a,i,j,k,l,in[200000],ps[150000],ns[150000],x=0,n=1;
	char b;
	
	for(i=0;i<150000;i++)
		ps[i] = ns[i] = 0 ;
	
	while(scanf("%d%c",&a,&b)==2 )
	{
		
		if(a >= 0)
		{
			if(ps[a]) 				
				ps[a] ++ ;
			else
			{
				in[n++] = a ;
				ps[a] ++ ;
			}
			
		}
		else
		{
			if(ns[a * (-1)]) 				
				ns[a * (-1)] ++;
			else
			{
				in[n++] = a ;
				ns[ a * (-1)] ++;
			}
		}
		if(b=='\n')	break;
	}
	for(i=1;i<n;i++)
		if( 0 > in[i])
			printf("%d %d\n",in[i],ns[ (-1) * in[i] ]);
		else
			printf("%d %d\n",in[i],ps[ in[i] ]);
	return 0 ;
}
