#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define fi(i,a,b)   for(i=1;i<b;i++)

int col[101],dis[101],sam[101],nsam,ESZ,st;
vector<int> adj[101],cst[101],par[101],an[101];
vector<bool>ec[101];
int s[101];

struct pq{
    int n,d;
    bool operator <(const pq & b)const
    {
        return d>b.d;
    }
};

typedef struct{int u,v,w;} edg;
edg E[10300];

bool com(edg a,edg b)
{
    if(a.u!=b.u)    return a.u<b.u;
    return a.v<b.v;
}

void DIS(int so,int n)
{
    memset(dis,60,sizeof(dis));
    memset(col,true,sizeof(col));
    int i,j,vn,vd;
    fi(i,1,n+1) { par[i].clear(); an[i].clear();}
    pq u,v;
    priority_queue<pq>q;


    u.n = so;
    u.d=dis[u.n] = 0;
    q.push(u);

    while(!q.empty())
    {
        u  = q.top();   q.pop();
        if(!col[u.n])   continue;
        col[u.n] = false;
        for(i=0;i<(int)adj[u.n].size();i++)
            if(ec[u.n][i]&& col[adj[u.n][i]])
            {
                if(dis[adj[u.n][i]] > u.d+cst[u.n][i])
                {
                    v.n = adj[u.n][i];
                    par[v.n].clear();
                    an[v.n].clear();

                    par[v.n].push_back(u.n);
                    an[v.n].push_back( i);
                    v.d = dis[v.n] = u.d + cst[u.n][i] ;
                    q.push(v);
                }
                else if(dis[adj[u.n][i]] == u.d+cst[u.n][i])
                {
                    v.n = adj[u.n][i];
                    par[v.n].push_back(u.n);
                    an[v.n].push_back( i);
                    v.d = dis[v.n] = u.d + cst[u.n][i] ;
                    q.push(v);
                }
            }
    }
}

void pp(int u)
{
    if(u==st)   return ;

    for(int i=0;i<(int)par[u].size();i++)
    {
        pp(par[u][i]);
        if(ec[par[u][i]][an[u][i]])
        {
            ec[par[u][i]][an[u][i]] = false;
            E[ESZ].u = u;
            E[ESZ].v = par[u][i];
            E[ESZ].w = cst[par[u][i]][an[u][i]];
            ESZ++;
        }
    }
}

int main()
{
    //freopen("in2.in","r",stdin);
    int ks=1,t,i,j,k,u,v,w,n,m,ed,oo=1010580540,no,last;


    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&ed);
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            cst[i].clear();
            ec[i].clear();
        }

        for(i=0;i<ed;i++)
            scanf("%d",&s[i]);
        scanf("%d",&st);
        //for(i=0;i<ed;i++)   printf("%d\n",s[i]);
        while(m--)
        {
            scanf("%d%d%d",&v,&u,&w);
            adj[u].push_back(v);
            cst[u].push_back(w);
            ec[u].push_back(true);
        }
        printf("Case %d:\n",ks++);

        ESZ=last=0;
        no=1;

        while(true)
        {
            DIS(st,n);
            m = oo ;
            nsam=0;
            for(i=0;i<ed;i++)
                if(dis[s[i]]<m)
                {
                    nsam=0;
                    m = dis[s[i]];
                    sam[nsam++] = s[i];
                }
                else if(dis[s[i]]==m && m<oo)
                {
                    sam[nsam++] = s[i];
                }
            //for(i=0;i<ed;i++)    printf("\t\tsam: %d\n",s[i]);
            if(!nsam)   break;
            last = dis[sam[0]];
            printf("The path cost is %d\n",last);
            for(i=0;i<nsam;i++)
                pp(sam[i]);
            sort(E,E+ESZ,com);
            for(i=0;i<ESZ;i++)
                printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
            ESZ=0;
            no=0;
        }
        if(no)  printf("No road to block\n");

    }
    return 0;
}

/*
INPUT :

8

2 1 1
1 2
2 1 10

3 5 2
1 3 2
2 1 10
1 2 20
1 2 20
1 2 30
3 2 30

4 4 2
1 2 4
1 4 10
2 4 10
1 3 20
3 4 10

3 2 2
1 2 3
1 2 3
2 3 3

3 5 2
1 3 2
2 1 10
1 2 20
1 2 20
1 2 30
3 2 30

7 9 2
1 2 7
1 4 10
1 3 5
2 3 5
3 4 5
4 5 5
4 6 5
5 7 5
6 7 5
4 7 11

7 8 2
1 2 7
1 3 5
2 3 5
2 3 6
3 4 5
4 5 5
4 6 5
5 7 5
6 7 5

4 4 2
1 2 4
1 4 10
2 4 10
1 3 20
3 4 10

*/
