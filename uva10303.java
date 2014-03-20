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
        BigInteger[] cat=new BigInteger[1005];
        cat[0]=BigInteger.ONE;
        BigInteger bi;
        for(int i=1;i<=1001;i++)
        {   bi=BigInteger.valueOf((2*(i-1)+1)*2);
            cat[i]=cat[i-1].multiply(bi);
            bi=BigInteger.valueOf((i-1)+2);
            cat[i]=cat[i].divide(bi);
            //System.out.println(cat[i]);
        }
        int n;
        while(b.ready())
        {
            n=Integer.parseInt(b.readLine());
            System.out.println(cat[n]);

        }

    }
}
