#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;
bitset<1000002> bs;
vector<long long> v;
//vector<long long> ap;
long long ap[90000];

int k=0;
void Sieve(long long sz)
{  // v.push_back(0);v.push_back(0);
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2;i<=sz;i++)
    {
        if(bs[i])
           {
               for(long long j=i*i;j<=sz;j+=i) bs[j]=0;
               v.push_back(i);
           }
    }
}
void Arr(long long sz)
{
    for(long long i=0;i<v.size();i++)
    {
            for(long long j=v[i]*v[i];j<=sz;j*=v[i]) {ap[k++]=j;}

    }
    sort(ap,ap+k);
}
int bsearch(long long key)
{
    long long low=0,high=k-1,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        if(ap[mid]==key) return mid;
        if(ap[mid]>key) high=mid;
        else low=mid+1;

    }
    return -1;
}

int main()
{
int t;
long long a,b;
Sieve(1000000);
Arr(1000000000000);
scanf("%d",&t);
long long cnt=0;
while(t--)
{
    scanf("%lld %lld",&a,&b);

    bool flag=false;
    for(long long i=a;i<=b;i++)
    {
        int pos=bsearch(i);
        if(pos!=-1) {cnt++; for(int j=pos+1;ap[j]<=b && j<k;j++) cnt++; flag=true;}
        if(flag) break;
    }
    printf("%lld\n",cnt);
    cnt=0;

}
}
