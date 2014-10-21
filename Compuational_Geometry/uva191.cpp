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

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

struct point_i{
int x,y;
    point_i(){
        x=0;
        y=0;
    }
    point_i(int _x,int _y){
        x=_x;
        y=_y;
    }
    bool areSame(point_i p1,point_i p2){
        return (p1.x==p2.x && p1.y==p2.y);
    }
};

int cross2_i(point_i p,point_i q,point_i r){
    int val=(q.x-p.x)*(r.y-p.y) - (q.y-p.y)*(r.x-p.x);
    if(val==0) return 0;
    if(val>0) return 1;
    return -1;
}



bool onSegment(point_i p1,point_i p2,point_i p3){
    if((p3.x>=min(p1.x,p2.x) && p3.x<=max(p1.x,p2.x)) &&(p3.y>=min(p1.y,p2.y) && p3.y<=max(p1.y,p2.y)) ) return true;
    return false;
}

bool lineSegmentIntersect(point_i p1,point_i p2,point_i p3,point_i p4){
    int d1=cross2_i(p1,p2,p3);
    int d2=cross2_i(p1,p2,p4);
    int d3=cross2_i(p3,p4,p1);
    int d4=cross2_i(p3,p4,p2);
    if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
    if(d1==0 && onSegment(p1,p2,p3)) return true;
    if(d2==0 && onSegment(p1,p2,p4)) return true;
    if(d3==0 && onSegment(p3,p4,p1)) return true;
    if(d4==0 && onSegment(p3,p4,p2)) return true;
    return false;
}

int main(){

  int n,a,b,c,d,e,f,g,h;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);

    point_i p1(a,b);
    point_i p2(c,d);
    point_i q4(e,f);
    point_i q2(g,h);
    point_i q1(e,h);
    point_i q3(g,f);
    if((a>min(e,g) && a<max(e,g) && b<max(f,h) && b>min(f,h)) || lineSegmentIntersect(p1,p2,q1,q2) || lineSegmentIntersect(p1,p2,q2,q3) || lineSegmentIntersect(p1,p2,q3,q4) || lineSegmentIntersect(p1,p2,q4,q1)){
        printf("T\n");
    }
    else printf("F\n");


  }

}

