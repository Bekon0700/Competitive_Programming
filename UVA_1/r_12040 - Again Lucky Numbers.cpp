#include<stdio.h>
#include<string.h>

const int M = 10000007;

char a[105],b[105];
int mm[105][105],n,l,mat[105][10];

int go(int p,int c)
{
    if(p==n)    return 1;
    int &re = mm[p][c];
    if(re>-1)   return re;

    re=0;
    for(int i=0;i<10;i++)
        if((p||i||p==n-1) && mat[c][i]<l) re = (re+go(p+1,mat[c][i]))%M;

    return re;
}


int main()
{
    int i,tks,j,k;
    //freopen("in.in","r",stdin);

    scanf("%d",&tks);
    memset(mm,-1,sizeof mm);

    while(tks--)
    {
        scanf("%d%s",&n,a+1);
        l = strlen(a+1);

        memset(mm,-1,sizeof mm);
        memset(mat,0,sizeof mat);
        memset(b,0,sizeof b);

        for(j=0,i=2;i<=l;i++)
        {
            if(a[i]==a[j+1])    j++;
            else
            {
                while(j && a[j+1]!=a[i])
                    j = b[j];
                if(a[j+1]==a[i])    j++;
            }
            b[i] = j ;
        }
        //for(i=0;i<=l;i++)   printf("%d ",b[i]);printf("\n\n");

        for(i=0;i<l;i++)
        {
            for(j=0;j<10;j++)
            {
                //printf("(%c %c)",a[i+1],j+48);
                if(a[i+1]==j+48)    mat[i][j] = i+1;
                else
                {
                    k = b[i];
                    while(k && a[k+1]!=j+48)
                        k=b[k];
                    if(a[k+1]==j+48)    k++;
                    mat[i][j] = k;
                }
                //printf("(%d,%d)%d ",i,j,mat[i][j]);
            }
            //printf("\n");
        }
        //printf("\n\n");


        printf("%d\n",go(0,0));
    }

    return 0;
}
