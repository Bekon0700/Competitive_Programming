#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define  sz1 26
#define  sz2 10
int n,pa[sz1],pc[sz2];
bool fc[sz2];
char ac[sz1];
vector<int>adj[sz1];

bool BPM(int A)
{
    int i,c;
    for(i=0;i<adj[A].size();i++)
    {
        c = adj[A][i];
        if(fc[c])
        {
            fc[c] = false;
            if(pc[c]==-1 || BPM(pc[c]))
            {
                pc[c] = A;
                pa[A] = c;
                return true;
            }
        }
    }
    return false;
}

void SOLVE()
{
    int i,j;
    bool out=false;

    memset(pa,-1,sizeof(pa));
    memset(pc,-1,sizeof(pc));

    for(i=0;i<n;i++)
    {
        memset(fc,true,sizeof(fc));
        if(!BPM(i))   out = true;
    }
    if(out) printf("!\n");
    else
    {
        for(i=0;i<10;i++)
            if(pc[i]!=-1)   printf("%c",ac[pc[i]]);
            else    printf("_");
        printf("\n");
    }
    for(i=0;i<26;i++)   adj[i].clear();
    n=0;
}

int main()
{
    //freopen("in.in","r",stdin);
    char a[100],ap[32],com[11],*p,c;
    int i,j,d,lc,la;
    n=0;

    while(gets(a))
    {
        if(a[0]=='\0')   SOLVE();
        else{
            p = strtok(a," ");
            strcpy(ap,p);
            p = strtok('\0'," ");
            strcpy(com,p);
            la = strlen(ap);
            lc = strlen(com)-1;
            d = ap[1]-48;
            c = ap[0];
            for(i=0;i<d;i++)
            {
                ac[n] = c;
                for(j=0;j<lc;j++)
                    adj[n].push_back(com[j]-48);
                n++;
            }
        }
    }
    SOLVE();
    return 0;
}
