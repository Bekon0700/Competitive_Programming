#include<stdio.h>
#include<math.h>

int prime[80000],rp[80000],rpf[80000],c,R;
bool flag[1000020];
void RP();
void SEIVE();

int main()
{
	SEIVE();
	RP();
	int i,j,n,x,l,h,m;
	char a[3];
	
	while(scanf("%s %d",a,&n) == 2)
		if(a[0] == 'q')	
		{
			n++ ;
			x = 0 ;
			
			for( i = 0 ; i < n ; i ++ )	
				if( rpf[i])
					x += rpf[i] ;
				else
					n ++ ;
			printf("%d\n",x);
		}
		else	
		{
			l = 0 ;
			h = R ;
			while(l <= h)
			{
				m = (l+h) >> 1;
				if(rp[m] > n)	h = m-1;
				else if(rp[m]< n)	l = m+1;
					else break;
			}
			rpf[m] = 0 ;
		}
		
	return 0;
}

void SEIVE()
{
	int  i,j,r,x,m = 1000007;
	c = 2 ;
	prime[1] = 2 ;
	flag[1]=false;
	flag[2] = true ;
	for( i = 3 ; i < m ; i += 2)	flag[i] = true;
	x = sqrt(m) + 1;
	m ++ ;
	for(i=3;i<m;i += 2)
		if(flag[i])	
		{
			prime[c++] = i;
			if( i < x)
				for(j = i*i,r = i << 1 ; j < m ; j += r)
					flag[j] = false ;
		}
}


void RP()
{
	int rv = 1,i,x,y,a,b,m,n,k,j;
	
	for(j=1;j<10;j+=2)
	{
		m = (j+1)*100000 + 1;
		
		for(i = j*100000 ; i <  m ; i++)	
		{
			a = i;
			b = 0 ;
			while(a)
			{
				b = b*10 + a %10 ;
				a /= 10 ;
			}
			
			if(flag[b])
			{
				rp[R] = i*10;
				a = i;
				n = 2 ;
				x = sqrt(a) + 1 ;				
				for(k=1;prime[k] < x ;k++)
					if(a%prime[k] == 0)
					{
						while(a%prime[k]==0)	
						{
							a /= prime[k];
							n++;							
						}
						x = sqrt(a) + 1 ;				
					}
				if(a != 1 )		n++;
				rpf[R++] = n;	
			}
		}
	}
	R--;
}
