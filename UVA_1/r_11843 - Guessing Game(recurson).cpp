#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int re[22][1010];

int go(int s,int n)
{
    if(re[s][n]>-1)  return re[s][n];
    if(s==1)    return re[s][n]=n;
    if(n==0)    return re[s][n]=0;

    int m=2000,i;

    for(i=0;i<n;i++)
        m <?=1+max(go(s-1,i),go(s,n-1-i));
        go(s-1,n);
    return re[s][n]=m;
}

int main()
{
    memset(re,-1,sizeof re);
    go(20,1000);
    int tks,n,m;
    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",re[m][n]);
    }
    return 0;
}

