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

#define oo        (1<<30)
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
template<class T>T sqr(T a) {return a*a;}

typedef long long LL;typedef vector<string>VS;typedef vector<int>VI;typedef vector<double>VD;typedef vector<long long>VLL;


int main(){
    int i,j,w,h,f,t,n,cc,k;
    //freopen("in.in","r",stdin);
    string a,b,c,d,x,y;

    cin>>t;

    while(t--)
    {
        cin>>x>>y;
        a.clear();
        b.clear();
        rdi(30){
            a+=x[i]; b+=y[i];
        }
        rdi(30) cout<<a[i];
        cout<<" ";
        rdi(30) cout<<b[i];
        cout<<endl;

        f=0;
        rii(31) if(b[i]=='1')   {f=1;break;}

        while(f)
        {
            f=0;
            c.clear();
            d.clear();
            rii(31) {
                if(a[i]==b[i])  c+='0';
                else c+='1';
                if(a[i]==b[i]&& a[i]=='1')  d+='1';
                else d+='0';
            }
            b.clear();

            rdi(30) cout<<c[i];
            a= c;

            b.clear();
            cc=0,k=0;

            rii(31) {
                    if(d[i]=='1')   k=2;
                    else k=0;
                    if((cc+k)&1) b+='1';
                    else b+='0';
                    if(k)   cc=1;
                    else cc=0;
            }
            if(cc)
                b+='1';

            if(b.size()>31){ cout<<" overflow"<<endl;break;  }
            else{
                    cout<<" ";
                    rdi(30) cout<<b[i];
                    cout<<endl;
                }
            rii(31) if(b[i]=='1')   {f=1;break;}
        }
        if(t)cout<<endl;
    }
    return 0;
}

