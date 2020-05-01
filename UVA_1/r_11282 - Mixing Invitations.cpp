#include<iostream>
using namespace std;


long long de[23],bc[23][23];
int main()
{
    long long i,j,n,m,an;

    de[0]=1;
    de[1]=0;de[2]=1;
    for(i=3;i<21;i++) de[i] = (de[i-1]+de[i-2])*(i-1);


    for(i=0;i<22;i++)
        for(j=0;j<=i;j++)
            if(j) bc[i][j] =  bc[i-1][j-1]+bc[i-1][j];
            else bc[i][j] = 1;

    while(cin>>n>>m)
    {
        an=0;

        for(i=0;i<=m;i++)
            an+= bc[n][i]*de[n-i];
        cout<<an<<endl;

    }

    return 0;
}
