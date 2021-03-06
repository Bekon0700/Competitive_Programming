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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

ll ar[10010];

ll sum(ll n)
{
    int s =0;
    while(n!=0)
    {
        s += n%10;
        n=n/10;
    }
    return s;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i=1,j=19;
    while(i<=10000)
    {
        while(sum(j)!=10)
            j++;
        ar[i++]=j;
        j++;
    }

    int n;
    while(1==scanf("%lld",&n))
    {
        printf("%lld\n",ar[n]);
    }

    return 0;
}
