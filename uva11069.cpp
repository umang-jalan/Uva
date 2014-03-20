#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int dp[78],n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=2;
    for(int i=4;i<=76;i++)
    {
        dp[i]=dp[i-2]+dp[i-3];
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",dp[n]);
    }
}
