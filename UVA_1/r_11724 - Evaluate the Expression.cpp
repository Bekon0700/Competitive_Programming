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
#define MEM(a,b)     memset(a,b,sizeof(a))
//class { public:};

int mat[127][27],id[127],res,N,val[127],dg[127];
bool al[127];
string s;

void EXP()
{
    int a,b,i;
    res = 0;
    stack<char>stk;
    string sst;

    sst.clear();
    stk.push('(');
    s += ')';
    fi(i,0,s.size())
        if(isalpha(s[i]))
            sst += s[i];
        else if(s[i] == '(')
            stk.push('(');
            else if(s[i] == '+')
            {
                while(stk.top()!='(')
                {
                    sst += stk.top();
                    stk.pop();
                }
                stk.push('+');
            }
            else if(s[i]=='*')
            {
                if(stk.top()=='*')
                {
                    sst += stk.top();
                    stk.pop();
                }
                stk.push('*');
            }
            else if(s[i]==')')
            {
                while(stk.top()!='(')
                {
                    sst += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
    //cout<<sst<<endl;
    stack<int>ss;
    fi(i,0,sst.size())
        if(isalpha(sst[i]))
        {
            ss.push(val[sst[i]]);
        }
        else if(sst[i]=='*'){
            a = ss.top();ss.pop();
            b = ss.top();ss.pop();
            ss.push(a*b);
        }
        else if(sst[i]=='+'){
            a = ss.top();ss.pop();
            b = ss.top();ss.pop();
            ss.push(a+b);
        }
    res = ss.top();
    return;
}

bool BFS()
{
    int q[27],f,r,i,j,u,v;
    res  = -1;

    f= r =0;
    fi(i,96,126)
    if(al[i] && ! id[i])
    {
        q[r++] = i;
        val[i] = 1;
    }
    while(f<r)
    {
        u = q[f++];

        fi(i,0,dg[u])
        {
            id[mat[u][i]]--;
            if(!id[mat[u][i]])
            {
                val[mat[u][i]] = val[u]+1;
                q[r++] = mat[u][i];
            }
        }
    }
    //fi(i,0,r)   cout<<(char)q[i]<<" "<<val[q[i]]<<"\t";    cout<<endl;
    if(r!=N)
        return false;
        res=0;
    EXP();
    return true;;
}

int main(){
    string sst;
    int i,j,k,t=1,T,exp,n;

    set<char>S;
    cin>>T;

    while(T--)
    {
        cin>>s>>n;
        S.clear();
        MEM(id,0);
        MEM(al,false);
        MEM(val,0);
        MEM(dg,0);

        fi(i,0,s.size())
            if(isalpha(s[i]))
            {
                S.insert(s[i]);
                al[s[i]] = true;
            }
        N = S.size();
        fi(i,0,n)
        {
            sst.clear();
            cin>>sst;
            id[sst[0]]++;
            mat[sst[2]][dg[sst[2]]++] = sst[0];
        }
        if(BFS())
            cout<<"Case "<<t++<<": "<<res<<endl;
        else cout<<"Case "<<t++<<": "<<res<<endl;
    }
    return 0;   }



