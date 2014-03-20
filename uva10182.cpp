#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline void solve(int n)
{
    int r=0,k=1;
    while(n>k)
    {
        r++;
        k+=(r*6);
    }
    int x=r,y=0;
    while(k!=n)
      {
        while(x!=-y && k!=n)
        {
            y--;k--;
        }
        while(x!=0 && k!=n)
        {
            x--;k--;
        }
        while(y!=0 && k!=n)
        {
            x--;y++;k--;
        }
        while(x!=-y && k!=n)
        {
            y++;k--;
        }
        while(x!=0 && k!=n)
        {
            x++;k--;
        }
        while(y!=0 && k!=n)
        {
            x++;y--;k--;
        }
      }

        printf("%d %d\n",x,y);

}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        solve(n);
    }
}
