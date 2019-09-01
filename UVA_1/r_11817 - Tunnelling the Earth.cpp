#include<iostream>
#include<cmath>
using namespace std;


double pi=2*acos(0),R=6371009;
template<class T>T sqr(T a){return a*a;}
//lat1,lat2 lon1,lon2 all are in degree
double SphericalDistance(double lat1,double lon1,double lat2,double lon2)
{
    double dlon,dlat,a,d,c;
    //convertino from degree to radian.
    lat1 *= 2.*pi/360.;lat2 *= 2.*pi/360.;
    lon1 *= 2.*pi/360.;lon2 *= 2.*pi/360.;
    dlon = lon2 - lon1;
    dlat = lat2 - lat1;

    a = (sqr(sin(dlat/2))) + cos(lat1) * cos(lat2) * sqr(sin(dlon/2));
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    return c;
    d = R * c;
    return d;
}

int main()
{
    int tt;
    double la1,la2,lo1,lo2,a,an;
    cin>>tt;

    while(tt--)
    {
        cin>>la1>>lo1>>la2>>lo2;
        an = SphericalDistance(la1,lo1,la2,lo2);
        a = R*sin(an)/sin((pi-an)/2);
        printf("%.0lf\n",R*an-a);
    }


}
