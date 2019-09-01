#include<iostream>
#include<algorithm>
#include<string>

#include<math.h>

using namespace std;

const int SZ=5000010;

bool f[SZ];
int dp[SZ],pri[1000],np,spf[SZ];

/// spf[i] is sum of distinct prime factor of i

void sieve()
{
    int c=0,i,j,r;

    f[2]=true;
    pri[c++]=2;

    for(i=3;i<SZ;i+=2)   f[i]=true;

    for(i=3;i<SZ;i+=2)
        if(f[i])
        {
            if(i<2240)  pri[c++]=i;

            if(i<=SZ/i) for(j=i*i,r=i+i;j<SZ;j+=r)  f[j]=false;
        }
}

void Make()
{
    int i,j,x,y,c,sum;

    for(i=2;i<SZ;i++)
    {
        if(f[i])    ///if i is a prime
        {
            dp[i]=dp[i-1]+1;
            spf[i]=i;
            continue;
        }

        y=i;

        for(j=0;;j++)
            if(y%pri[j]==0)
            {
                y/=pri[j];

                if(y%pri[j]==0) spf[i]=spf[y];
                else spf[i]=spf[y]+pri[j];

                c=0;
                if(f[spf[i]])   c++;

                dp[i]=dp[i-1]+c;
                break;
            }
    }
}


int main()
{
    int l,h;

    sieve();
    Make();

    while(scanf("%d",&l)==1&& l)
    {
        scanf("%d",&h);
        printf("%d\n",dp[h]-dp[l-1]);
    }

    return 0;
}


