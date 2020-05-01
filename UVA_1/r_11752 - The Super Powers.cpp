#include<iostream>
#include<algorithm>

using namespace std;

unsigned long long a[68000];
int end;
int l[]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55,56,57,58,60,62,63,64};

int main(){
    unsigned long long  i,j,x,O,m,k,b,c;


    O = 18446744073709551615LL;
    end=0;
    a[end++]=1;

    for(i=2;i<65536;i++)
    {
        x=1;
        j=0;
        for(k=1;true;k++)
        {
            if(!(O/i>x)) break;
            x *= i;
            if(k==l[j]){
                j++;
                a[end++] = x;
            }
        }
    }
    sort(&a[0],&a[end]);

    printf("1\n");
    for(i=1;i<end;i++)if(a[i-1]!=a[i])    printf("%llu\n",a[i]);

    return 0;
}
