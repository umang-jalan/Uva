#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<vector>

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
    //int a[100];
    int n;

    while(1)
    {
    cin>>n;
    if(n==0) break;
    vector<int> v;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(n/i!=i)  v.push_back(n/i);
        }
    }
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i;j<v.size();j++)
        {
            if(lcm(v[i],v[j])==n) cnt++;
        }
    }
    cout<<n<<" "<<cnt<<"\n";
    //v.clear();
    }



}

