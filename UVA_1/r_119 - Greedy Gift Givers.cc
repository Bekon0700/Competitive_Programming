#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>

using namespace std;

char name[13][15];
int money[15];

int main()
{
	int i,j,k,x,y,m,n,p,r,t=0;
	char a[15];
	map <string,int> MP;
	
	
	while(scanf("%d",&n)==1)
	{
		if(t)
			printf("\n");
		t++;
		MP.clear();
		for(i=0;i<n;i++)	
		{
			scanf("%s",name[i]);	
			MP[name[i]] = i;
			money[i] = 0;
		}
		
		
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",a,&x,&y);
			
			p = 0; 
			if(x && y)			
				p = x/y;
			m = MP[a];
			money[m] -= x;
			money[m] += x-y*p ;
			
			for(j=0;j<y;j++)
			{
				scanf("%s",a);
				m = MP[a];				
				money [m] += p;
			}
		}
		for(i=0;i<n;i++)
			printf("%s %d\n",name[i],money[i]);
	}

	return 0;
}
