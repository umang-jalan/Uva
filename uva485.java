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

                  int n=1000;
                  BigInteger z=BigInteger.valueOf(10);
                  BigInteger p=z.pow(60);
                  int flag=0;
                  for (int y = 0; y < n && flag!=1; y++)
                  {
                        BigInteger  c = BigInteger.ONE;
                        BigInteger d;
                        for(int x = 0; x <= y; x++)
                        {
                              System.out.print(c); // 3 digits
                              System.out.print(" ");
                              d =(c.multiply(BigInteger.valueOf((y - x))));
                              c=d.divide(BigInteger.valueOf((x + 1)));
                              if(c.compareTo(p)>=0) flag=1;
                        }

                       System.out.println();
                  }

                  System.out.println();


    }
}
