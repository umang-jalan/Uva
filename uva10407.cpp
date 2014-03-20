#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<numeric>

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
    long a[1002],b[1002];
    while(1)
    {

    scanf("%lld",&a[0]);
    if(a[0]==0) break;
    int n=1;
    while(1)
    {
        scanf("%lld",&a[n]);b[n]=a[n];
        if(a[n]==0) break;
        n++;
    }
    //for(int i=0;i<n;i++) {cin>>a[i];b[i]=a[i];}
    for(int i=0;i<n;i++) {b[i]-=a[0]; }
    long result=std::accumulate(b+1,b+n,b[1],gcd);
    cout<<abs(result)<<"\n";
    }
}



