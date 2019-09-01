#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;

#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-1;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)
#define pi			2*acos(0)


int main(){
	double a,b,c,A,B,C,D,E,F,area,tb,tc,ta,garea,r1,r2,r3;
	int t=1,x,y,z;

	while(cin>>x>>y>>z && z )
	{
		a = x;b=y;c=z;
		A = acos( (b*b+c*c-a*a) / (2*b*c) );
		B = acos( (-b*b+c*c+a*a) / (2*a*c) );
		C = pi-A-B;
		tb = (pi-B)/2;ta = (pi-A)/2;tc = (pi-C)/2;
		D = pi-tb-tc;E = pi-ta-tc; F = pi-tb-ta;
		
		area=0.5*(sin(D)*(a/sin(D)*sin(tc))*(a/sin(D)*sin(tb)) +sin(E)*(b/sin(E)*sin(tc))*(b/sin(E)*sin(ta)) +sin(F)*(c/sin(F)*sin(ta))*(c/sin(F)*sin(tb))  + a*b*sin(C));
		r1=sin(D)*(a/sin(D)*sin(tc))*(1/sin(D)*sin(tb));
		r2 = sin(E)*(b/sin(E)*sin(tc)) * (1/sin(E)*sin(ta));
		r3=sin(F)*(c/sin(F)*sin(ta))*(1/sin(F)*sin(tb)) ;
		garea = D*r1*r1/2 +	E*r2*r2/2 + F*r3*r3/2;
		
		cout<<"Case "<<t<<": ";
		t++;
		printf("%.2lf %.2lf\n",area,garea);
	}
  



    return 0;
}
