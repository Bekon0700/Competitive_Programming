#include<stdio.h>


int main()
{
	int i,j,k,xl[2],yl[2],yu[2],xu[2],Xl,Xu,Yl,Yu,t;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d",&xl[0],&yl[0],&xu[0],&yu[0],&xl[1],&yl[1],&xu[1],&yu[1]);
		if(xl[0] > xl[1])  	Xl = xl[0];
		else	Xl = xl[1];	
		
		if(yl[0] > yl[1])  	Yl = yl[0];
		else	Yl = yl[1];	
		
		if(xu[0] < xu[1])  	Xu = xu[0];
		else	Xu = xu[1];	
		
		if(yu[0] < yu[1])  	Yu = yu[0];
		else	Yu = yu[1];	
		
		if(Yl<Yu && Xu>Xl)
			printf("%d %d %d %d\n",Xl,Yl,Xu,Yu);
		else
			printf("No Overlap\n");		
		if(t)	
			printf("\n");
	}

	return 0;
}
