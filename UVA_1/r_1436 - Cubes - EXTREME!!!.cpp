#include<stdio.h>
#include<math.h>

int main()
{
    long long i,j,k,l,x,y,z,a,b,y1,x1,x2,y2,z1,z2;
    double p,q;
    bool bb;

    while(scanf("%lld",&z)==1 && z)
    {
        p=3;
        bb=true;
        l=pow(4*z,(1/p));
        l++;
        if(z%2) j=2;
        else    j=1;
        for(i = 1;i<=l;i += j)
            if(z%i==0)
            {
                a=i;
                b = z/a;
                p = 12*b-3*a*a;
                q=sqrt(p);
                if(q == ceil(q))
                {
                    y = (3*a+q)/6;
                    x=y+a;
                    z1=x*x*x-y*y*y;
                    x1 = (3*a+q)/6;
                    y1=x1-a;
                    z2=x1*x1*x1-y1*y1*y1;

                    if(z==z1)
                        printf("%lld %lld\n",x,y);
                    else if(z==z2 && y1>=0)
                            printf("%lld %lld\n",x1,y1);
                        else
                            printf("No solution\n");
                    bb=false;
                    break;
                }
            }
        if( bb == true )
            printf("No solution\n");
    }
    return 0;
}
