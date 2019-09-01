#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>

typedef struct
{
	int point,g,w,t,d,sbh,sba,gd;
	char name[40];
}te;
te team[40];

int mystrcmp(char a[],char b[])
{
	int i;
	
	for(i=0; a[i] && b[i] ;i++)
	{
		if(tolower(a[i]) < tolower(b[i]))	
			return -1;
		else if(tolower(a[i]) > tolower(b[i]))
			return 1;
	}
	if ( !a[i] ) return -1 ;
	if ( !b[i] ) return 1 ;

    return 0 ;
}

int comp(const void *a, const void *b)
{
	te *x = (te*) a;
	te *y = (te*) b;
	if( x->point  !=  y->point)
		return y->point - x->point;
	if(x->w != y->w)
		return y->w - x->w;
	if( x->sbh - x->sba !=  y->sbh - y-> sba )
		return  (y->sbh - y-> sba) - ( x->sbh - x->sba ) ;
	if(x->sbh != y->sbh)				
		return y->sbh - x->sbh;
	if(x->g != y->g)					
		return x->g - y->g;
	return mystrcmp(x->name, y->name ) ;
}

int main()
{
	int t,i,j,k,nt,ng,ga,gb,p,q;
	char noftur[150],des[200],ta[40],tb[40];

	scanf("%d",&t);

	while(t--)
	{
		scanf(" %[^\n]",noftur);
		scanf("%d",&nt);

		for(i=0;i<nt;i++)
		{
			scanf(" %[^\n]",team[i].name);
			team[i].g = team[i].point = team[i].w = team[i].t = team[i].d = team[i].sbh = team[i].sba =team[i].gd = 0 ;
		}
		scanf("%d\n",&ng);

		for(i=0;i<ng;i++)
		{
			scanf(" %[^#]#%d@%d#%[^\n]",ta,&ga,&gb,tb);
			for(j=0;j<nt;j++)
				if( !strcmp(ta,team[j].name) )
				{
					team[j].g ++ ;	team[j].sbh += ga;	team[j].sba += gb;	
					if(ga > gb )
					{
						team[j].point += 3;
						team[j].w ++ ;
					}
					else if(gb > ga)
					{
						team[j].d ++ ;
					}
					else
					{
						team[j].point ++;
						team[j].t ++ ;
					}
					break;
				}
			for(j=0;j<nt;j++)
				if( !strcmp(tb,team[j].name) )
				{
					team[j].g ++ ;	team[j].sbh += gb;	team[j].sba += ga;	
					if(gb > ga )
					{
						team[j].point += 3;
						team[j].w ++ ;
					}
					else if(ga > gb)
					{
						team[j].d ++ ;
					}
					else
					{
						team[j].point ++;
						team[j].t ++ ;
					}
					break;
				}
			
		}
		qsort(team,nt,sizeof(te),comp);
		puts(noftur);
	
		for(i=0;i<nt;i++)
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,team[i].name,team[i].point,team[i].g,team[i].w,team[i].t,team[i].d,team[i].sbh - team[i].sba,team[i].sbh,team[i].sba);
		if(t)
			printf("\n");
	
	}

	return 0;
}
