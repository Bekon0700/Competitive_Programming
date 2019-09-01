#include<stdio.h>
#include<string.h>

int l;
void BACKTRACK(int k,char a[],char b[],bool test[]);
int main()
{
	int i,j,k,t,v[202];
	char a[102],b[102],c[102],temp;
	bool test[102];
	
	scanf("%d",&t);
	for(i = 65 , j = 0 ; i<91;i++,j+=2)
		v[i] = j;
	for(i = 97 , j = 1 ; i<123;i++,j+=2)
		v[i] = j;
	
	while( t -- )
	{
		scanf("%s",a);
		l = strlen( a );
		
		for(i=0;i<l;i++)
			test[i] = true;
		for(i=0;i<l-1;i++)		
			for(j=0;j < l-1;j++)
				if( v[ a[j] ] > v[ a[j+1] ] )
				{
					temp = a[j]; a[j] = a[j+1]; a[j+1] = temp ; 		
				}
		
		b[l] = '\0' ;
		BACKTRACK(0,a,b,test);
		
	}


	return 0;
}

void BACKTRACK(int k,char a[],char b[],bool test[])
{
	int i,j,record[102],x=0;
	bool it[102];
	
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
