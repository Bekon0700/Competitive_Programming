#include<stdio.h>
#include<math.h>

const double pi = acos(-1.0);
double E;

int main(){

//    freopen("in1.txt","r", stdin);
//    freopen("out1.txt","w", stdout);
    int tk,cs=1,r,n;
    scanf("%d",&tk);
    while(tk--){
        scanf("%d%d",&r,&n);
        double A = pi*r*r;  //area
        double a = A/3.0; // area of red
        double esum = 0,sum=0;
        esum = (A-a)/A;
        sum = esum;
//        cout<<esum<<endl;
        double x;
        for(int i = 1; i < n; i++){
            x = ((A-a)/A) * ((pow(a,i))/(pow(A,i)));
            esum += x;
            //cout<<"#"<<esum<<endl;
            sum += x * (double)(i+1);
           // cout<<"X = "<<x<<" "<<x * (double)(i+1)<<endl;
           // cout<<"@"<<sum<<endl;
        }
        sum += (double)n * ((pow(a,n))/(pow(A,n)));
        //cout<<"sum "<<sum<<endl;
        //cout<<"$"<<esum<<endl;
        E = 1.0 - esum;
        //cout<<E<<endl;
        double res = sum / E;
        printf("Case %d : %.3lf\n",cs++,res);

    }

    return 0;
}
