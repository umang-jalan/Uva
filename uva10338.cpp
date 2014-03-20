#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    string str;
    unsigned long long int fac[25];
    fac[0]=1;
    for(int i=1;i<=20;i++)
    {
        fac[i]=i*fac[i-1];
    }
    //cout<<fac[20];
    int cnt=1;
    while(t--)
    {
        getline(cin,str);
        map<char,int> m;
        for(int i=0;i<str.length();i++)
        {
            m[str[i]]++;
        }
        unsigned long long int result=fac[str.length()];
        for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
        {
            result=result/fac[it->second];
        }
        printf("Data set %d: %llu\n",cnt,result);
        cnt++;
       // unsigned long int=(fac[str.length()]/())
    }
}
