#include <stdio.h>
#include<math.h>
#include<stdlib.h>
long long int primeFactors(long long int n)
{
    long long int s=0;
    while (n%2 == 0)
    {
        s=2;
        n = n/2;
    }
    for (long long int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            s+=i;
            n = n/i;
        }
    }
    if (n > 2)
        s+=n;
     return s;
}
int main()
{
	int t;
	long long int i,j,l,h,n,c,sl,sh;
	scanf("%d",&t);
	while(t--)
	{
	c=0;
	    scanf("%lld",&n);
	    long long int A[n],s[n];
	    for(i=0;i<n;i++)
	    {  scanf("%lld",&A[i]);
	        for(j=0;j<i;j++)
	        {
	            if(A[i]==A[j])
	            c+=2;
	            else
	            {
	                l=(A[i]<A[j]?A[i]:A[j]);
	                h=(l==A[i]?A[j]:A[i]);
	                if(h%l==0)
	                {
	                   sl= primeFactors(l);
	                   sh= primeFactors(h);
	                   if(sh%sl==0){
                            c++;
                           // printf("l = %d, sl = %d, h = %d, sh = %d\n", l,sl,h, sh);
	                   }

	                }
	            }
	        }
	    }
	 printf("%lld\n",c);
	}
	return 0;
}
