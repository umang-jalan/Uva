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

    public static void main(String[] args) {


        //BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        while(sc.hasNext())
        {BigInteger n=sc.nextBigInteger();
        BigInteger k=sc.nextBigInteger();
        if(k.compareTo(n.subtract(k))>0) k=n.subtract(k);
        BigInteger fact1=new BigInteger("1");
        BigInteger fact2=new BigInteger("1");
        BigInteger x=n.subtract(k);
        x=x.add(BigInteger.ONE);
        BigInteger y=k;
        while(x.compareTo(n)<=0)
        {
            fact1=fact1.multiply(x);
            x=x.add(BigInteger.ONE);
        }
        while(y.compareTo(BigInteger.ZERO)>0)
        {
            fact2=fact2.multiply(y);
            y=y.subtract(BigInteger.ONE);
        }
        BigInteger ans=fact1.divide(fact2);
        String ans2=ans.toString();
        System.out.println(ans2.length());
        }
    sc.close();
    }
}
