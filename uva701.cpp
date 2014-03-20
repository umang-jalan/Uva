#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    long long int p;
   long double c=logl(10)/logl(2);
    while(scanf("%lld",&p)!=EOF)
    {   long double x,y,t;
        x=logl(p)/logl(2);
        y=logl(p+1)/logl(2);
        t=floor(log10l(p))+2;
        for(;ceill(x+t*c)!=floorl(y+t*c);t++);
        cout<<(long long int)floor(y+t*c)<<"\n";
    }
}
