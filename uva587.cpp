
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
#include<bitset>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define MOD 1234567891
#define EPS 1e-9
#define PI acos(-1.0)


struct point{
double x,y;
    point(){
        x=0.0;
        y=0.0;
    }
    point(double _x,double _y){
        x=_x;
        y=_y;
    }
    bool operator < (point other) const{
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const{
        return (fabs(x-other.x)<EPS && fabs(y-other.y)<EPS);
    }
};

double dist(point p1,point p2){
    return hypot(p1.x-p2.x,p1.y-p2.y);
}

int rev(int val){
    int x=0;
    while(val){
        x=x*10+val%10;
        val/=10;
    }
    return x;


}

void modify(double &x,double &y,int c,int b){
    double val=(double)b;
    double val1=(double)sqrt((val*val)/2.0);
    //int val=b;
    switch(c){
    case 0:y+=val;break;
    case 1:x+=val;break;
    case 2:x-=val;break;
    case 3:y-=val;break;
    case 4:x+=val1;y+=val1;break;
    case 5:x-=val1;y+=val1;break;
    case 6:x+=val1;y-=val1;break;
    case 7:x-=val1;y-=val1;break;
    }
}
int pow_c(int c){
    int val=1;
    for(int i=0;i<c;i++){
        val=val*10;
    }
    return val;
}

int main()
{
    int t;
   // scanf("%d",&t);

    map<string,int> m;
    m["N"]=0;
    m["E"]=1;
    m["W"]=2;
    m["S"]=3;
    m["EN"]=4;
    m["WN"]=5;
    m["ES"]=6;
    m["WS"]=7;
    int l=1;
    char str[300];
    //scanf("%s",&str);
    while(gets(str) && strcmp(str,"END")){

            int len=strlen(str);
            //if(strcmp(str,"END")==0) break;
            //else if(l!=1) printf("\n");
            int val=0;
            string str2="";
            double x=0.0,y=0.0;
            int cnt=0;
            vector<pair<int,int> > v;
            for(int i=len-2;i>=0;i--){
                if(str[i]==',') {
                v.push_back(make_pair(val,m[str2]));
                //modify(x,y,m[str2],rev(val));
                val=0;str2="";cnt=0;
                continue;
                }
                if(str[i]>='0' && str[i]<='9'){
                    val=pow_c(cnt)*(str[i]-'0') + val;
                    cnt++;
                }
                else str2+=str[i];

            }
            v.push_back(make_pair(val,m[str2]));
            for(int i=v.size()-1;i>=0;i--){
               //cout<<v[i].first<<" "<<v[i].second<<" "<<x<<" "<<y<<"\n";;
                modify(x,y,v[i].second,v[i].first);
                 // cout<<v[i].first<<" "<<v[i].second<<" "<<x<<" "<<y<<"\n";;
            }
            point p1(0,0),p2((double)x,(double)y);
            printf("Map #%d\n",l);
             printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
            printf("The distance to the treasure is %.3lf.\n\n",dist(p1,p2));
            l++;

    }
}
