import java.io.*;
import java.util.*;
import java.math.*;

import static java.math.BigInteger.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;


public class Main
{
	long[] ar =new long[10010];
	
	public static void main(String []args)
	{
		new Main().run();
	}
	
	void Gen()
	{
		Arrays.fill(ar,0);
		ar[0]=1;
		for(int i=1;i*i*i<=10000;i++)
			for(int j=i*i*i;j<=10000;j++)
				ar[j]+=ar[j-i*i*i];
		
	}
	
	public void run()
	{
		Gen();
		Scanner in = new Scanner(System.in);
		
		while(in.hasNextInt())
		{
			int re=in.nextInt();
			System.out.println(ar[re]);
		}
		
	}
}