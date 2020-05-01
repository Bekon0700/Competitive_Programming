#include<stdio.h>

void bt(int a[],int k,int in[],int j);
int count = 0,b=0;
int n;

int main()
{
	int a[15],i,j,k,in[15];
	bool x=false;
	
	while(scanf("%d",&n) && n)
	{
		if(x)
			printf("\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		bt(a,0,in,0);
		x = true;
	}
	return 0;
}

void bt(int a[],int k,int in[],int j)
{
	int i,nc;
	
	if(k == 3)	
	{
		for(i=0;i<2;i++)
			printf("%d ",in[i]);
		printf("%d\n",in[i]);
	}
	else
	{
		for(i=j;i<n;i++)
		{
			in[k]=a[i];
			bt(a,k+1,in,i+1);			
		}
	}
}
