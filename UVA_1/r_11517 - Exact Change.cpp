#include<stdio.h>
#include<algorithm>

using namespace std;

int tk[20000],co[100];


bool com(int a,int b){return a>b;}

int main()
{
    int m,i,j,tot,ks,f,n;
    scanf("%d",&ks);

    while(ks--)
    {
        scanf("%d%d",&f,&n);
        tot=0;

        for(i=0;i<n;i++)    {scanf("%d",&co[i]);tot+=co[i];}

        sort(co,co+n,com);


        m = (tot<19999)?tot:19999;
        n++;
        for(i=1;i<=m;i++)   tk[i] = n;
        n--;
        tk[0] = 0;
        tot = 1;

        for(i=0;i<n;i++)
            for(j=m;j>=0;j--)
                if(j+co[i]<=m && tk[j+co[i]]>tk[j]+1)
                {
                    tk[j+co[i]]=tk[j]+1;
                }




        for(i=f;i<=m;i++)
            if(tk[i]<n+1)
            {
                    printf("%d %d\n",i,tk[i] );
                    break;
            }




    }
    return 0;
}



