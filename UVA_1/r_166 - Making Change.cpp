#include<iostream>
#include<string>

int c[]={5,10,20,50,100,200};
int f[6];
bool fg[602];

int main()
{
    int dp[602],i,j,k,w;
    double a;

    while(scanf("%d%d%d%d%d%d",&f[0],&f[1],&f[2],&f[3],&f[4],&f[5])==6)
    {
        if(!(f[0]||f[1]||f[2]||f[3]||f[4]||f[5]))   break;
        scanf("%lf",&a);
        w = (a*100.00+0.3);
        memset(fg,false,sizeof(fg));
        for(i=1;i<602;i++)  dp[i] = 500;
        fg[0] = true;
        dp[0]=0;

        for(i=0;i<6;i++)
        {
            for(j=0;j<f[i];j++)
                for(k=601;k>-1;k--)
                    if(fg[k] && k+c[i]<601 )
                    {
                        if(dp[k+c[i]] > dp[k]+1)
                            dp[k+c[i]] = dp[k]+1;
                        fg[k+c[i]] = true;
                    }
        }

        for(i=0;i<6;i++)
        {
            for(k=601;k>-1;k--)
                if(fg[k] && k-c[i]>=0 )
                {
                    if(dp[k-c[i]] > dp[k]+1)
                        dp[k-c[i]] = dp[k]+1;
                    fg[k-c[i]] = true;
                }
        }

        printf("%3d\n",dp[w]);
    }
    return 0;
}
