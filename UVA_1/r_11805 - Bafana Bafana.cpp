#include<stdio.h>

int main()
{
    int i,j,k,t,an,n,s,p,ks=1;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&s,&p);

        an = p%n+s;
        if(an>n)    an-=n;

        printf("Case %d: %d\n",ks++,an);
    }

    return 0;
}

