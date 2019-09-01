#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;

#define oo          (1<30)
#define ERR         1e-5
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-1;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)

string s1,s2;
int len,s1c;

struct nod{
    char c;
    nod *l,*r;
};

nod* Build(int s,int e)
{
    int x=-1,i;

    fii(s,e)    if(s2[i]==s1[s1c])  {x=i;break;}
    if(x>-1)
    {
        nod *p;
        p = new nod();
        p->c=s1[s1c++];
        p->l = Build(s,x);
        p->r = Build(x+1,e);
        return p;
    }
    return NULL;
}

void Print(nod *p)
{
    if(p->l!=NULL)     Print(p->l);
    if(p->r!=NULL)     Print(p->r);
    printf("%c",p->c);
}

int main(){
    //freopen("in.in","r",stdin);
    int t;
    nod *p;

    while(cin>>s1>>s2)
    {
        s1c=0;
        p = new nod;
        len = s1.size();
        p =  Build(0,len);
        Print(p);
        cout<<endl;
    }
    return 0;
}

