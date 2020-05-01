#include<stdio.h>

int k[91][2],STACK[20][2],TOP=0;

int f(char a[]) ;

int main()
{
    int i,n,x,y;
    char a[1000],b,c[3];

    scanf("%d",&n);

    for(i = 0 ; i < n ; ++ i )
    {
        scanf("%s%d%d",c,&x,&y);
        k[c[0]][0] = x ;
        k[c[0]][1] = y ;
    }
    while(scanf("%s",a) == 1)
    {
        if( a[0] != '(' )
        {
            printf("0\n");
            continue;
        }
        x=f(a);
        if(x)
            printf("%d\n",x);
        else
            printf("error\n");
    }
    return 0;
}

int f(char a[])
{
    int i = 0, x = 0 ;
    while( a[i] != '\0' )
    {
        if(a[i] > 64 && a[i] < 91  )
        {
            STACK [TOP][0] = k[a[i]][0];
            STACK [TOP ++][1] = k[a[i]][1];
        }
        if(a[i] == ')')
        {
            if( STACK [TOP - 2][1] != STACK [TOP - 1][0])
                return 0;
            x += ( STACK [TOP - 2][0] * STACK [TOP - 2][1] * STACK[TOP - 1][1] ) ;
            TOP -= 2;
            STACK [TOP][0] = STACK [TOP][0];
            STACK [TOP ++][1] = STACK [TOP + 1][1];
        }
        i ++ ;
    }
    return x;
}
