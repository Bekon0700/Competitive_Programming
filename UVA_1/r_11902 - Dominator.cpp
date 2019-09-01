#include<stdio.h>
#include<string.h>

int mat[100][100],col[100],amat[100][100],n;

void dfs(int u)
{
    for(int i=0;i<n;i++)
        if(mat[u][i]&&col[i]==-1)
        {
            col[i]=1;
            dfs(i);
        }
}

int main()
{
    int t,ks=1,i,j,k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&mat[i][j]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                amat[i][j]=mat[i][j];
            amat[i][i]=1;
        }

        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    if(amat[i][k]&&amat[k][j])
                        amat[i][j]=1;


        printf("Case %d:\n",ks++);

        printf("+");    for(i=1;i<2*n;i++)  printf("-");    printf("+\n");

        printf("|");
        for(i=0;i<n;i++)
            if(amat[0][i])   printf("Y|");
            else printf("N|");
        printf("\n+");    for(i=1;i<2*n;i++)  printf("-");    printf("+\n");

        for(k=1;k<n;k++)
        {
            memset(col,-1,sizeof col);

            col[0]=1;
            col[k]=-2;
            dfs(0);
            printf("|");
            for(i=0;i<n;i++)
                if(amat[0][i]&&col[i]<0)   printf("Y|");
                else printf("N|");

            printf("\n+");    for(i=1;i<2*n;i++)  printf("-");    printf("+\n");
        }
    }

    return 0;
}
