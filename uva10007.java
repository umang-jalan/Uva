import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;
import java.text.*;


class Main {

    public static void main(String[] args)  throws IOException{


        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        //Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        BigInteger[] cat=new BigInteger[305];
        cat[0]=BigInteger.ONE;
        BigInteger bi;
        for(int i=1;i<=300;i++)
        {   bi=BigInteger.valueOf((2*(i-1)+1)*2);
            cat[i]=cat[i-1].multiply(bi);
            bi=BigInteger.valueOf((i-1)+2);
            cat[i]=cat[i].divide(bi);
            //System.out.println(cat[i]);
        }
        int n;
        while(1!=0)
        {
            n=Integer.parseInt(b.readLine());
            if(n==0) break;
            BigInteger fact=BigInteger.ONE;
            int temp=n;
            while(n>0)
            {
                fact=fact.multiply(BigInteger.valueOf(n));
                n--;
            }
            System.out.println(fact.multiply(cat[temp]));


        }

    }
}
