
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

bool areIntersect(line l1,line l2,point &p){
    if(areSame(l1,l2)) return false;
    if(areParallel(l1,l2)) return false;
    p.x=(l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    if(fabs(l1.b)>EPS) p.y=-(l1.a*p.x + l1.c);
    else               p.y=-(l2.a*p.x + l2.c);
    return true;
}

struct vec{
double x,y;
vec(double _x,double _y){x=_x; y=_y;}
};

vec toVec(point a,point b){
    return vec(b.x - a.x , b.y - a.y);
}

vec scale(vec v,double s){
    return vec(v.x*s , v.y*s);
}

point translate(point p,vec v){     // translate p according to v
    return point(p.x + v.x , p.y + v.y);
}

void pointSlopeToLine(point p,double m,line &l){
    l.a=-m;
    l.b=1.0;
    l.c=-((l.a*p.x)+ (l.b*p.y));
}

void closestPoint(line l,point p,point &ans){       //closest point between point p and line l
    if(fabs(l.b)<EPS) {
        ans.y=p.y; ans.x=-l.c; return;
    }
    if(fabs(l.a)<EPS){
         ans.y=-l.c; ans.x=p.x; return;
    }
    line perpendicular;
    pointSlopeToLine(p , 1/l.a ,perpendicular);
    areIntersect(l,perpendicular,ans);
}

void reflectionPoint(line l,point p , point &ans){
    point b;
    closestPoint(l,p,b);
    vec v=toVec(p,b);               //p->b
    ans=translate(translate(p,v),v);  //vector b has difference of coordinates between p and closest point. So translate p to closest point and then to reflection point
}

double dot(vec a,vec b){ return (a.x*b.x + a.y*b.y);}
double norm_sq(vec a) { return (a.x*a.x + a.y*a.y);}

//minimum distance between a point p and a line defined by point A and point B
//closest point is point c
double distToLine(point p,point a,point b,point &c){
    //c=a+u*ab
    vec ab=toVec(a,b);
    vec ap=toVec(a,p);
    double u=dot(ap,ab)/norm_sq(ab);            //doubt -> why norm_sq
    c=translate(a,scale(ab,u));
    return dist(p,c);
}


double distToLineSegment(point p,point a,point b,point &c){
    vec ab=toVec(a,b);
    vec ap=toVec(a,p);
    double u=dot(ap,ab)/norm_sq(ab);
    if(u < 0.0){            //required point lies before point a  (negative scaling of vector)
        c=point(a.x,a.y);
        return dist(a,p);
    }
    if(u > 1.0){            //required point lies after point b  (positive scaling of vector  -> vector magnitude increases)
        c=point(b.x,b.y);
        return dist(b,p);
    }
    return distToLine(p,a,b,c);     // required point lies in between a and b. Perpendicular Distance

}

double angle(point a,point o,point b){
    vec oa=toVec(o,a); vec ob=toVec(o,b);
    return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

double cross(vec a,vec b){ return (a.x*b.y - a.y*b.x); }
/*double cross2(point p,point q,point r){
    return (r.x-q.x)*(p.y-q.y) - (r.y-q.y)*(p.x-q.x);
}
*/

//checks if point r is CCW to line described by points p,q;
bool ccw(point p,point q,point r){
    return cross(toVec(p,q),toVec(p,r)) > 0;
}

bool collinear(point p,point q,point r){
    return fabs(cross(toVec(p,q),toVec(p,r))) < EPS;
}

//CIRCLE

int insideCircle(point_i p,point_i c,int r){            //integer version
int dx=p.x-c.x , dy=p.y-c.y;
int dist=dx*dx + dy*dy;
int r_sq=r*r;
return (dist < r_sq ? 0 : (dist == r_sq ? 1 : 2));    //inside/border/outside
}

int insideCircle_f(point p,point c,double r){       //float version
    double dx=p.x-c.x;
    double dy=p.y-c.y;
    double dist=dx*dx + dy*dy;
    double r_sq=r*r;
    if((dist-r_sq) < 0.0) return 0;
    if(fabs(dist-r_sq)<EPS) return 1;
    return 2;
}

bool circle2PtsRad(point p1,point p2,double r,point &c1,point &c2){
    double mid_x=(p1.x+p2.x)/2.0 , mid_y=(p1.y+p2.y)/2.0;
    point mid(mid_x,mid_y);
    vec ab=vec(p1.y-p2.y,p2.x-p1.x);                //perpendicular to vector joining p1,p2. [interchange coordinates and change sign of one]
    double p1_p2_sq=(p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    double r_sq=r*r;
    if(fabs(p1_p2_sq)<EPS || (p1_p2_sq)> 4*r_sq) return false;
    double u=sqrt(r_sq - p1_p2_sq*0.25);
    c1=translate(mid,scale(ab,u));
    c2=translate(mid,scale(ab,-u));
    return true;
}

void circle_other(double r)
{
  double d = 2 * r;
  printf("Diameter = %.2lf\n", d);
  double c = PI * d;
  printf("Circumference (Perimeter) = %.2lf\n", c);
  double A = PI * r * r;
  printf("Area of circle = %.2lf\n", A);

  printf("Length of arc   (central angle = 60 degrees) = %.2lf\n", 60.0 / 360.0 * c);
  printf("Length of chord (central angle = 60 degrees) = %.2lf\n", sqrt((2 * r * r) * (1 - cos(DEG_to_RAD(60.0)))));
  printf("Area of sector  (central angle = 60 degrees) = %.2lf\n", 60.0 / 360.0 * A);
}


//TRIANGLE

double perimeter(double ab,double bc,double ca){
    return ab+bc+ca;
}

double perimeter(point a,point b,point c){
    return dist(a,b) + dist(b,c) + dist(c,a);
}

double area(double ab,double bc,double ca){
    double s=0.5*perimeter(ab,bc,ca);
    return sqrt(s) * sqrt(s-ab) * sqrt(s-bc) * sqrt(s-ca);
}

double area(point a,point b,point c){
    double ab=dist(a,b),bc=dist(b,c),ca=dist(c,a);
    return area(ab,bc,ca);
}

double rInCircle(double ab,double bc,double ca){        // r=A/s
    return area(ab,bc,ca)/(0.5*perimeter(ab,bc,ca));
}

double rInCircle(point a,point b,point c){
    return rInCircle(dist(a,b),dist(b,c),dist(c,a));
}

double rCircumCircle(double ab,double bc,double ca){            // r=a*b*c/(4*A)
    return (ab*bc*ca/(4.0 * area(ab,bc,ca)));
}

double rCircumCircle(point a,point b,point c){
    return rCircumCircle(dist(a,b),dist(b,c),dist(c,a));
}

//center of incircle (returns 0 if no center exists , otherwise returns 1. Center is 'ctr' and radius in 'r')
//http://www.askiitians.com/iit-jee-straight-line/centroid-incentre-and-circum-centre/ [Refer it]
//other formula : ((a*x1+b*x2+c*x3)/(a+b+c),(a*y1+b*y2+c*y3)/(a+b+c))
int inCircle(point p1,point p2,point p3,point &ctr,double &r){
    r=rInCircle(p1,p2,p3);
    if(fabs(r)<EPS) return 0;
    line l1,l2;
    double ratio=dist(p1,p2)/dist(p1,p3);
    point d=translate(p2,scale(toVec(p2,p3),ratio/(1+ratio)));
    pointsToLine(p1,d,l1);

    ratio=dist(p1,p2)/dist(p2,p3);
    d=translate(p1,scale(toVec(p1,p3),ratio/(1+ratio)));
    pointsToLine(p2,d,l2);

    areIntersect(l1,l2,ctr);
    return 1;
}


void find_perpendicular(point p1,point p2,point p3,point mid,line &l){
    if(fabs(p1.y-p2.y)<EPS)
    {
       l.a=1.0; l.b=0.0; l.c=-mid.x;
    }
    else{
         if(fabs(p1.x-p2.x)<EPS) pointSlopeToLine(mid,0,l);
         else{
            double x=-(double)(p1.y-p2.y)/(p1.x-p2.x);
            pointSlopeToLine(mid,1.0/x,l);
         }
    }
}

//center of circumcircle (returns 0 if no center exists , otherwise returns 1. Center is 'ctr' and radius in 'r')
//MY METHOD
//Refer [https://in.answers.yahoo.com/question/index?qid=20070123170311AAt541A ]
int circumCircle(point p1,point p2,point p3,point &ctr,double &r){
    r=rCircumCircle(p1,p2,p3);
    if(fabs(r)<EPS) return 0;

    point mid1(0.5*(p1.x+p2.x),0.5*(p1.y+p2.y)),mid2(0.5*(p2.x+p3.x),0.5*(p2.y+p3.y)),mid3(0.5*(p1.x+p3.x),0.5*(p1.y+p3.y));
    line l1,l2;
    find_perpendicular(p1,p2,p3,mid1,l1);
    find_perpendicular(p2,p3,p1,mid2,l2);
    areIntersect(l1,l2,ctr);
    return 1;

}
//OTHER METHOD [Can't Understand]
// assumption: the required points/lines functions have been written
// returns 1 if there is a circumCenter center, returns 0 otherwise
// if this function returns 1, ctr will be the circumCircle center
// and r is the same as rCircumCircle
int cp2_circumCircle(point p1, point p2, point p3, point &ctr, double &r){
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPS) return 0;

  ctr.x = (d*e - b*f) / g;
  ctr.y = (a*f - c*e) / g;
  r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
  return 1; }

// returns true if point d is inside the circumCircle defined by a,b,c
//COPIED cp2.
int inCircumCircle(point a, point b, point c, point d) {
  return (a.x - d.x) * (b.y - d.y) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) +
         (a.y - d.y) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.x - d.x) +
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.x - d.x) * (c.y - d.y) -
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.y - d.y) * (c.x - d.x) -
         (a.y - d.y) * (b.x - d.x) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) -
         (a.x - d.x) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.y - d.y) > 0 ? 1 : 0;
}

bool canFormTriangle(double a,double b,double c){
    return (a+b > c) && (b+c > a) && (c+a > b);
}


//SPHERE Great-Circle Distance [DERIVATION NOT REQUIRED]
double gcDistance(double pLat, double pLong,double qLat, double qLong, double radius) {
    pLat *= PI / 180; pLong *= PI / 180; // conversion from degree to radian
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
    cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
    sin(pLat)*sin(qLat));
}

struct line_i{
int a,b,c;
};
void points_itoLine(point_i p1,point_i p2,line_i &l){
    if(p2.x- p1.x == 0){
        l.a=1;
        l.b=0;
        l.c=p1.x;
    }
    else{
        l.c=(p2.x-p1.x)*p1.y - (p2.y-p1.y)*p1.x;
        l.b=(p2.x-p1.x);
        l.a=(p2.y-p1.y);
    }
}

bool collinear_i(point_i p,point_i q,point_i r){
    return (r.x-q.x)*(p.y-q.y) - (r.y-q.y)*(p.x-q.x)==0;
}
int main()
{   int a,b,c=0,d;
    bool flag=false;
    int j=0;
    vector<pair<pair<int,int>,int> > s;
    int dp[350][350];
    vector<pair<point_i,int> > ans;
    memset(dp,-1,sizeof(dp));
    int cnt=0;
    while(1){
        scanf("%d %d",&a,&b);
        if(a==0 && b==0)
        {   if(flag) break;
            else {
                flag=true;
                sort(s.begin(),s.end());
                int sz=s.size();
                for(int i=0;i<sz-1;i++){
                    line_i l;
                    point_i p=point_i(s[i].first.first,s[i].first.second);
                    ans.push_back(make_pair(p,s[i].second));
                    //printf("IN1-> %d %d\n",p.x,p.y);
                    for(int k=i+1;k<sz;k++)
                    {
                    point_i q=point_i(s[k].first.first,s[k].first.second);
                    //points_itoLine(p,q,l);
                   // printf("IN-> %d %d\n",q.x,q.y);
                    ans.push_back(make_pair(q,s[k].second));
                    dp[s[i].second][s[k].second]=0;
                    for(int j=k+1;j<sz;j++){
                        if(dp[s[i].second][s[j].second]==-1 && dp[s[k].second][s[j].second]==-1){
                           point_i r=point_i(s[j].first.first,s[j].first.second);
                            if(collinear_i(p,q,r)){
                                ans.push_back(make_pair(point_i(s[j].first.first,s[j].first.second),s[j].second));
                                for(int l=0;l<ans.size();l++)
                                dp[ans[l].second][s[j].second]=0;
                            }
                        }
                    }
                    if(ans.size()>2)
                    {
                    if(cnt==0) printf("The following lines were found:\n");
                    for(int t=0;t<ans.size();t++)
                     {
                         printf("(%4d,%4d)",ans[t].first.x,ans[t].first.y);
                     }
                     cnt++;
                     printf("\n");
                     ans.clear();
                     ans.push_back(make_pair(p,s[i].second));
                }
                else {ans.pop_back();dp[s[i].second][s[k].second]=-1;}
                }
                ans.clear();
                }
                if(cnt==0) printf("No lines were found\n");
                ans.clear();
                memset(dp,-1,sizeof(dp));
                s.clear();
                cnt=0;
                c=0;
            }
        }
        else{
            s.push_back(make_pair(make_pair(a,b),c));
            c++;
            flag=false;
        }

    }

}
