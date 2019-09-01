#include<stdio.h>
#include<math.h>
#include<stdlib.h>


typedef struct {	double x,y;	}P;	
P p[10010];

int comp(const void *a,const void *b)
{
	P *A= (P*) a;
	P *B= (P*) b;
	
	if( B->x > A->x )	return -1;
	else if( B->x < A->x )	return 1;
	return 0;
}


int main()
{
	int n,j,i;
	double min,dis; 
	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1 && n)
	{
		min = 10000.0;
		for(i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);

		qsort(p,n,sizeof(P),comp);
		
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if( p[j].x - p[i].x >= min)
					break;
				dis = sqrt( (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y) );
				if(dis < min)
					min = dis;
			}
		}
		if(min<10000.0)
			printf("%.4lf\n",min);
		else
			printf("INFINITY\n");
	}

	return 0;
}
