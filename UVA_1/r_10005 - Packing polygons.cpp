#include<stdio.h>
#include<math.h>

int main()
{
    double  x[100],y[100],r,X,Y,d;
    int n,i;

    while(scanf("%d",&n)==1 && n)
    {
        X=Y=0.0;
        for(i=0;i<n;i++) {
            scanf("%lf %lf",&x[i],&y[i]);
            X +=x[i];Y+=y[i];
        }
        bool f=true;
        X/=n;Y/=n;

        scanf("%lf",&r);

        if(sqrt(pow(X-x[0],2)+pow(Y-y[0],2)) > r)printf("There is no way of packing that polygon.\n");
        else printf("The polygon can be packed in the circle.\n");

    }
    return 0;
}

