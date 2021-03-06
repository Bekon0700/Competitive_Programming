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

int ar[10010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k,mx,x,i,j;

    while(2==scanf("%d%d",&n,&k))
    {
        mx = 0;
        set<int>st;
        st.clear();
        for(i=0;i<n;i++)
        {
            cin>>x;
            st.insert(x);
            ar[x]++;
            mx = max(ar[x],mx);
        }
        int ans = mx/k;
        if(mx%k!=0)
            ans++;
        x = st.size();
        cout<<(ans*x*k)-n<<endl;
    }

    return 0;
}
