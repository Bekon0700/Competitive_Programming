#include<bits/stdc++.h>

using namespace std;
void addPrime();
int n=1000000;

bool prime[1000000];
vector <long long  > primeArray;

void nsieve()
{
    prime[0]=false;
    prime[1]=false;
    memset(prime, true, sizeof(prime));
    prime[1]=false;

    for ( long long   p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (long long i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    addPrime();
}


void addPrime()
{
    for(int i=0; i<n; i++)
    {
        if(prime[i]==true)
        {
            primeArray.push_back(i);
        }

    }


}

vector<int> getFactorization(int x)
{
    vector<int> ret;

    int i=1;
    while (x != 1)
    {
        if(x%primeArray[i]==0)
        {
            ret.push_back(primeArray[i]);
            x = x / primeArray[i];

        }
        else
        {
            i++;
        }
    }

    return ret;
}



int main()
{
    nsieve();
    int sizee=primeArray.size();
    sort(primeArray.begin(),primeArray.end());
    int num1,num2;

    cin>>num1>>num2;

    int x =num1;
    int y=num2;

    vector <int> p = getFactorization(x);
    vector <int> q = getFactorization(y);

    set<int> valu1(p.begin(), p.end());
    set<int> valu2(q.begin(), q.end());
    set<int>::iterator iter;

    for(iter=valu1.begin(); iter!=valu1.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    printf("\n");

    for(iter=valu2.begin(); iter!=valu2.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    vector<int> result;

    set_intersection(valu1.begin(),valu1.end(),valu2.begin(),valu2.end(),back_inserter(result));

    int res= result.size()-1;
    if(res==-1)
    {
        printf("-1\n");
    }
    else
    {
        cout<<result[res]<<endl;
    }


    return 0;
}
