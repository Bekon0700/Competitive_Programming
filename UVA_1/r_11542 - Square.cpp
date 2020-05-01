#include<stdio.h>
#include<algorithm>
using namespace std;

#define SIZE_N 520
#define SIZE_P 100
#define p2(a)   (1LL<<a)

bool flag [SIZE_N];
int prime [SIZE_P],np;

void sieve ()
{
	int i, j, r, c = 0;

	for ( i = 3; i < SIZE_N; i += 2 )
        flag[i] = true ;
	flag [2] = true ;

	prime [c++] = 2 ;

	for ( i = 3; i <SIZE_N; i += 2 )
        if ( flag[i] )
		{
			prime[c++] = i ;

            if ( SIZE_N/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <SIZE_N; j += r )
                    flag[j] = false ;
            }
            //printf("%d\n",prime[c-1]);
		}
    np=c;
    //printf("%d %d\n",c,prime[c-1]);
}

long long x,gf[100][2];

int main()
{
    //freopen("in.in","r",stdin);

    sieve();
    int ks,n,i,j,r;

    scanf("%d",&ks);

    while(ks--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            gf[i][0]=gf[i][1]=0;
            scanf("%lld",&x);
            //scanf("%I64d",&x);
            for(j=0;j<np;j++)
                if(x%prime[j]==0)
                {
                    r=0;
                    while(x%prime[j]==0)
                    {
                        x/=prime[j];
                        r++;
                    }
                    if(r&1) (j<50?gf[i][0]|=p2(j):gf[i][1]|=p2(j-50));
                }
            //printf("%d : %I64d\n",i,gf[i][0]);
        }



        for(r=i=0;i<np;i++)
        {
            j=r;
            while(j<n && !((i<50)?(gf[j][0]&p2(i)):(gf[j][1]&p2(i-50))))  j++;


            if(j<n)
            {
                swap(gf[j][0],gf[r][0]);
                swap(gf[j][1],gf[r][1]);
            }
            else continue;

            //printf("gf: %I64d  %d\n",gf[r][0],j);
            if(i<50?!(gf[r][0]&p2(i)):!(gf[r][1]&p2(i-50)))    continue;

            for(j=r+1;j<n;j++)
            {
                if((i<50)?(gf[j][0]&p2(i)):(gf[j][1]&p2(i-50)))
                {
                    gf[j][0]^=gf[r][0];
                    gf[j][1]^=gf[r][1];
                }
            }
            r++;
        }

        //printf("r:%d n:%d\n",r,n);
        printf("%lld\n",p2(n-r)-1);
        //printf("%I64d\n",p2(n-r)-1);
    }

    return 0;
}

