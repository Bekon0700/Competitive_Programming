#include<stdio.h>

int n,in[22],p[22],ar[22];

int LIS()
{
    int i,mx=0,l,r,m;

    for(i=1;i<=n;i++)   ar[i]=25;

    for(i=0;i<n;i++)
    {
        l=0;r=i+1;

        while(l<r)
        {
            m = (l+r)/2;
            if(ar[m]<in[i]) l=m+1;else r=m;
        }
        ar[r]=in[i];
        if(r>mx)mx=r;
    }
    return mx;
}


int main()
{
    int i,j;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    while(scanf("%d",&j)==1)
    {
        in[j-1]=p[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&j);
            in[j-1]=p[i];
        }
        printf("%d\n",LIS());
    }

    return 0;
}

