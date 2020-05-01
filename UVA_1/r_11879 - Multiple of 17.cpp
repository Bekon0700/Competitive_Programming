#include<stdio.h>
#include<string.h>

char a[1000000];

int main()
{
    int x,i;

    while(gets(a)&& strcmp(a,"0"))
    {
        x=0;
        for(i=0;a[i];i++)
        {
            x=x*10+a[i]-48;
            x%=17;
        }
        if(x)   printf("0\n");
        else printf("1\n");
    }

    return 0;
}
