
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
point rotate(point p,double theta){
    double r=DEG_to_RAD(theta);
    return point(p.x*cos(r)-p.y*sin(r),p.x*sin(r)+p.y*cos(r));
}

struct line{
double a,b,c;
};

void pointsToLine(point p1,point p2,line &l){
    if(fabs(p1.x-p2.x)<EPS)
    {
        l.a=1.0; l.b=0.0; l.c=-p1.x;
    }
    else{
        l.a=-(double)(p1.y - p2.y)/(p1.x - p2.x);
        l.b=1.0;
        l.c=-(double)(l.a*p1.x) - p1.y;
    }
}

bool areParallel(line l1,line l2){
    return (fabs(l1.a-l2.a) < EPS && fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1,line l2){
    return (areParallel(l1,l2) && fabs(l1.c-l2.c)<EPS);
}

int areIntersect(line l1,line l2,point &p){
    if(areSame(l1,l2)) return 0;
    if(areParallel(l1,l2)) return 1;
    p.x=(l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    if(fabs(l1.b)>EPS) p.y=-(l1.a*p.x + l1.c);
    else               p.y=-(l2.a*p.x + l2.c);
    return 2;
}

int main()
{
    int t;
    scanf("%d",&t);

    double a,b,c,d,x,y,p,q;
    for(int i=1;i<=t;i++){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&x,&y,&p,&q);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        line l1,l2;
        point p1(a,b),p2(c,d),p3(x,y),p4(p,q);
        pointsToLine(p1,p2,l1);
        pointsToLine(p3,p4,l2);
        point p5;
        int z=areIntersect(l1,l2,p5);
        //cout<<z<<"\n";
        if(i==1) printf("INTERSECTING LINES OUTPUT\n");
        if(z==0) printf("LINE\n");
        else if(z==1) printf("NONE\n");
        else {
            printf("POINT %.2lf %.2lf\n",p5.x,p5.y);
        }
        if(i==t) printf("END OF OUTPUT\n");
    }
}
