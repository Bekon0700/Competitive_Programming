#include<stdio.h>

long long count[30010];

int main()
{
    int i,coin[]={1,5,10,25,50},n;

    count[0]=1;
    for( i = 0 ; i < 5 ; i ++ )
        for( n=0 ; n <30002; n ++ )
            count[ n + coin[i]] += count[n];
    while(scanf("%d",&n) == 1)
        if(count[n] != 1)
            printf("There are %lld ways to produce %d cents change.\n",count[n],n);
        else
            printf("There is only 1 way to produce %d cents change.\n",n);
    return 0;
}
