#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<string.h>
using namespace std;

set<long long int> s;
int main()
{   int n;
    s.insert(1);
    set<long long int>::iterator it;
    it=s.begin();
    while(s.size()<=7000)
    {
        s.insert(*it*2);
        s.insert(*it*3);
        s.insert(*it*5);
        s.insert(*it*7);
        it++;
    }
    vector<long long int> v(s.begin(),s.end());
    while(1)
    {scanf("%d",&n);
    long long int T=n%10;
    long long int H=(n%100)/10;
    string str;
    if(T==1 && H!=1) str="st";
    else if(T==2 && H!=1) str="nd";
    else if(T==3 && H!=1) str="rd";
    else str="th";

   // int cnt=0;
   if(n==0) break;
    cout<<"The "<<n<<str<<" humble number is "<<v[n-1]<<".\n";
    }
}
