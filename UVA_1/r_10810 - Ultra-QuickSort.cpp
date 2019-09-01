#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

const int s=1000100;
typedef long long LL;

LL a[s],b[s];

LL M(int l1,int h1,int l2,int h2)
{
    LL re=0;
    int i,i1=l1,i2=l2;

    i=i1;
    while(l1<=h1&&l2<=h2)
    {
        if(a[l1]<a[l2]) b[i++] = a[l1++];
        else
        {
            b[i++] = a[l2++];
            re+=h1-l1+1;
        }
    }

    while(l1<=h1)   b[i++]=a[l1++];
    while(l2<=h2)   b[i++]=a[l2++];
    i=i1;

    while(i<=h2)   a[i] = b[i++];

    return  re;
}

LL MS(int l,int h)
{
    if(h-l<1)   return 0;
    LL re;
    re=MS(l,(l+h)/2);
    re+=MS(1+(l+h)/2,h);

    return re+M(l,(l+h)/2,1+(l+h)/2,h);
}

int main()
{
    int i,j,tks,n;

    LL m;

    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<n;i++)    scanf("%lld",a+i);
        m = MS(0,n-1);
        printf("%lld\n",m);
    }
    return 0;
}



