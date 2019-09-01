import java.util.*;
import java.math.*;
import java.io.*;

//import static java.util.Arrays.*;

/**
 *
 * @author javadb.com
 */
 

 
 
public class Main {
    

     
    long BigMod(long b,long p,long m)
    {
    	if(p==0)	return 1;
    	long x=BigMod(b,p/2,m);
    	
    	x=(x*x)%m;
    	
    	if(p%2==1)	x=(x*b)%m;
    	
    	return x;
    }
     
    public void FUN()
    {
    	Scanner in = new Scanner(System.in);
    	
    	while(in.hasNextLong())
    		System.out.println(BigMod(in.nextLong(),in.nextLong(),in.nextLong()));
    }

    public static void main(String[] args) {
        new Main().FUN();
    }
}