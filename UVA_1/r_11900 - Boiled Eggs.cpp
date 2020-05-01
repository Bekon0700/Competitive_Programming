#include<stdio.h>
#include<algorithm>

using namespace std;


int main()
{
    int i,n,c,p,q,ks=1,t,s,a[30];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&n,&p,&q);
        for(i=0;i<n;i++)    scanf("%d",&a[i]);
        sort(a,a+n);

        for(i=c=s=0;i<n;i++)
        {
            if(c<p && s+a[i]<=q)
            {
                s+=a[i];
                c++;
            }else break;
        }

        printf("Case %d: %d\n",ks++,c);
    }

    return 0;
}
