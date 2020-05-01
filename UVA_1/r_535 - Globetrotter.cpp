#include<iostream>
#include<math.h>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

double La[120],Lo[120];
double pi=2*acos(0),R=6378;
template<class T>T sqr(T a){return a*a;}
map<string,int>M;
double SphericalDistance(double lat1,double lon1,double lat2,double lon2)
{
    double dlon,dlat,a,d,c;
    lat1 *= 2.*pi/360.;lat2 *= 2.*pi/360.;
    lon1 *= 2.*pi/360.;lon2 *= 2.*pi/360.;
    dlon = lon2 - lon1;
    dlat = lat2 - lat1;

    a = (sqr(sin(dlat/2))) + cos(lat1) * cos(lat2) * sqr(sin(dlon/2));
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = R * c;
    return d;
}

int main()
{
    //freopen("in.in","r",stdin);
    string s1,s2;
    double la,lo;
    int i=1,j;

    while(cin>>s1 && s1!="#")
    {
        cin>>la>>lo;
        M[s1] = i;
        La[i] = la;
        Lo[i] = lo;
        i++;
    }
    while(cin>>s1>>s2 && (s1!="#" ||s2!="#" ))
    {
        i = M[s1];
        j = M[s2];
        cout<<s1<<" - "<<s2<<endl;
        if(i&&j)    printf("%.0lf km\n",SphericalDis(La[i],Lo[i],La[j],Lo[j]));
        else printf("Unknown\n");
    }

    return 0;
}
