#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,B,c,x,A,z,y,PI=2*acos(0);
    int cs=0;
    printf("Case    A      B    THETA  # of    Side   Side\n #     side   side  (deg)  Triags    1      2\n");

    while(scanf("%lf%lf%lf",&a,&b,&z)==3 && a)
    {

        ++cs;
        printf("%4ld%7.2lf%7.2lf%7.2lf",cs,a,b,z);
        B = z*PI/180.0;
        x = a*sin(B)/b;
        A = asin(x);
        z = a*cos(B);
        x = b*cos(A)+z;
        y = b*cos(PI-A)+z;
        if(y>0)   printf("     2%9.2lf%7.2lf\n",x,y);
        else if(x>0)  printf("     1%9.2lf\n",x);
        else printf("     0\n");
    }
    printf("\nEND OF REPORT for %d cases\n",cs);
    return 0;
}
