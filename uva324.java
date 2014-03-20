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
        //BigInteger temp2;
        //int temp;
        //BigInteger r=new BigInteger("10");
        BigInteger[] fac=new BigInteger[367];
        fac[0]=BigInteger.ONE;
        for(int i=1;i<367;i++)
        {
            fac[i]=BigInteger.valueOf(i).multiply(fac[i-1]);
        }
        while(1!=0)
        {

        int n=Integer.parseInt(b.readLine());
        if(n==0) break;

        /*BigInteger fac=BigInteger.ONE;
        int temp=n;
        while(temp>0)
        {
            fac=fac.multiply(BigInteger.valueOf(temp));
            --temp;
        }*/

        String str=fac[n].toString();
        Integer[] arr=new Integer[15];

        for(int i=0;i<10;i++) arr[i]=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)>='0' && str.charAt(i)<='9') arr[str.charAt(i)-'0']++;
        }
        System.out.println(n + "! --");
        //System.out.format("   ");
        for(int i=0;i<10;i++)
        {
            System.out.printf("   (%d)%5d",i,arr[i]);
            if(i==4) System.out.printf("\n");
        }

        System.out.println();


    }
}
}
