import java.io.*;
import java.util.*;
import java.math.BigInteger;


public class Main {
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner inp = new Scanner(System.in);
        
        while(inp.hasNextBigInteger())
        {
        	
        	BigInteger b=inp.nextBigInteger(),a=inp.nextBigInteger();
        	//if(0==b.compareTo(BigInteger.valueOf(0)))	break;
        		
        	a=b.multiply(a);
   
           	System.out.println(a);
        }
    }
}
