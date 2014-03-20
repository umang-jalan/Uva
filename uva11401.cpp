#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 1000001
using namespace std;
static unsigned long long int dp[N];
int main()
{int n;
dp[3]=0;
dp[4]=1;
unsigned long long int x;
for(int i=5;i<N;i++)
{ x=(i-3);
    dp[i]=dp[i-2]+(x*(x+1)/2);
}
while(1)
  { scanf("%d",&n);
       if(n<3) break;
            printf("%llu\n",dp[n]);
  }

}




