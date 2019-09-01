#include<stdio.h>
#include<math.h>

int main()
{
    double pi=2*acos(0);
    double l,h,w,t,a,b,c,ar,d2r=pi/180,lo=pi/2;

    while(scanf("%lf%lf%lf%lf",&l,&w,&h,&t)==4)
    {
        t*=d2r;
        b = l*tan(t);

        if(b>h)
        {
            t=lo-t;
            b = h*tan(t);
            ar=.5*b*h;
        }
        else
        {
            ar=l*h;
            ar-=.5*b*l;
        }
        printf("%.3lf mL\n",ar*w);
    }



    return 0;
}

