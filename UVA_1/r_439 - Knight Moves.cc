#include<stdio.h>
#include<string.h>

int  L[10000],D[10000],F,R,V[10000] ;


int main()
{
	int  i,j,l,d,fl,fd,rl,rd,n,t,v; 
	char f[4],r[4];
	bool field[9][9];
	
	while( scanf("%s%s",f,r) == 2 )
	{
		fl = f[0] - 96 ;
		fd = f[1] - 48 ;
		
		rl = r[0] - 96 ;
		rd = r[1] - 48 ;
		for(i=1;i<9;i++)
			for(j=1;j<9;j++)
				field[i][j] = true ;
		
		F = R = 0 ;
		n = 0 ;
		L[++R] = fl ;
		D[R] = fd ;
		field[fl][fd] = false;
		V[R] = 0 ;
		
		while(F != R)
		{
			l = L[++F];
			d = D[F];
			v = V[F];
		
			if(l == rl && d == rd)	
			{	
				n = v;
				break;				
			}
			
			if(l + 2 < 9 && d + 1< 9)
			if(field[l+2][d+1])
			{
				L[++R] = l + 2 ;
				D[R] = d +1 ;
				V[R] = v + 1 ;
				field[l+2][d+1] = false;
			}
			if(l + 2 < 9 && d -1 > 0)
			if(field[l+2][d-1])
			{
				L[++R] = l +2;
				D[R] = d -1 ;
				V[R] = v + 1 ;
				field[l+2][d-1] = false;
			}
			if(l + 1 < 9 && d + 2< 9)
			if(field[l+1][d+2])
			{
				L[++R] = l + 1 ;
				D[R] =  d + 2 ;
				V[R] = v + 1 ;
				field[l+1][d+2] = false;
			}
			if(l + 1 < 9 && d - 2 > 0 )
			if(field[l+1][d-2])
			{
				L[++R] = l + 1 ;
				D[R] = d -2 ;
				V[R] = v + 1 ;
				field[l+1][d-2] = false;
			}
			if(l - 2 > 0 && d + 1 < 9)
			if(field[l-2][d+1])
			{
				L[ ++ R ] = l - 2 ;
				D[R] = d + 1 ;
				V[R] = v + 1 ;
				field[l-2][d+1] = false;
			}
			if(l - 2 > 0 && d - 1 > 0)
			if(field[l-2][d-1])
			{
				L[++R] = l -2 ;
				D[R] = d -1 ;
				V[R] = v + 1 ;
				field[l-2][d-1] = false;
			}
			if(l - 1 > 0 && d + 2 < 9)
			if(field[l-1][d+2])
			{
				L[++R] = l - 1 ;
				D[R] = d + 2 ;
				V[R] = v + 1 ;
				field[l-1][d+2] = false;
			}
			if(l - 1 > 0 && d - 2 > 0)
			if(field[l-1][d - 2])
			{
				L[++R] = l - 1;
				D[R] = d - 2 ;
				V[R] = v + 1 ;
				field[l-1][d - 2] = false;
			}
		}
		
		printf("To get from %s to %s takes %d knight moves.\n",f,r,n);
		
	}
	return 0;
}
