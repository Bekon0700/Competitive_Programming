#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

typedef struct {int x,y;}P;
P M(P a,P b){b.x-=a.x;b.y-=a.y;return b;}
int C(P a,P b){return a.x*b.y-a.y*b.x;}


int main()
{
    int i,j,k,l,tks,ks=1,n;
    P a,b,c,d;
    double A1,A2,B1,B2,C1,C2,x,y;

    scanf("%d",&tks);
    printf("INTERSECTING LINES OUTPUT\n");

    while(tks--)
    {
        scanf("%d%d%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);

        if(C(M(a,b),M(c,d))==0)
        {
            if(C(M(a,b),M(a,d))==0 && C(M(a,b),M(a,c))==0)  printf("LINE\n");
            else printf("NONE\n");
        }else {
            A1=a.y-b.y;B1=b.x-a.x;C1=a.x*b.y-a.y*b.x;
            A2=c.y-d.y;B2=d.x-c.x;C2=c.x*d.y-c.y*d.x;
            x = (B1*C2-B2*C1)/(A1*B2-A2*B1);
            y = (C1*A2-C2*A1)/(A1*B2-A2*B1);
            printf("POINT %.2lf %.2lf\n",x,y);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}



