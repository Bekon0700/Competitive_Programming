#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int re[22][1010];


void pc()
{
    int i,j,s,n,m;
    for(i=0;i<1001;i++) re[1][i]=i;
    for(s=2;s<21;s++)
        for(n=1;n<1001;n++)
        {
            re[s][n]=2000;
            for(m=0;m<n;m++)
                re[s][n]<?=max(re[s-1][m],re[s][n-1-m])+1;
        }
}

int main()
{
    pc();
    int tks,n,m;
    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",re[m][n]);
    }
    return 0;
}

