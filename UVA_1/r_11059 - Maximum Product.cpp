#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    long long x,m;

    int a[20],n,i,ks=1,j;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)    scanf("%d",&a[i]);

        for(m=i=0;i<n;i++)
        {
            x=a[i];
            m>?=x;
            for(j=i+1;j<n;j++)
            {
                x*=a[j];
                m>?=x;
            }
        }
        printf("Case #%d: The maximum product is ",ks++);
        cout<<m<<".\n\n";
    }

    return 0;
}
