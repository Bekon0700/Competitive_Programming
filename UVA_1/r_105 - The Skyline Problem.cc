#include<stdio.h>

int a[10002];

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,l,r,h,t=0,max=0,min=200000;
	
	while(scanf("%d%d%d",&l,&h,&r)==3)
	{
		if(min>l)   min = l;
		if(max<r)   max = r;
		
		for( ;l<r;l++)	
			if(a[l]<h)
				a[l] = h;
	}
	
	printf("%d",min);
	
	for(i=min;i <max;i++)
		if( a[i] != a[i+1])
			printf(" %d %d",a[i],i+1);
	printf(" 0\n");

	return 0;
}
