#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define	fi(i,a,b)	for(i=a;i<b;i++)
#define	fd(i,a,b)	for(i=a;i>b;--i)
#define	ri(i,a)		for(i=0;i<b;i++)
#define	rd(i,a)		for(i=a;i>-1;--i)
#define PP(a,b)     (cout<<a<<b)
#define oo           2000000

int jon[1000][1000],fire[1000][1000],nr,nc;
char maz[1000][1001];
int ii[]={1,-1,0,0},
    jj[]={0,0,1,-1};

void bfs_fire(int r,int c)
{
    int i,ui,uj;
    queue<int>q;

    q.push(r);
    q.push(c);
    fire[r][c] = 0;

    while(!q.empty())
    {
        ui=q.front(); q.pop();
        uj=q.front(); q.pop();

        fi(i,0,4)
        {
                r = ui+ii[i];
                c = uj+jj[i];
                if(maz[r][c] == '.' && fire[r][c] > fire[ui][uj]+1 )
                {
                        fire[r][c]= fire[ui][uj]+1;
                        q.push(r);
                        q.push(c);
                }
        }
    }
}

int bfs_jon(int r,int c)
{
    int i,ui,uj;
    queue<int>q;

    q.push(r);
    q.push(c);
    jon[r][c] = 0;
    if(!r || !c || r == nr-1 || c == nc-1)  return jon[r][c]+1;

    while(!q.empty())
    {
        ui=q.front();q.pop();
        uj=q.front();q.pop();
        fi(i,0,4)
        {
                r = ui+ii[i];
                c = uj+jj[i];
                if(maz[r][c]=='.' && fire[r][c] > jon[ui][uj]+1)
                {
                        jon[r][c]= jon[ui][uj]+1;
                        if((!r || !c) ||( r == nr-1 || c == nc-1))
                            return jon[r][c]+1;

                        maz[r][c]= 'J' ;
                        q.push(r);
                        q.push(c);
                }
        }
    }
    return 0;
}

int main(){
    int t,i,j,k;

    cin>>t;
    while(t--)
    {
            cin>>nr>>nc;
            fi(i,0,nr)
            scanf("%s",maz[i]);

        fi(i,0,nr)fi(j,0,nc) fire[i][j]=oo;
        fi(i,0,nr)fi(j,0,nc)if(maz[i][j]=='F')  bfs_fire(i,j);
        fi(i,0,nr)fi(j,0,nc)if(maz[i][j]=='J'){

            k=bfs_jon(i,j);
            i=nr;
            break;}


        if(k)
            cout<<k<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}



