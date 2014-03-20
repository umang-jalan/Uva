#include<iostream>
#include<cstdio>
#include<cmath>
int n,k,p,q,a,b,c,d,cnt;
using namespace std;
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
    a=0;b=1;c=1;d=n;
    cnt=0;
    while(cnt!=k)
    {
        int x=((n+b)/d);
        p=x*c-a;
        q=x*d-b;
        a=c;b=d;
        c=p;d=q;
        cnt++;
    }
    printf("%d/%d\n",a,b);
    }
}
