#include<iostream>
using namespace std;

double pc[1000001];
bool f[1000001];
int p[80000],rp[1000001];

void PC()
{
    int i,n,r,j,np=0,up,d;
    double x,y;

    for(i=3;i<1000001;i+=2)  f[i]=true;
    f[2] = true;
    p[np++] = 2;
    rp[2] = 1;

    for(i=3;i<1000001;i++)
    {
        if(f[i])
        {
            p[np++]  = i;
            if(i<=1000000/i)
                for(j=i*i,r=i+i;j<1000001;j+=r)     f[j] = false;

        }
        rp[i]=rp[i-1]+f[i];
    }
    pc[1] = 0.;
    for(i=2;i<1000001;i++)
    {
        n = i;
        d=0;
        x =0;
        for(j=0;p[j]<=n/p[j];j++)
            if(n%p[j]==0)
            {
                d++;
                x+=pc[i/p[j]]+1;
                while(n%p[j]==0)
                    n/=p[j];
            }
        if(n>1)
        {
            d++;
            x+=pc[i/n]+1;
        }
        y = (rp[i]-d)*1./rp[i];
        pc[i] = (y+x/rp[i])/(1-y);
    }
}


int main()
{
    int ks=1,tks,n;
    PC();

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        printf("Case %d: %.9lf\n",ks++,pc[n]);
    }

}
