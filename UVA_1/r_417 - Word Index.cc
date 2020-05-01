#include<stdio.h>

int index[26][26][26][26][26];
void INDEX();
int main()
{
	INDEX();
	int i,j ;
	char a[7];
	
	while(scanf("%s",a)==1)
	{
		i = j = 1 ;
		while( a[i] != '\0')		
		{
			if(a[i] <= a[i-1])
				j=0;	
			i++;
		}
		if(j)
		{			
			switch(i)		
			{
				case 1:	printf("%d\n",index[ a[0] - 97][0][0][0][0]);
							break;
				case 2:	printf("%d\n",index[ a[0] - 97][ a[1] - 97][0][0][0]);
							break;
				case 3:	printf("%d\n",index[ a[0] - 97][ a[1] - 97][ a[2] - 97 ][0][0]);
							break;
				case 4:	printf("%d\n",index[ a[0] - 97][ a[1] - 97][ a[2] - 97 ][a[3]-97][0]);
							break;
				case 5:	printf("%d\n",index[ a[0] - 97][ a[1] - 97][ a[2] - 97 ][a[3]-97][a[4]-97]);
							break;
			}
		}	
		else
			printf("0\n");
	}
	return 0;
}

void INDEX()
{
	int i,j,k,l,m,n,o,p,ind=1;

	for(i=0;i<26;i++)	
		index[i][0][0][0][0] = ind ++ ;
	for(i=0;i<26;i++)
		for(j=i+1;j<26;j++)
			index[i][j][0][0][0] = ind ++ ;
	for(i=0;i<26;i++)
		for(j=i+1;j<26;j++)
			for(k=j+1;k<26;k++)
				index[i][j][k][0][0] = ind ++ ;
	for(i=0;i<26;i++)
		for(j=i+1;j<26;j++)
			for(k=j+1;k<26;k++)
				for(l=k+1;l<26;l++)
					index[i][j][k][l][0] = ind ++ ;
	for(i=0;i<26;i++)
		for(j=i+1;j<26;j++)
			for(k=j+1;k<26;k++)
				for(l=k+1;l<26;l++)
					for(m=l+1;m<26;m++)
					index[i][j][k][l][m] = ind ++ ;
}
