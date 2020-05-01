#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define MAX(a,b)    (a>b?a:b)
#define MIN(a,b)    (a<b?a:b)

bool dp[22501];
int num[22501];
int a[100];
bool comp(int a,int b){return a>b;}
int main()
{
    int i,j,k,n,m,t,hlf,tot,o,max;


    cin>>t;
    while(t--)
    {
        cin>>n;
        tot=max=0;
        fi(i,0,n)   {
            cin>>a[i];
            tot+=a[i];
            }
        memset(dp,false,sizeof(dp));
        memset(num,0,sizeof(num));
        sort(&a[0],&a[n],comp);
        dp[0] = true;
        hlf = tot/2;
        if(tot&1)   hlf++;
        m=n/2;
        if(n&1) o=1;    else o=0;

        //fi(i,0,n)   cout<<a[i]<<" ";

        fi(i,0,n)fd(j,hlf,-1)
            if(dp[j] && j+a[i]<=hlf)
            {
                dp[ j+a[i] ]  = true ;
                num[j+a[i]] = MAX(num[j+a[i]],num[j]+1);
                if(num[j+a[i]] == m || num[j+a[i]] == m+o)
                    max=MAX(max,j+a[i]);
            }
            cout<<MIN(max,tot-max)<<" "<<MAX(max,tot-max)<<endl;
	if(t)	cout<<endl;
    }
    return 0;
}

