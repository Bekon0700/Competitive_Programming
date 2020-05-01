#include<stdio.h>
#include<math.h>

int main()
{
    double pi=2*acos(0),A,B,R,r,I,ci,co,tri,E,a,pol;
    int n;

    while(scanf("%lf%d",&R,&n)==2)
    {
        if(n==1){ printf("%.10lf %.10lf %.10lf\n",R,0.0,0.0); continue;}
        A = pi - (2*pi/n);
        B = A/2;
        r = R*cos(B)/(1+cos(B));
        pol = n*0.5*sin(2*pi/n)*(R-r)*(R-r);
        a = pi*r*r;
        ci = a*A/2.0/pi;
        co = a - ci ;
		I = pol - n*ci ;
		E = pi*R*R -pol-n*co;
        printf("%.10lf %.10lf %.10lf\n",r,I,E);
    }

    return 0;
}

