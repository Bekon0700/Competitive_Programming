#include<stdio.h>
#include<string.h>

int main()
{
    int tks,sum,cnt,t,i,ks=1;
    char a[1010];

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%s",a);

        sum=cnt=t=0;

        for(i=0;a[i];i++)
        {
            sum+=a[i]-48;
            if(a[i]=='3'||a[i]=='9'||a[i]=='6') cnt++;
        }

        printf("Case %d: ",ks++);


        for(i=0;a[i];i++)
        {
            if(a[i]=='3'||a[i]=='9'||a[i]=='6') ;
            else   if((sum-a[i]+48)%3==0)
            {
                t=1;
                break;
            }
        }

        cnt+=t;
        if(cnt&1)printf("S\n");
        else printf("T\n");
    }

    return 0;
}
