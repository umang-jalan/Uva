#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<vector>
#define in(x)    scanf("%d",&x)
#define MAX 1000000001
using namespace std;
bool flag=true;
long int prime(long int num)
{
    long int cnt,m=num;
    cnt=0;
    while(num%2==0)
    {
        cnt+=2;//cout<<"2 ";
        num/=2;
    }
    long int j;
    for(long int i=3;i<=sqrt(num);i+=2)
    {
        if(num%i==0)
        {
        while(num%i==0)
        {   if(i<=9) {cnt+=i;}//cout<<i<<" ";}
            else
            {
                j=i;//cout<<i<<" ";
                while(j>0)
                {
                    cnt+=(j%10);j/=10;
                }
            }
            num/=i;
        }
        }
    }
    long int res;
    if(num>2) {
    //cout<<num<<"\n";
    if(num==m) flag=false;
    while(num>0 && flag){res=num%10;cnt+=res;num/=10;}
    }
    if(m==2) flag=false;
    return cnt;

}
int main()
{   long int n,sum=0;
int t;
scanf("%d",&t);
//ofstream fout;
//fout.open("F://test.txt",ios::out|ios::trunc);
while(t--)
{
    scanf("%ld",&n);
    long int m;
    n++;
    while(1)
    {
    m=n;
    while(m>0){sum+=(m%10); m/=10;}
    if(sum==prime(n)&& flag) {printf("%ld\n",n);break;}//fout<<n<<"\n";}
    n++;flag=true;
    sum=0;

    }
    sum=0;
    flag=true;
}
/*fout.close();
ifstream fin1,fin2;
fin1.open("F://test.txt",ios::in);
fin2.open("F://test2.txt",ios::in);

fin1.seekg(0);
fin2.seekg(0);
long int x,y;
while(!fin1.eof() || !fin2.eof())
{
    fin1>>x;
    fin2>>y;
    if(x!=y) {cout<<"false\n"; cout<<x<<" "<<y<<"\n";break;}
}*/




}

