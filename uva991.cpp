#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{

    int n;
    int cat[15];
    cat[0]=1;
    for(int i=1;i<=10;i++)
    {
        cat[i]=(((2*(i-1)+1)*2*cat[i-1])/((i-1)+2));
        //cout<<cat[i]<<" ";
    }
    bool blank=false;
    while(scanf("%d",&n)!=EOF)
    {
    //cin>>n;
    if(blank) cout<<"\n";
    blank=true;
    cout<<cat[n]<<"\n";
    }
}
