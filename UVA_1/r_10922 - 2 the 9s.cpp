#include<iostream>

using namespace std;

int dg9(int c)
{
    if(c==9)    return 1;
    int s=0;
    while(c)
    {
        s+=c%10;
        c/=10;
    }
    return 1+dg9(s);
}

int main()
{
    int i,s;
    char a[1004];

    while(scanf("%s",a)==1 && a[0]!='0')
    {
        for(i=s=0;a[i];i++)
            s+=a[i]-48;
        if(s%9) printf("%s is not a multiple of 9.\n",a);
        else printf("%s is a multiple of 9 and has 9-degree %d.\n",a,dg9(s));


    }

    return 0;
}

