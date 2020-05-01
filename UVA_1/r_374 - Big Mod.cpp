#include<stdio.h>

int main()
{
    int b,p,m,x,z,power,i;

    while(scanf("%d%d%d",&b,&p,&m)==3)
    {
        power = b%m;
        x=1;
        i=0;
        while(p)
        {
            if(p&1)    x = (x * power) % m ;
            power = (power *power) % m ;
            p >>= 1 ;
        }
        printf("%d\n",x);
    }
    return 0 ;
}
