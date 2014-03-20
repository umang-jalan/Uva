#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<string.h>
#include<sstream>
using namespace std;
int gcd(int a,int b)
{
    return((b==0) ? a : gcd(b,a%b));

}
int lcm(int a,int b)
{
    return (a*(b/gcd(a,b)));
}
int main()
{
    int a[101];
    int t,n=0;
   scanf("%d",&t);
   getchar();
   char str[100];

   while(t--)
    {
    n=0;
    gets(str);
    int temp;
    istringstream str1(str);
    while(str1)
    {   str1>>temp;
        a[n++]=temp;
    }
    int i=0,x=0;
    /*while(str[i])
    {   a[n]=0;
        while(str[i]!=' ' && str[i])
        {
            a[n]=a[n]*10+(str[i]-'0');
            i++;
        }
        if(str[i]==' ')
        {
            i++;
        }
        n++;

    }*/
    int mx=0;
    for(i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            mx=max(mx,gcd(a[i],a[j]));
        }
    }
    printf("%d\n",mx);
    }

}

