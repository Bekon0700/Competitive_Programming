#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct{int u,v,w;}E;
E   e[12000];

int dis[101][101],no[101][101],ne,y,x,K,par[101],rnk[101];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
char bo[100][100];

void BFS(int n,int I,int J)
{
    int i,j,cr,cc,r,c;
    queue<int>q;
    memset(dis,-1,sizeof dis);
    dis[I][J]=0;

    q.push(I);q.push(J);

    while(!q.empty())
    {
        cr=q.front();q.pop();
        cc=q.front();q.pop();

        for(i=0;i<4;i++)
        {
            r=cr+dx[i];
            c=cc+dy[i];
            if(r>-1 && c>-1 && r<y && c<x && bo[r][c]!='#' && dis[r][c] ==-1)
            {
                dis[r][c] = dis[cr][cc]+1;
                q.push(r);q.push(c);
            }
        }
    }

    for(I=0;I<y;I++)
        for(J=0;J<x;J++)
            if(no[I][J]>-1 && no[I][J]>n)
            {
                e[K].u = n;
                e[K].v = no[I][J];
                e[K].w = dis[I][J];
                K++;
            }

}

bool com(E a,E b){return a.w<b.w;}

int FS(int u)
{
    if(u!=par[u])   par[u] = FS(par[u]);

    return par[u];
}

void U(int u,int v)
{
    u = FS(u);
    v = FS(v);
    if(rnk[u]>rnk[v])   par[v]=u;
    else {
        par[u]=v;
        if(rnk[u]==rnk[v])  rnk[v]++;
    }
}

int Kruskel()
{
    sort(e,e+K,com);
    int i,cst=0;
    for(i=0;i<K;i++)
        if(FS(e[i].u)!=FS(e[i].v))
        {
            //printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
            cst+=e[i].w;
            U(e[i].u,e[i].v);
        }
    return cst;
}

int main()
{
    int T,i,j;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d\n",&x,&y);
        ne=K=0;
        memset(no,-1,sizeof no);
        for(i=0;i<y;i++)    gets(bo[i]);

        for(i=0;i<y;i++)
            for(j=0;j<x;j++)
                if(bo[i][j]=='A' || bo[i][j]=='S')
                    no[i][j] =  ne++;

        for(i=0;i<ne;i++)
        {
            par[i] = i;
            rnk[i] = 0;
        }

        for(i=0;i<y;i++)
            for(j=0;j<x;j++)
                if(no[i][j]!=-1)
                    BFS(no[i][j],i,j);

        printf("%d\n",Kruskel());
    }

    return 0;
}
