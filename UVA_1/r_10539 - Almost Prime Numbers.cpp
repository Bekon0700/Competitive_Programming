#include<iostream>
#include<algorithm>

using namespace std;

long long a[100000];
bool f[1000000];

int sieve()
{
    int c=1,r,i,j;
    long long H=1000000000000LL,x;

    x=2;
    while(x*2<H)
    {
        x*=2;
        a[c++]=x;
    }
    for(i=3;i<1000000;i+=2)
        if(!f[i])
        {
            x=i;

            while(x*i<H)
            {
                x*=i;
                a[c++]=x;
            }
            if(i<=1000000/i)
                for(j=i*i;j<1000000;j+=2*i)
                    f[j]=true;

        }

    //cout<<c<<endl;
    return c;

}

int BS(long long v,int h)
{
    int l=0,m;

    while(l<=h)
    {
        m = (l+h)>>1;
        if(a[m]<v)  l=m+1;
        else if(a[m]>v) h=m-1;
        else if(a[m]==v)    return m;
    }
    if(a[m]>v)  return m-1;
    return m;
}


int main()
{
    int t,c,m;
    long long l,h;

    sort(a,a+(m=sieve()));
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld%lld",&l,&h);
        //cin>>l>>h;
        printf("%d\n",BS(h,m-1)-BS(l-1,m-1));
    }

    return 0;
}

