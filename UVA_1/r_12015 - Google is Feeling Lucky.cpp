#include<iostream>
#include<string>
using namespace std;

string s[11];
int v[11];

int main()
{
    int k,i,m,ks=1;
    cin>>k;

    while(k--)
    {
        for(i=m=0;i<10;i++)
        {
            cin>>s[i]>>v[i];
            m=m<v[i]?v[i]:m;

        }
        cout<<"Case #"<<ks<<":"<<endl;
        ks++;
        for(i=0;i<10;i++)
            if(v[i]==m)
                cout<<s[i]<<endl;

    }
    return 0;
}
