#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

typedef struct {int u,v;double d;}E;
E e[250010];

bool com(E a,E b){return a.d<b.d;}

int rnk[500],par[500];

void ini(int n)
{
    int i;
    for(i=0;i<n;i++)
        rnk[i]=0,par[i]=i;
}

int FS(int u)
{
    if(par[u]!=u)
        par[u]=FS(par[u]);

    return par[u];
}

void L(int u,int v)
{
    if(rnk[u]>rnk[v])   par[v]=u;
    else par[u]=v;
    if(rnk[v]==rnk[u])  rnk[v]++;
}


double x[500],y[500];


int main()
{
    int tks,i,j,ne,n,s,c;
    double ans;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&s,&n);

        ini(n);

        ne=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            for(j=i-1;j>-1;j--)
            {
                e[ne].u=i,e[ne].v=j;
                e[ne].d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                ne++;
            }
        }
        sort(e,e+ne,com);

        for(c=i=0;i<ne;i++)
        {
            if(FS(e[i].u)!=FS(e[i].v))
            {
                L(FS(e[i].u),FS(e[i].v));
                c++;
                if(n-s==c)
                {
                    printf("%.2lf\n",e[i].d);
                    break;
                }
            }

        }
    }

    return 0;
}



