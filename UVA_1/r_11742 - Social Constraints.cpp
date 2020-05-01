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

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;

    int i,j,t,cnt,n,m;
    int a[8],b[8];
    int u[20],v[20],c[20];

    while(scanf("%d%d",&n,&m)==2 &&(n||m))
    {
        for(i=0;i<m;i++)
            scanf("%d%d%d",u+i,v+i,c+i);

        for(i=0;i<n;i++)    a[i]=i;

        cnt=0;

        do{
            t=1;
            for(i=0;i<n;i++)    b[a[i]]=i;

            for(i=0;i<m && t;i++)
                if(c[i]>0 && abs(b[u[i]]-b[v[i]])>c[i]) t=0;
                else if(c[i]<0 && abs(b[u[i]]-b[v[i]])<-c[i]) t=0;

            cnt+=t;

        }while(next_permutation(a,a+n));

        printf("%d\n",cnt);
    }


    return 0;
}




