#include<stdio.h>


int ar[100001];

int main()
{
    int an,n,ks=1,tks,m,i,j;

    scanf("%d",&tks);

    while(tks--)
    {

        scanf("%d",&n);
        m=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",ar+i);
            if(ar[i]-ar[i-1]>m) m = ar[i]-ar[i-1];
        }
        while(true)
        {
            an=1;
            j=m;
            for(i=1;i<=n&&an;i++)
                if(ar[i]-ar[i-1]==j)    j--;
                else if(ar[i]-ar[i-1]>j)an=0;

            if(an){printf("Case %d: %d\n",ks++,m);break;}

            m++;
        }


    }

    return 0;
}


