#include<stdio.h>
#include<math.h>



int main()
{
    int t;
    double a,b,c,s,ar;

    scanf("%d",&t);
    while(t)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        a = 1.0/a;b = 1.0/b;c = 1.0/c;
        s = a+b+c;

        if(a<b+c && b<c+a && c<a+b)
        {
            ar = 1.0/sqrt(s*(a+b-c)*(b+c-a)*(a+c-b));
            printf("%.3lf\n",ar);
        }
        else printf("These are invalid inputs!\n"),t--;


    }


    return 0;
}
