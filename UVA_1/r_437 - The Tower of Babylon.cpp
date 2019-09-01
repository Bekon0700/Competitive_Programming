#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>

using namespace std;

#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define MAX(a,b)    (a>b?a:b)
#define MIN(a,b)    (a<b?a:b)

typedef struct{int x,y,z;}UD;
UD a[180];

bool comp(UD a,UD b){return a.x>b.x;}

int main()
{
    int i,j,k,n,m,t=1,hlf,tot,o,max;

    while(cin>>n && n)
    {
        i=0;
        m = n*6;
        while(i<m)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i+1].x=a[i].x; a[i+1].y=a[i].z; a[i+1].z=a[i].y;
            a[i+2].x=a[i].y; a[i+2].y=a[i].x; a[i+2].z=a[i].z;
            a[i+3].x=a[i].y; a[i+3].y=a[i].z; a[i+3].z=a[i].x;
            a[i+4].x=a[i].z; a[i+4].y=a[i].x; a[i+4].z=a[i].y;
            a[i+5].x=a[i].z; a[i+5].y=a[i].y; a[i+5].z=a[i].x;
            i+=6;
        }

        sort(a,a+m,comp);
        fi(i,1,m){
            max=0;
            fd(j,i-1,-1)
                if(a[i].x<a[j].x&&a[i].y<a[j].y)    max=MAX(max,a[j].z);
            a[i].z+=max;
        }
        fi(i,0,m)max=MAX(max,a[i].z);
        cout<<"Case "<<t<<": maximum height = "<<max<<endl;
        t++;
    }
    return 0;
}


