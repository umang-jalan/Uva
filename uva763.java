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


class Main{
public static void main(String[] args) throws IOException{
BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
//Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
//PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
BigInteger[] a=new BigInteger[115];
a[0]=BigInteger.ONE;
a[1]=BigInteger.valueOf(2);
for(int i=2;i<=105;i++)
{
    a[i]=a[i-1].add(a[i-2]);

}
//BigInteger bi1,bi2;
//BigInteger sum=BigInteger.ZERO;
boolean flag=false;
while(sc.ready())
{
    if(flag) System.out.println();
    flag=true;
    BigInteger sum1=BigInteger.ZERO;
    BigInteger sum2=BigInteger.ZERO;
    String num1=sc.readLine();
    String num2=sc.readLine();
    if(sc.ready()) sc.readLine();
    int j=0;
    for(int i=num1.length()-1;i>=0;i--)
    {
        if(num1.charAt(i)=='1'){sum1=sum1.add(a[j]);}
        j++;
    }
    j=0;
     for(int i=num2.length()-1;i>=0;i--)
    {
        if(num2.charAt(i)=='1'){sum2=sum2.add(a[j]);}
        j++;
    }
BigInteger sum=sum1.add(sum2);
int start;
int beg=0,end=105;
while(end-beg>1)
{
    int mid=(end+beg)/2;
    if(a[mid].compareTo(sum)>=0) end=mid;
    else beg=mid;
}
if(sum.compareTo(a[end])>=0) start=end;
else start=beg;

String ans="";
for(int i=start;i>=0;i--)
{
    if(sum.compareTo(a[i])>=0) {ans+="1";sum=sum.subtract(a[i]);}
    else ans+="0";
}

System.out.println(ans);
}
//pr.close();
//
}

}



