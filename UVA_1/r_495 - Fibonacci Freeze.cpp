#include<stdio.h>

int I=0;
char fib[5050][1000];

int main()
{
    int i,j,k,l,x,y,c;
    char a[5000],b[1100],z=48;

    for(i=0;i<1100;i++)
        a[i] = b[i] = z ;
    fib[I][0]='0';
    fib[I++][1]='\0';

    fib[I][0]=a[0]='1';
    fib[I++][1]='\0';
    fib[I][0]=a[0]='1';
    fib[I++][1]='\0';
    b[0]='1';
    l=1;
    for(k=2;k<5000;k++)
    {
        c=0;

        for(i=0;i<l || c != 0 ;i++)
        {
            x= a[i] + b[i] + c - 2*z;
            b[i] = a[i];
            a[i] = x% 10 +z ;
            c = x/ 10 ;
        }
        l = i ;
        for(i--,j=0;i > -1;i--,j++)
            fib[I][j]=a[i];
        fib[I++][j]='\0';
    }
    while(scanf("%d",&k)==1)
        printf("The Fibonacci number for %d is %s\n",k,fib[k]);


    return 0 ;
}
