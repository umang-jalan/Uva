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
#include<iomanip>

using namespace std;
int val1=-1;
int a[109],n;
int dp[50005][109];
int value(int id,int remw)
{
    if(id<0) return 0;
    if(dp[remw][id]!=-1) return dp[remw][id];
    if(a[id]>remw) return dp[remw][id]=value(id-1,remw);
    else
    {
        return dp[remw][id]=max(value(id-1,remw),a[id]+(value(id-1,remw-a[id])));
    }
}
int main()
{
    int t,totsum=0;;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) {cin>>a[i];totsum+=a[i];}
        memset(dp,-1,sizeof(dp));
        int val=value(n-1,totsum/2);
        cout<<totsum-2*val<<"\n";
        totsum=0;

    }
}
