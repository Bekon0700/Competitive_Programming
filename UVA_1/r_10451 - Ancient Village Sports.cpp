#include<stdio.h>
#include<math.h>

int main()
{
    double r,n,A,R,p=2*acos(0),t,a,C,sp;
    int i = 1;
    while(scanf("%lf%lf",&n,&A)==2 && n >= 3)
    {
        t = 2 * p / n;
        R = A * 2 /( n * sin(t) );
        R = sqrt(R) ;
        C = p * R * R;
        sp = C - A ;
        t /= 2 ;
        r = R * cos(t);
        a = p * r * r;
        a = A - a ;
        printf("Case %d: %.5lf %.5lf\n",i,sp,a);
        i ++ ;
    }

    return 0 ;
}
