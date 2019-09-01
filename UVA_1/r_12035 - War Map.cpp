#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std;

int d[22],n,sum,l[22],r[22];
bool f;
bool com(const int &a,const int &b){return a>b;}
int mm[(1<<20)+10];

void go(int msk,int v,int s,int cnt,int mx)
{
    if(f || v>sum || mx>n-cnt)   return ;

    if(v==sum)
    {
        int i,j,k;

        for(i=j=k=0;i<n;i++)
        {
            if(0==(msk&(1<<i))) r[k++] = d[i];
            else l[j++] = d[i];
        }

        for(i=0;i<cnt;i++)
        {
            sort(r,r+k,com);
            for(j=0;j<k && l[i];j++)
                if(r[j])    r[j]--,l[i]--;
                else return ;
        }
        f = true;

        return ;
    }

    for(int i=s;i<n;i++)
        if((msk&(1<<i))==0)
            go(msk|(1<<i),v+d[i],i+1,cnt+1,max(mx,d[i]));
}

int main()
{
    int ks=1,i,tks;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);
        for(sum=i=0;i<n;i++)
        {
            scanf("%d",d+i);
            sum+=d[i];
        }
        printf("Case %d: ",ks++);
        if(sum&1)   {printf("NO\n");continue;}

        f = false;

        sum/=2;
        sort(d,d+n,com);

        while(d[n-1]==0 && n>2)
            n--;
        go(0,0,0,0,0);

        if(f)   printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
