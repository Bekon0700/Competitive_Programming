import java.io.*;
import java.util.*;
import java.math.*;

import static java.math.BigInteger.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;


public class Main
{
	
	public static void main(String []args)
	{
		new Main().run();
	}
	
	public void run()
	{
		Scanner in = new Scanner(System.in);
		//int n=in.nextInt();
		int n=10,ks=1,tks=in.nextInt();
		//String s="sdf";		n = s.compareTo();
			
		E[] ar = new E[n];
		
		while(tks-- > 0)
		{
		
			for(int i=0;i<n;i++)
				ar[i] = new E(in.next(),in.nextInt(),in.nextInt());
			
			Arrays.sort(ar,new Comparator<E>(){
					public int compare(E x,E y)			
					{
						if(x.a!=y.a)	return y.a-x.a;
						if(x.d!=y.d)	return x.d-y.d;
						return  x.nm.compareTo(y.nm);
					};	
			});		
				
			//System.out.println("A:");
			//for(int i=0;i<n;i++)	System.out.println(ar[i].nm+"  "+ar[i].a+" "+ar[i].d);
			
			sort(ar,0,5,new Comparator<E>(){
					public int compare(E x,E y)			
					{
						return  x.nm.compareTo(y.nm);
					};	
			});		
				
				
			sort(ar,5,10,new Comparator<E>(){
					public int compare(E x,E y)			
					{
						return  x.nm.compareTo(y.nm);
					};	
			});		
			
			
			System.out.println("Case "+ks+":");
			ks++;
			System.out.println("("+ar[0].nm+", "+ar[1].nm+", "+ar[2].nm+", "+ar[3].nm+", "+ar[4].nm+")");
			System.out.println("("+ar[5].nm+", "+ar[6].nm+", "+ar[7].nm+", "+ar[8].nm+", "+ar[9].nm+")");
		}
	}
	public class E{
		int a,d;
		String nm;
		public E(String nm,int a,int d){this.a=a;this.d=d;this.nm=nm;}
	}
}