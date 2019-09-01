#include<stdio.h>
#include<string.h>

int left;
void diff(char a[],char b[],int l1,int l2,int s);

int main()
{
	char a[11000],b[11000],z='0';
	int i,j,l1,l2,t,x;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);	
		scanf("%s",b);	
		l1=strlen(a);
		l2=strlen(b);
		left = 0 ;
		if( l1 > l2 )
			diff(a,b,l1,l2,0);
		else if( l2 > l1 ) 
			diff(b,a,l2,l1,1);
		else if(l1 == l2)
		{
			x = 1 ;
			for(i=0;i<l1;i++)	
				if(a[i]!=b[i])
				{
					if(a[i]>b[i])
						diff(a,b,l1,l2,0);
					else
						diff(b,a,l2,l1,1);
					x = 0 ;
					break;
				}
			if(x)
				printf("0\n");
		}
	}

	return 0;
}

void diff(char a[],char b[],int l1,int l2,int s)
{
	int i,x,ca=0,k,j;
	char c[11000],z='0';
	if(s)
		printf("-");
	for(k=0,i=l1-1,j=l2-1; j > -1; i-- , j-- )
	{
		x = a[i]-b[j]-ca;
		ca = 0;
		if(x<0)
		{			
			x += 10 ; 
			ca = 1 ;
		}
		c[k++]= x + z;
	}
	
	while(i > -1)
	{
		x = a[i] - ca - z;
		ca = 0 ;
		if(x < 0 )
		{
			x  += 10;	
			ca = 1;
		}
		c[k++] = x + z ;
		i--;		
	}
	k -- ;
	while(c[k]==z)	
		k -- ;
	k ++ ;
	while( k -- )
		printf("%c",c[k]);
	printf("\n");		
}
