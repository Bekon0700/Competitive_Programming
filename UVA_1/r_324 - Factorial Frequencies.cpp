#include<stdio.h>

int I = 1,D[380][10];

int main()
{
    char a[850],z ='0';
    int i,j,k,x,y,c,l;

    for(i=0;i<850;++i)
        a[i] = z;
    for(i=1;i<380;i++)
        D[i][0] = D[i][1] = D[i][2] =D[i][3] =D[i][4] =D[i][5] =D[i][6] =D[i][7] =D[i][8] =D[i][9] = 0;
    a[0]='1';
    l = 1 ;
    D[I++][1] = 1 ;
    for( k = 2 ; k < 380 ; k ++ )
    {
        c = 0 ;
        for( i = 0 ; i < l || c != 0 ; i ++ )
        {
            x = a[i] - z ;
            x *= k ;
            x += c ;
            a[i] = x % 10 + z;
            c = x / 10 ;
        }
        l = i ;
        for(j = 0 ; j < i ;++j)
            D[I][a[j]-z] ++ ;
        I ++ ;
    }
    while(scanf("%d",&i)&& i)
    {
        printf("%d! --\n",i);
        printf("    (0)%5d",D[i][0]);
        printf("    (1)%5d",D[i][1]);
        printf("    (2)%5d",D[i][2]);
        printf("    (3)%5d",D[i][3]);
        printf("    (4)%5d\n",D[i][4]);
        printf("    (5)%5d",D[i][5]);
        printf("    (6)%5d",D[i][6]);
        printf("    (7)%5d",D[i][7]);
        printf("    (8)%5d",D[i][8]);
        printf("    (9)%5d\n",D[i][9]);
    }
    return 0 ;
}





