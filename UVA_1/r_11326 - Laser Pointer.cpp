#include<stdio.h>
#include<math.h>

#define ERR     1e-5

int main()
{
    double A,pi=2*acos(0),t,x,y,B,l,w,b,a;
    int n,oe,ks,ti,T;

    scanf("%d",&ks);
    while(ks--)
    {
        scanf("%lf%lf%d",&l,&w,&T);
        if(!T)   {printf("1.000\n");continue;}
        A = B = 0.0;
        t=T;
        t *= pi/180.0;
        b = w/tan(t);
        a = w/sin(t);
        ti = l/b;
        A += ti*a;
        x=l-ti*b;
        y = tan(t)*x;
        A += x/cos(t);
        if(ti&1)    B = sqrt(l*l+(w-y)*(w-y));
        else B = sqrt(l*l+y*y);
        A/=B;
        printf("%.3lf\n",A);
    }


    return 0;
}
