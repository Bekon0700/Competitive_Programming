#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>

using namespace std;


int main()
{
    int i,d,tks,ks=1;
    char a[22];

    map<string,int>mp;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&i);
        mp.clear();

        while(i--)
        {
            scanf("%s%d",a,&d);
            mp[a]=d;
        }
        scanf("%d%s",&d,a);

        printf("Case %d: ",ks++);

        if(mp.find(a)!=mp.end())
        {
            i = mp[a];
            if(i<=d)    printf("Yesss\n");
            else if(i<=d+5) printf("Late\n");
            else printf("Do your own homework!\n");
        }
        else printf("Do your own homework!\n");
    }
    return 0;
}

