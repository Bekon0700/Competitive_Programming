#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct{
    char na[50];
    int a,d;
}P;
P p[12];

bool com(P a, P b)
{
    if(a.a!=b.a)    return a.a>b.a;
    if(a.d!=b.d)    return a.d<b.d;
    if(strcmp(a.na,b.na)>0) return false;
    return true;
}

bool com1(P a, P b)
{
    if(strcmp(a.na,b.na)>0) return false;
    return true;
}


int main()
{
    int ks=1,i,j,k,l,t;

    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<10;i++)
            scanf("%s%d%d",p[i].na,&p[i].a,&p[i].d);
        sort(p,p+10,com);
        sort(p,p+5,com1);
        sort(&p[5],&p[10],com1);
        printf("Case %d:\n",ks++);
        printf("(%s, %s, %s, %s, %s)\n",p[0].na,p[1].na,p[2].na,p[3].na,p[4].na);
        printf("(%s, %s, %s, %s, %s)\n",p[5].na,p[6].na,p[7].na,p[8].na,p[9].na);
    }


    return 0;
}
