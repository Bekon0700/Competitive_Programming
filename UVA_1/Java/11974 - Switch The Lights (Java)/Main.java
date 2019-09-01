import java.io.*;
import java.util.*;
import java.math.*;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;




public class Main {
	int []mm = new int[(1<<16)+2];
	int []p = new int[111];
	
	
	
    public void FUN() {
    	
       	Scanner in=new Scanner(System.in);
    	
       	int tks,ks=1,u;
    	tks=in.nextInt();
    	
       	while(tks>0)
    	{
    			tks--;
    			int N,M,x,re=0;
    			
    			N=in.nextInt();
    			M=in.nextInt();
    			
    			Arrays.fill(mm,200);
    			Arrays.fill(p,0);
    			
    			for(int i=0;i<M;i++)
    			{
    					for(int j=0;j<N;j++)
    					{
    						x = in.nextInt();
    						if(x==1)	p[i]=p[i]|(1<<j);
       					}
       			}
    			
    			mm[0]=0;
    			
    			Queue <Integer>q = new LinkedList<Integer>();
    			q.add(0);
    			
    			while(!q.isEmpty())
    			{
    				u = q.peek();	q.remove();
    				for(int i=0;i<M;i++)
    					if(mm[u^p[i]]==200)
    					{
    						mm[u^p[i]]=mm[u]+1;
    						q.add(u^p[i]);
    					}
    			}
    			
    			re = mm[(1<<N)-1];
    			
    			
    			if(re>M)	System.out.println("Case "+ks+": IMPOSSIBLE");
    			else System.out.println("Case "+ks+": "+re);
    			ks++;
    			
 		}
    }
		public static void main (String[] args) {
    		new Main().FUN();		    	
    	}
}