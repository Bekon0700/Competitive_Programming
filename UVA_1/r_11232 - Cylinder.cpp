#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

#define EQ(a,b) (fabs((a)-(b))<1e-5)

int main()
{
    int a,b;
    double w,h,r,m1,m2,pi=2*acos(0);

    while(scanf("%d%d",&a,&b)==2 && a )
    {
        if(a>b) {w=b;h=a;}
        else {w=a;h=b;}
        r = h/3.0;
        r = min(r,w/(2*pi));
        m1 = pi*pow(r,2.0)*(h-2.00*r);
        r = min(w/2.0,h/(2.0 + 2.0*pi));
        m2=pi*r*r*w;
        printf("%.3lf\n",max(m1,m2));
    }
    return 0;
}
