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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n;
    int ar[110];
    map<int,int>mp;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]),mp[ar[i]]=i;

        int cnt = 0;
        for(i=1;i<=n;i++)
        {
            if(ar[i]!=i)
            {
                int x = mp[i];
                int y = ar[i];
                swap(ar[i],ar[x]);
                mp[y]=x;
                cnt++;
            }
        }
        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}