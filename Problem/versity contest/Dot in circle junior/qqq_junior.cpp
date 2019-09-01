#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
double res;

int main(){

//    freopen("in2.txt","r", stdin);
//    freopen("out2.txt","w", stdout);
    int tk,cs=1,r,n;
    scanf("%d",&tk);
    while(tk--){
        scanf("%d%d",&r,&n);
        double A = pi*r*r;
        double B = A / (double)n;
        B = B*2.0;
        res = B/A;
        printf("Case %d : %.6f\n",cs++,res);

    }
    return 0;
}

