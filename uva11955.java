
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

    public static void main(String[] args) throws IOException {


        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        //Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        long[][] dp=new long[55][55];
        for(int i=0;i<55;i++)
        {
            dp[i][0]=1;
            dp[i][i]=1;

        }
        for(int i=2;i<55;i++)
        {
            for(int j=1;j<i;j++)
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        int j=Integer.parseInt(b.readLine());
        int cnt=1;
           while(j-->0)
            {
            String str=b.readLine();
            String str1,str2;int n;
            str1=str.substring(str.indexOf('(')+1,str.indexOf('+'));
            str2=str.substring(str.indexOf('+')+1,str.indexOf(')'));
            n=Integer.parseInt(str.substring(str.indexOf('^')+1,str.length()));
            int beg=n,end=0;
            System.out.print("Case " + cnt + ": ");
            cnt++;
            for(int i=0;i<=n;i++)
            {
                if(dp[n][i]==1)
                {
                    if(beg==n && end==0 )
                    {
                        if(n==1) System.out.print(str1);
                        else System.out.print(str1 + "^" + beg);
                    }
                    else if(beg==0 && end==n)
                    {
                        if(n==1) System.out.print(str2);
                        else System.out.print(str2 + "^" + end);
                    }
                    if(i+1<=n) System.out.print("+");
                    else System.out.println();
                }
                else
                {
                    if(beg==1 && end>1) System.out.print(dp[n][i] + "*" + str1 + "*" + str2 + "^" + end);
                    else if(beg>1 && end==1) System.out.print(dp[n][i] + "*" + str1 + "^" + beg + "*" + str2 );
                    else if(beg==1 && end==1) System.out.print(dp[n][i] + "*" + str1 + "*" + str2);
                    else System.out.print(dp[n][i] + "*" + str1 + "^" + beg + "*" + str2 + "^" + end);
                    if(i+1<=n) System.out.print("+");
                    else System.out.println();

                }
                beg--;
                end++;
            }
            //int i;



        }

    }
}
