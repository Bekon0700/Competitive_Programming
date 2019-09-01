import java.util.*;
import java.math.*;
import java.io.*;

//import static java.util.Arrays.*;
 
public class Main {
    long [][][] dp = new long [2][66][66];
    
    int n,m;
     
    long go(int p,int c,int r)
    {
       	if(c>r || c<0)	return 0;
    	if(r==0 && c==0)	return 1;
    	if(dp[p][c][r]>-1)	return dp[p][c][r];
    	int a=0;
    	
    	if(p==1)	a=1;
    		
    	dp[p][c][r]=0;
       	dp[p][c][r] = go(1,c-a,r-1);
       	dp[p][c][r] += go(0,c,r-1);
       	
       	return dp[p][c][r];
    }
     
    public void FUN()
    {
    	
    	Scanner in = new Scanner(System.in);
    	int ks=1;
    	long g;
		
		for(int i=0;i<66;i++)
		{
			Arrays.fill(dp[0][i],-1);
			Arrays.fill(dp[1][i],-1);
		}
		for(int i=65;i>=0;i--)	dp[1][i][65]=go(1,i,65);
    	
    	while(true)
    	{
    		m=in.nextInt();
    		n=in.nextInt();
    		
    		if(n<0 && m<0)	break;
    		
			g = dp[1][n][m]<0?0:dp[1][n][m];
   			System.out.println(g);
    	}
    }

    public static void main(String[] args) {
        new Main().FUN();
    }
}