#include<stdio.h>
#include<math.h>

int main()
{
    double w,h,x,m;

    while(scanf("%lf%lf",&w,&h)==2)
    {
        x = (w+h - sqrt(w*w- w*h+h*h))/6;
        printf("%.3lf %.3lf %.3lf\n",x+1e-10,0.00,( (w<h)? w/2 : h/2)+1e-10 );
    }
    return 0;
}


