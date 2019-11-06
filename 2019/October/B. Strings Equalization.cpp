#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

char s[1100];
char t[1100];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    map<char,int>mp;
    int tks,ks=1,i,n;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        scanf("%s%s",s,t);
        n = strlen(s);
        int flag = 0;
        for(i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(mp[t[i]]>0)
                flag = 1;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}