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
    int i,j,t,n,m,x;
    string a,b,c,d;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        n=0;
        x = 2*(d[0]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(d[2]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(c[0]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(c[2]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(b[0]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(b[2]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(a[0]-48);  n += x%10;  x/=10;  n += x%10;
        x = 2*(a[2]-48);  n += x%10;  x/=10;  n += x%10;


        //cout<<n<<endl;
        n += (d[3]+d[1]+a[3]+a[1]+b[3]+b[1]+c[3]+c[1] - 48*8);
        if(n%10)
            cout<<"Invalid"<<endl;
        else
            cout<<"Valid"<<endl;

    }



    return 0;
}

