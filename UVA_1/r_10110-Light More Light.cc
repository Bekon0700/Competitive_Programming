#include<stdio.h>
#include<math.h>

void MAIN()
{
	long long n;

	while(scanf("%d",&n)==1 && n)
	{
		if( ceil(sqrt(n)) == floor(sqrt(n)+1e-5) )
			printf("yes\n");
		else
			printf("no\n");
	}		
}

int main()
{
	MAIN();
	return 0;
}
