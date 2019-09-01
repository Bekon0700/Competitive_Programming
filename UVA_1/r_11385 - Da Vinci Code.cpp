#include<stdio.h>

int main()
{
	int i,j,k,in[109],fib[50],x,h,l,m,mid,t,n,sn[109];
	char is[109],os[109],q,ks[109];
	bool sp[103],ss;

	fib[1]=fib[0]=i=1;
	while( fib[ i ++ ] > 0)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		m=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&in[i]);
			l=1;
			h=45;
			while(l<h)
			{
				mid = (l+h) >> 1 ;
				if(in[i]<fib[mid])
					h = mid ;
				else if(in[i]>fib[mid])
					l=mid;
					else
					{
						in[i]=mid;
						break;
					}
			}
			if(mid > m) m = mid ;
		}
		scanf("%c",&q);
		gets(is);
		i=k=0;
		while(is[i] !='\0')
		{
			if(is[i]>64 && is[i]<91)
			{
				os[k] = is[i];
				k++;
			}
			i ++ ;
		}
		for(i=0;i<m;i++)
			sp[i] = false ;
		for(i=0;i<n;i++)
		{
			is[ in[i] - 1 ] = os[i];

			sp[ in[i] - 1 ] = true;
		}
		ss=false;
		for(i=0;i<m;i++)
			if(sp[i])
                printf("%c",is[i]);
            else
				printf(" ");
		printf("\n");
	}

	return 0 ;
}
