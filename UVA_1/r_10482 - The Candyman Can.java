import java.io.*;
import java.util.*;
import java.math.*;

import static java.math.BigInteger.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;


public class Main
{
	boolean [][] ar =new boolean[250][250];
	int[] l = new int[33];
	
	public static void main(String []args)
	{
		new Main().run();
	}
	
	int min(int a,int b){return a<b?a:b;}
	int max(int a,int b){return a<b?b:a;}
	
	int Gen(int n)
	{
		int mx,sum=0,it;
		for(int i=0;i<n;i++)	sum+=l[i];
			
		it=sum/3 + 20;
		
		for(int i=0;i<=it;i++)
			Arrays.fill(ar[i],false);
			
		mx=sum;
		
		ar[0][0]=true;
		
		for(int i=0;i<n;i++)
			for(int j=it;j>=0;j--)
				for(int k=it;k>=0;k--)
					if( (j>=l[i]&&ar[j-l[i]][k]) || (k>=l[i] && ar[j][k-l[i]]) )
					{	
						ar[j][k]=true;
						mx=min(mx,max(max(j,k),sum-j-k)-min(sum-j-k,min(j,k)));
					}
				
					
		return mx;
	}
	
	public void run()
	{
		Scanner in = new Scanner(System.in);
		
		int ks=1,tks=in.nextInt();

		while(tks-->0)
		{
			int n=in.nextInt(),i;
			
			for(i=0;i<n;i++)	l[i]=in.nextInt();
			
			System.out.println("Case "+ ks++ +": "+Gen(n));
		}
		
	}
}