#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

bool isprime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i<=n/2;i++)
        if(n%i==0)
            return false;
    return true;
}

int primesum(int n)
{
    while(n>9)
    {
        int sum = 0;
        while(n!=0)
        {
            sum+=(n%10);
            n/=10;
        }
        n = sum;
    }
    return n;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,l,r,sum,ans,i;
    scanf("%d",&tks);
    while(tks--)
    {
        ks = 1;
        scanf("%d%d",&l,&r);
        if(l<=r)
        {
            for(i=l;i<=r;i++)
            {
                if(isprime(i))
                {
                    sum = primesum(i);
                    if(sum==1)
                        ans = 2;
                    else
                    {
                        if(isprime(sum))
                            ans = sum;
                        else
                        {
                            while(!isprime(sum))
                                sum--;
                            ans = sum;
                        }
                    }
                    if(ks==1)
                        printf("%d",ans);
                    else
                        printf(" %d",ans);
                    ks++;
                }
            }
            if(ks==1)
                printf("There has no prime number from %d to %d.",l,r);
            printf("\n");
        }
        else
        {
            for(i=l;i>=r;i--)
            {
                if(isprime(i))
                {
                    sum = primesum(i);
                    if(sum==1)
                        ans = 2;
                    else
                    {
                        if(isprime(sum))
                            ans = sum;
                        else
                        {
                            while(!isprime(sum))
                                sum--;
                            ans = sum;
                        }
                    }
                    if(ks==1)
                        printf("%d",ans);
                    else
                        printf(" %d",ans);
                    ks++;
                }
            }
            if(ks==1)
                printf("There has no prime number from %d to %d.",l,r);
            printf("\n");
        }
    }

    return 0;
}
