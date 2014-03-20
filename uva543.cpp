#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<math.h>
#include<vector>

using namespace std;
bitset<1000002> bs;
vector<int> v;
void Sieve(long long sz)
{
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2;i<=sqrt(sz);i++)
    {
        if(bs[i])
           {
               for(long long j=i*i;j<=sz;j+=i) bs[j]=0;
           }
    }
}

int main()
{
int n;
Sieve(1000000);
while(1)
{
    scanf("%d",&n);
    if(n==0) break;
    for(int i=n;;i--)
    {
        if(bs[i] && bs[n-i]) {printf("%d = %d + %d\n",n,n-i,i); break;}
    }
}
}
