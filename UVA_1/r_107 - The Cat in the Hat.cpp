#include<stdio.h>
#include<math.h>

bool F(int x,int y,int k)
{
    while(x%(k+1)==0 && y%k==0 )
    {
        x /= k+1;
        y /=k;
        if(x==1 && y==1)    return true;
    }

    return false;
}

int main()
{
    int i,j,k,l,n,m,x;

    while(scanf("%d%d",&n,&m)==2 && (n||m))
    {
        x = sqrt(m)+1;
        k=0;
        for(i=1;i<=x;i++)
            if(F(n,m,i))
            {
                k=i;
                break;
            }
        if(!k)  k = m;
        j = 0;l =m;
        x = 1;

        while(n!=1)
        {
            m/=k;
            j+=m;
            l+=n*x;
            n/=k+1;
            x *= k;

        }

        printf("%d %d\n",j,l);
    }

    return 0;
}

