#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<sstream>
#include<stack>
#include<ctype.h>
#include<list>


using namespace std;
#define N 1000005
//using namespace std;
int num[N],p[N],m[N],M[N];
//long p[N];
void Sieve(long s_size)
{   //bs.reset();
    //cout<<"fvft";

    memset(num,0,sizeof(num));
    for(long i=1;i<=s_size;i++) p[i]=i;

    for(long i=2;i<=s_size;i++)
    {
        if(num[i]==0)
        {
            for(long j=i+i;j<=s_size;j+=i) {num[j]++;p[j]/=i;}
        }
    }
}
int main()
{
//cout<<"Cdcdcf";
Sieve(1000000);
//cout<<"cfevfeve";
//long m[N],M[N];
//cout<<"vdvfgvfg";
memset(M,0,sizeof(M));
m[1]=1;M[1]=1;
for(long i=2;i<=1000000;i++)
{   //cout<<i<<" "<<"vdfvdfv\n";
    if(num[i]==0) {m[i]=-1;  M[i]=M[i-1]+m[i];}
    else if(num[i]>0)
    {
        if(p[i]!=1) {m[i]=0; M[i]=M[i-1]+m[i];}
        else
        {
            m[i]=((num[i]%2) ? -1 : 1);
            M[i]=M[i-1]+m[i];
        }
    }
}
int n;
while(1)
{
    scanf("%d",&n);
    if(n==0) break;
    printf("%8d%8d%8d\n",n,m[n],M[n]);
}
return 0;
}
