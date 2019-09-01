import java.io.*;
import java.util.*;
//import java.math.BigInteger;
//import java.math.BigDecimal;
import java.math.*;



public class Main {
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner inp = new Scanner(System.in);
        int ar[] = new int[23];
        

        while(inp.hasNextInt())
        {
        	
        	int n=inp.nextInt(),a=inp.nextInt(),i;
        	
        	BigInteger sum=BigInteger.valueOf(0),A,B;
        	
        	for(i=1;i<=n;i++)
        	{
        		A=BigInteger.valueOf(a);
        		A=A.pow(i);
        		A=A.multiply(BigInteger.valueOf(i));
        		
        		sum=sum.add(A);
        	}	
           	System.out.println(sum);
        }
    }
}
