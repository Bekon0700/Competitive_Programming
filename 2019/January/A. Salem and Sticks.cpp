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

int ar[1110];
int i,j,n,sum,ans;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        int mn = OO;
        for(i=1;i<10000;i++)
        {
            sum = 0;
            for(j=0;j<n;j++)
            {
                if(ar[j]<i)
                {
                    sum+=(i-(ar[j]+1));
                }
                if(ar[j]>i)
                {
                    sum+=(ar[j]-(i+1));
                }
            }
            if(mn>sum)
            {
                mn = sum;
                ans = i;
            }

        }
        printf("%d %d\n",ans,mn);;
    }

    return 0;
}
