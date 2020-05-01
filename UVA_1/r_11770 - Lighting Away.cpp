#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>v1[10001];

int f[10001],cv;
bool col[10001];

void d1(int x)
{
    int i;
    col[x] = false;

    for(i=0;i<v1[x].size();i++)
        if(col[v1[x][i]])
            d1(v1[x][i]);
    f[++cv] = x;
}

void d2(int x)
{
    int i;
    col[x] = false;

    for(i=0;i<v1[x].size();i++)
        if(col[v1[x][i]])
            d2(v1[x][i]);
}

int main()
{
    int cs=1,t,i,cnt,n,m,u,v;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)   v1[i].clear();

        while(m--)
        {
            scanf("%d%d",&u,&v);
            v1[u].push_back(v);
        }
        memset(col,true,sizeof(col));
        cv=-1;
        for(i=1;i<=n;i++)   if(col[i])  d1(i);
        memset(col,true,sizeof(col));

        for(i=cv,m=0;i>-1;i--)
            if(col[ f[i] ])
            {
                d2(f[i]);
                m++;
            }
        printf("Case %d: %d\n",cs++,m);
    }
    return 0;
}
