#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int l;
void BACKTRACK(int k,char a[],char b[],bool test[]);

int main()
{
	int i,j,k,t;
	char a[12],b[12];
	bool test[12];
	
	scanf("%d",&t);
	
	while( t -- )
	{
		scanf("%s",a);
		l = strlen( a );
		sort(&a[0],&a[l]);
		for(i=0;i<l;i++)
			test[i] = true;
		b[l]='\0';
		BACKTRACK(0,a,b,test);
		printf("\n");
	}


	return 0;
}

void BACKTRACK(int k,char a[],char b[],bool test[])
{
	int i,j,record[12],x=0;
	bool it[12];
	
	if(k == l)	
	{
		printf("%s\n",b);
	}
	else
	{
		for(i=0;i<l;i++)	
			it[i]=true;
		for(i=0;i<l;i++)
			if(test[i])			
			{
				for(j=0;j<x;j++)
					if(record[j] == a[i])
						it[i] = false ;
				if(it[i])
				{
					record[x++]=a[i];	
					b[k] = a[i] ;
					test[i] = false ;
					BACKTRACK ( k+1 , a , b , test ) ;
					test[i] = true ;
				}
			}
	}
}
