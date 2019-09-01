#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	bool aa;
	int t=0,i,j,k,n,a[110],add[10050];
	
	while(scanf("%d",&n)==1)
	{
		t++;
		aa = false;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)	
			if(a[i] >= a[i+1])
				aa = true;
		if(!aa && (a[0] < 1 || a[n-1]<1))
			aa = true;
				
		
		if(aa)
		{
			printf("Case #%d: It is not a B2-Sequence.\n\n",t);	
			continue;
		}
		k=0;
		for(i=0;i<n;i++)
			for(j=i;j<n;j++)
				add[k++]=a[i]+a[j];
		sort(&add[0],&add[k]);
			k--;
		for(i=0;i<k;i++)
			if(add[i]==add[i+1])
			{
				aa=true;
				break;
			}
		
		if(aa)
			printf("Case #%d: It is not a B2-Sequence.\n\n",t);	
		else
			printf("Case #%d: It is a B2-Sequence.\n\n",t);
			
	}
	

	return 0;
}
