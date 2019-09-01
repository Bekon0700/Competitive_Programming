#include<iostream>
#include<string>
#include<cstdlib>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

map<string,int>M;

string w[220];
int nw,dis[220];
vector<int>vi[220];

bool DIS(string a,string b)
{
    int i,m=0,l;
    l = a.size();
    if((int)a.size()!=(int)b.size())    return false;

    for(i=0;i<l;i++)
    {
        if(a[i]!=b[i])  m++;
        if(m>1) return false;
    }

    return m==1;
}

int BFS(char a[],char b[])
{
    if(strcmp(a,b)==0)    return 0;

    int i,u,t;

    queue<int>q;
    memset(dis,-1,sizeof dis);
    u = M[a];
    t = M[b];
    dis[u]=0;
    q.push(u);

    while(!q.empty())
    {
        u = q.front();q.pop();
        //cout<<w[u]<<endl;
        for(i=0;i<vi[u].size();i++)
            if(dis[vi[u][i]]==-1)
            {
                if(vi[u][i] == t) return dis[u]+1;
                //cout<<"  "<<w[vi[u][i]]<<endl;
                dis[vi[u][i]] = dis[u]+1;
                q.push(vi[u][i]);
            }
    }
}

int main()
{
    int T,i,j,k,pr,kk;
    string s;
    char a[100],b[100],*p;
    //freopen("in.in","r",stdin);

    scanf("%d",&T);

    pr=0;

    while(T--)
    {
        nw=0;
        M.clear();

        while(scanf("%s",a)==1)
        {
            if(!strcmp(a,"*"))  break;
            w[nw]=a;
            M[w[nw]]=nw++;
        }
        for(i=0;i<nw;i++)   vi[i].clear();

        for(i=0;i<nw;i++)
            for(j=i+1;j<nw;j++)
                if(DIS(w[i],w[j]))
                {
                    vi[i].push_back(j);
                    vi[j].push_back(i);
                }

        gets(a);

        while(gets(a))
        {
            if(strlen(a)==0)    break;
            p  = strtok(a," ");
            strcpy(a,p);
            p  = strtok('\0'," ");
            strcpy(b,p);

            printf("%s %s %d\n",a,b,BFS(a,b));
        }
        if(T)   printf("\n");

    }

    return 0;
}

