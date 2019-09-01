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


//#include<cmath>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;


typedef long long LL;

LL max(LL a,LL b){if(a>b)return a;
return b;
}

LL f(LL x)
{
    LL m=0;

    while(x)
    {
        m=max(x%10,m);
        x/=10;
    }
    return m;
}

LL v(LL a,LL b)
{
    if(!a)  return 0;

    return v(a/10,b)*b+a%10;
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);


    int i,k,a,b,c,tks,n,l,j,p;
    char x[10],y[10],z[10],s[10];

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%s",x);
        a=atoi(x);
        scanf("%s",s);
        scanf("%s",y);
        b=atoi(y);
        scanf("%s",s);
        scanf("%s",z);
        c=atoi(z);
        k=1;

        n=max(max(f(a),f(b)),f(c))+1;

        if(n==1)
        {
            printf("2\n");
            k=0;
        }
        else if(n==2 )
        {
            l = strlen(x)+strlen(y);
            if(l==strlen(z))
            {
                j=0;
                for(i=0;x[i];i++)   if(x[i]=='1')   j++;
                for(i=0;y[i];i++)   if(y[i]=='1')   j++;
                for(i=p=0;z[i];i++)   if(z[i]=='1')   p++;
                if(l==j && l==p)
                {
                    printf("1\n");
                    k=0;
                }
            }
        }


        for(i=n;i<=1000 && k;i++)
        {
            //printf("i:%d  %I64d  %I64d  %I64d\n",i,v(a,i)+v(b,i),v(c,i),v(c,i)-v(a,i)-v(b,i));
            if((LL)v(a,i)+(LL)v(b,i)==(LL)v(c,i))
            {
                //deb(i);
                k=0;
                printf("%d\n",i);
                break;
            }


        }

        if(k)   printf("0\n");

    }

    return 0;
}

