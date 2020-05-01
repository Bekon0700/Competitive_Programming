#include    <stdio.h>
#include    <string.h>
#include    <math.h>
#include    <stdlib.h>


char a[1000002];

int main()
{
    int i,j,k,l,x;

    while(scanf("%s",a)==1 && strcmp(a,"END"))
    {
        i=1;
        x = strlen(a);
        if(x<10)
            l = atol(a);
        else l = - 1 ;
        while(x != l)
        {
                l = x ;
                x = log10(x) + 1 ;
				
                i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
