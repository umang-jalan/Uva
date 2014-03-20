#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<fstream>

using namespace std;
string a,b;
 //ofstream fout;
char dir[100][100];
int mx_element(int a,int b,int c)
{
    return (max(a,max(b,c)));
}
int cnt=1;
int ins,del,rep;
void print(int i,int j)
{
    if(i==0 && j==0) return;
    if(dir[i][j]=='0') {print(i-1,j-1);}
    else if(dir[i][j]=='C')
    {
        print(i-1,j-1);
        cout<<cnt<<" Replace "<<i+ins-del<<","<<b[j-1]<<"\n";
        //a[i+ins-del]=b[j-1];
        cnt++;
    }
    else if(dir[i][j]=='D') {print(i-1,j); cout<<cnt<<" Delete "<<i+ins-del<<"\n";cnt++;del++;}
    else if(dir[i][j]=='U') {print(i,j-1); cout<<cnt<<" Insert "<<j<<","<<b[j-1]<<"\n"; cnt++; ins++;}

}
int main()
{
    //string a,b;

    //char dir[n+2][m+2];

    //fout.open("F://test.txt",ios::out|ios::trunc);
    bool blank=false;
    //int dis;
    while(getline(cin,a))
    {
    getline(cin,b);
   // dis=0;
    int re=0,de=0,in=0;
    int n=a.length();
    int m=b.length();
    int table[n+2][m+2];
    for(int i=0;i<=n;i++)
        {table[i][0]=i;dir[i][0]='D';}
    for(int i=0;i<=m;i++)
        {table[0][i]=i;dir[0][i]='U';}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           int x=min(table[i-1][j-1] + (a[i-1]!=b[j-1]) ,min(table[i-1][j]+1,table[i][j-1]+1));
            table[i][j]=x;
            if(x==table[i-1][j]+1){
                dir[i][j]='D';
            }
            else if(x==table[i][j-1]+1){
                dir[i][j]='U';
            }
            else{
                dir[i][j]=(a[i-1]!=b[j-1]) ? 'C' : '0';
            }
        }
    }
    //for(itn )
    if(blank) cout<<"\n";
    blank=true;
    cout<<table[n][m]<<"\n";
    ins=0;del=0;cnt=1;
    print(n,m);
    }

}
