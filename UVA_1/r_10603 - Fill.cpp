#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int dis[201][201][201];
bool col[201][201][201];

struct pq{
    int a[3],tt;
    bool operator<(const pq &b)const{return tt>b.tt;}
    void up(int ca,int cb,int cc,int ctt){    a[0]=ca;a[1]=cb;a[2]=cc;tt=ctt;}
};

int DIJ(int ca[],int &d)
{
    int m=0,i,j,sh,val=0,oo;
    pq u,v;
    priority_queue<pq>q;

    memset(dis,60,sizeof dis);
    memset(col,true,sizeof col);
    oo=dis[0][0][0];

    if(ca[2]<=d && ca[2]>m) m=ca[2];

    dis[0][0][ca[2]]=0;
    u.up(0,0,ca[2],0);
    q.push(u);

    while(!q.empty())
    {
        u = q.top();q.pop();

        if(!col[u.a[0]][u.a[1]][u.a[2]])    continue;
        col[u.a[0]][u.a[1]][u.a[2]]=false;

        for(i=0;i<3;i++)    for(j=0;j<3;j++)    if(i!=j)
        {
            v=u;
            sh  = min(v.a[i],ca[j]-v.a[j]);
            if(!sh) continue;
            v.a[i]-=sh;
            v.a[j]+=sh;
            v.tt+=sh;
            if(v.tt < dis[v.a[0]][v.a[1]][v.a[2]])
            {
                dis[v.a[0]][v.a[1]][v.a[2]] = v.tt;
                q.push(v);

                if(v.a[i]<=d && v.a[i]>m)   m=v.a[i],val=oo;
                if(v.a[j]<=d && v.a[j]>m)   m=v.a[j],val=oo;
                if(m==v.a[i])   val<?=v.tt;
                if(m==v.a[j])   val<?=v.tt;
            }
        }
    }

    d=m;
    return val;
}


int main()
{
    int T,a[3],d,i;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d);
        printf("%d %d\n",DIJ(a,d),d);
    }
    return 0;
}
