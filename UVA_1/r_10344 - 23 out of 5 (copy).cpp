#include<stdio.h>

bool f;
void startBT(int a[],bool t[]);
void bt(int a[],bool t[],int n,int v);

int main()
{
	int a[5],i,n,v;
	bool t[5];
	
	while(scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]) == 5 && (a[0]||a[1]||a[2]||a[3]||a[4]))
	{
		for(i=0;i<5;i++)
			t[i]=true;
		f=false;
		v=0;
		startBT(a,t);
		if(f)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}		

	return 0;
}

void bt(int a[],bool t[],int n,int v)
{
	int i,k;
	if(v == 23 && n == 5)	
	{
		f=true;	
		return;
	}
	else
	{
		n++;
		for(i=0;i<5;i++)
			if(t[i])
			{
				t[i]=false;
				bt(a,t,n,v*a[i]);
				if(f)	return;				
				bt(a,t,n,v+a[i]);
				if(f)	return;				
				bt(a,t,n,v-a[i]);
				if(f)	return;				
				t[i]=true;
			}
	}
}

void startBT(int a[],bool t[])
{
	int i;
	for(i=0;i<5;i++)	
	{
		t[i]=false;
		bt(a,t,1,a[i]);
		t[i]=true;
	}
}
