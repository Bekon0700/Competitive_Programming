#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<list>
#include<iomanip>
#include<string>
#include<climits>
#include<sstream>
#include<fstream>
#include<cctype>
#include<time.h>
#include<assert.h>
#include<set>
#include<numeric>
#include<functional>
#include<cstring>
#include<cmath>
#include<iterator>
#include<memory.h>
#include<utility>
#include<ctime>
#include<algorithm>
using namespace std;
#define ll long long
#define dbl double
#define vl vector<ll>
#define sf(zz) scanf("%I64d",&zz)
#define sf2(zz,zzz) scanf("%I64d %I64d",&zz,&zzz)
#define sf3(zz,zzz,zzzz) scanf("%I64d %I64d %I64d",&zz,&zzz,&zzzz)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read freopen("in3.txt","r",stdin)
#define write freopen("out3.txt","w",stdout)
#define reset(a,d) memset(a,d,sizeof(a))
#define pb(a,b) a.push_back(b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define ALL(x) (x).begin(),(x).end()
#define LLA(x) x.rbegin(), x.rend()
#define SORT(v) sort(ALL(v))
#define inf   1e15
#define mod   1000000007
#define PI acos(-1.0)
string sss="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//-----------------------------------------------------------//
struct node
{
    int next[55],cnt;
    bool endmark;
} Trie[100009];
int cur,last;
void Reset(int koto)
{
    for(int i=0; i<54; i++)Trie[koto].next[i]=-1;
    Trie[koto].endmark = 0;
}
int convert(char C)
{
    int ret = 0;
    if(C >= 'A' && C <= 'Z')ret = (C - 'A' + 1);
    else if(C >= 'a' && C <= 'z') ret = (C - 'a' + 27);
    //cout<<"\t\t"<<ret<<endl;
    return ret;
}
void Insert(string s)
{
    ll i,j,l=s.size(); cur=0;
    for(i=0; i<l; i++)
    {
        int now = convert(s[i]);
        if(Trie[cur].next[now] == -1)
        {
            Trie[cur].next[now]=last;
            Reset(last++);
            cur = last - 1;
        }
        else
        {
            cur = Trie[cur].next[now];
        }
        Trie[cur].cnt++;
        //cout<<"\t\t"<<cur<<" "<<Trie[cur].cnt<<endl;
    }
    Trie[cur].endmark = 1;
}
bool Check(string s)
{
    ll i,j,l=s.size();cur=0;
    for(i=0; i<l; i++)
    {
        int now = convert(s[i]);
        if(Trie[cur].next[now] == -1)
        {
            return 0;
        }
        else
        {
            cur = Trie[cur].next[now];
        }
    }
    return Trie[cur].endmark;
}
void Print(string s)
{
    if(Check(s)==0){
        cout<<s.size()<<endl;
        return;
    }
    ll i,j,l=s.size();cur=0;
    ll ret = -1;
    for(i=0; i<l; i++)
    {
        int now = convert(s[i]);
        if(Trie[cur].next[now] == -1)
        {
            break;
        }
        else
        {
            cur = Trie[cur].next[now];
        }
        //cout<<"\t\t"<<cur<<" "<<Trie[cur].cnt<<endl;
        if(Trie[cur].cnt > 1)
        {
            ret = i + 1;
        }
    }
    if(ret==-1)ret = l-1;
    cout<<min(ret+1,l)<<endl;
}
void solve(ll CS)
{
    int q,qq,type,i,j;
    cin>>q;
    string s;
    last = 1;
    Reset(0);
    //cout<<"\nQ="<<q<<endl;
    for(i=1;i<=q;i++)
    {
        s.clear();
        cin>>s;
        if(Check(s)==0)
            Insert(s);
    }

    getchar();
    cin>>qq;
    for(i=1;i<=qq;i++)
    {
        s.clear();
        cin>>s;
        Print(s);
    }
}

int main()
{
//    read;write;
    ll t,no=0;
    t=1;
    //sf(t);
    while(t--)solve(++no);
}
