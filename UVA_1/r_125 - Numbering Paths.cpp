#include<iostream>

using namespace std;

typedef long long ll;
int mat[35][35];
bool cyc[35];

void FW(int n)
{
    int i,j,k;

    for(k=0;k<=n;k++)
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                if(mat[i][k] && mat[k][j])
                    mat[i][j]+=mat[i][k]*mat[k][j];

    for(i=0;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(mat[i][j] && mat[j][i])
                cyc[j]=cyc[i]=true;

    for(k=0;k<=n;k++)
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                if(mat[i][k] && mat[k][j] &&cyc[k])
                    mat[i][j]=-1;

}

int main()
{
    int i,j,n,u,v,m,ks=0;

    while(scanf("%d",&m)==1)
    {
        memset(cyc,false,sizeof cyc);
        memset(mat,0,sizeof mat);

        for(n=i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            n>?=u;
            n>?=v;
            mat[u][v]++;
        }
        FW(n);
        printf("matrix for city %d\n",ks++);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(j)   printf(" ");
                if((cyc[i] ||  cyc[j] )&& mat[i][j]) printf("-1");
                else printf("%d",mat[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
