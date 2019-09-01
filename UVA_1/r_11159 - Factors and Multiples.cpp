#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<int>V[100];
int par[101],col[101],A[101],B[101],n,m;

bool BPM(int u)
{
    int v,i;

    for(i=0;i<(int)V[u].size();i++)
    {
        v=V[u][i];
        if(col[v])
        {
            col[v]=0;
            if(par[v]==-1 || BPM(par[v]))
            {
                par[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int cs=1,T,i,j,cnt;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            V[i].clear();
        }

        scanf("%d",&m);
        for(i=0;i<m;i++)    scanf("%d",&B[i]);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(A[i]==B[j] || (A[i]&&B[j]%A[i]==0))
                    V[i].push_back(j);

        memset(par,-1,sizeof par);

        for(cnt=i=0;i<n;i++)
        {
            memset(col,1,sizeof col);
            if(BPM(i))  cnt++;
        }

        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}


