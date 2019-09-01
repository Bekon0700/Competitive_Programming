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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int ar[50],n,p,q,i,cnt,sum;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&n,&p,&q);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        cnt = sum =0;
        for(i=0;i<n;i++)
        {
            sum+=ar[i];
            if(sum<=q)
                cnt++;
        }
        printf("Case %d: %d\n",ks++,min(p,cnt));
    }

    return 0;
}
