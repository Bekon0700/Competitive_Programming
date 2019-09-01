#include <stdio.h>

int main()
{
    int tks;
    long long n,i,x;
    long long sum;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            sum+=(x-1);
        }
        printf("%lld\n",sum+1);
    }

    return 0;
}
