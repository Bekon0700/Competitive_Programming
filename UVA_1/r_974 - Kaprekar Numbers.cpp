#include<stdio.h>

int main()
{
	int  i,j=0,m,x,y,n,a[]={9,45,55,99,297,703,999,2223,2728,4879,4950,5050,5292,7272,7777,9999,17344,22222,38962};
	
	scanf("%d",&n);
	
	while(++j)
	{
		scanf("%d%d",&x,&y);
		printf("case #%d\n",j);

		for(i=0,m=0;i<19;i++)
			if(a[i] >= x && a[i] <= y)
			{
				printf("%d\n",a[i]);	
				m = 1 ;
			}
		if(!m)
			printf("no kaprekar numbers\n");
		if(j < n )		
			printf("\n");
		else
			break;
	}
	return 0;
}

