#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define LL          long long
#define p2(a)       (1LL<<a)

struct T{
    char co;
    char ti[3][3];
    int s,r,c;
    T(){}
    T(char coo,char a[],char b[],int n,int rr,int cc)
    {
        co=coo;
        strcpy(ti[0],a);
        strcpy(ti[1],b);
        s=n;
        r=rr;
        c=cc;
    }
};

T t[7];
int n,m;
char bo[10][22];
const LL  M = 50431;
LL mm[22][256][256];


void Initialize()
{

    t[0]=T('R',"*.","**",3,2,2);
    t[1]=T('G',".*","**",3,2,2);
    t[2]=T('B',"**","*.",3,2,2);
    t[3]=T('N',"**",".*",3,2,2);
    t[4]=T('W',"*.","*.",2,2,1);
    t[5]=T('P',"**","..",2,1,2);
    t[6]=T('L',"*.","..",1,1,1);
}


LL go(int r,int c,int msk,int nxt)
{
    if(c==m)    return 1;
    if(r==n)    return go(0,c+1,nxt,0);
    if(msk&p2(r))   return go(r+1,c,msk,nxt);

    LL &re=mm[c][msk][nxt];
    if(re>-1)   return re;
    re=0;
    int cnxt,cmsk,tl,i,j,cnt;

    if(bo[r][c]=='#')   return re=go(r+1,c,msk|p2(r),nxt);


    ///Tiles 1 Start
    tl=1;
    cnxt=nxt;
    cmsk=msk;
    cnt=0;
    ///      *
    ///  -> **

    for(i=r-1;i<=r;i++)
        for(j=c;j<t[tl].c+c;j++)
        {
            if(i<0 || j<0||i>=n||j>=m)  continue;

            if(c==j && (msk&p2(i)) && t[tl].ti[i-r+1][j-c]=='*')  continue;
            else if(c!=j && (nxt&p2(i)) && t[tl].ti[i-r+1][j-c]=='*')  continue;

            if(bo[i][j]=='.' || bo[i][j]==t[tl].co)
            {
                if(t[tl].ti[i-r+1][j-c]=='*')
                {
                    cnt++;
                    if(c==j)   cmsk|=p2(i);
                    else cnxt|=p2(i);
                }
            }
        }

    if(cnt==t[tl].s)
        re = (re+go(r+1,c,cmsk,cnxt))%M;

    ///Tile 1 End

    for(tl=0;tl<7;tl++) if(tl!=1)
    {
        cnxt=nxt;
        cmsk=msk;
        cnt=0;

        for(i=r;i<t[tl].r+r;i++)
            for(j=c;j<t[tl].c+c;j++)
            {
                if(i>=n||j>=m)  continue;
                if(c==j && (msk&p2(i)) && t[tl].ti[i-r][j-c]=='*')  continue;
                else if(c!=j && (nxt&p2(i)) && t[tl].ti[i-r][j-c]=='*')  continue;
                if(bo[i][j]=='.' || bo[i][j]==t[tl].co)
                {
                    if(t[tl].ti[i-r][j-c]=='*')
                    {
                        cnt++;
                        if(c==j)   cmsk|=p2(i);
                        else cnxt|=p2(i);
                    }
                }
            }

        if(cnt==t[tl].s){
            re = (re+go(r+1,c,cmsk,cnxt))%M;
        }
    }
    return re;
}


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;

    int i,j,k,l,tks,ks=1;
    int re;

    Initialize();
    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)    scanf("%s",bo[i]);

        memset(mm,-1,sizeof mm);
        re = go(0,0,0,0);
        printf("Case %d: %d\n",ks++,re);
    }
    return 0;
}






