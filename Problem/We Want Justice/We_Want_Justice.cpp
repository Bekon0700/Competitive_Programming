#include <stdio.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int d,m,y,t,k,r,sum=((30*8)+(2018*365)+12),sum1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&d,&m,&y);
        scanf("%d%d%d",&t,&r,&k);
        sum1 = ((30*m)+(y*365)+d);
        if(sum1<=sum)
            printf("Case %d: Expired.\n",ks++);
        else if(t-k<r)
            printf("Case %d: Invalid.\n",ks++);
        else
        {
            printf("Case %d: Valid.\n",ks++);
            printf("Total Penalty Money: %d$.\n",((k*(k+1))/2)*10);
        }
    }

    return 0;
}
