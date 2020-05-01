#include<stdio.h>
#include<algorithm>

using namespace std;

const long long M=1000007;

long long a[100011];

int main()
{
    long long i,sum,n,tks,ks=1,k,c,j;

    scanf("%lld",&tks);

    while(tks--)
    {
        scanf("%lld%lld%lld%lld",&k,&c,&n,&a[0]);
        for(i=1;i<n;i++)   a[i] = (k*a[i-1]+c)%M;
        sort(a,a+n);
        sum=0;
        j=0;
        for(i=n-2;i>-1;i--)
        {
            j = (a[i+1]-a[i])*(n-i-1)+j;
            sum+=j;
        }


        printf("Case %lld: %lld\n",ks++,sum);
    }
    return 0;
}

