#include<stdio.h>
#include<math.h>


int main(){
    int t;
    double r,a,b,c,n1,n2,n3,m1,m2,m3,X,s,area,x;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf",&r,&m1,&n1,&m2,&n2,&m3,&n3);
        a = m1+n1;b = (m2+n2)*n1/m2;c=(m3+n3)*m1/n3;
        X = (a+b+c)/2;
        x = r * sqrt( X / ((X-a)*(X-b)*(X-c) ) );
        area = r*x*X;
        printf("%.4lf\n",area);
    }
    return 0;
}
