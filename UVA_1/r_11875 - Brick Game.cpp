#include<stdio.h>

int a[100];

int main()
{
    int ks=1,tks,i,n;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)    scanf("%d",&a[i]);
        printf("Case %d: %d\n",ks++,a[n/2]);

    }
    return 0;
}
