#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair
#define EPS 1e-10
#define equals(a,b) fabs((a) - (b)) < EPS

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct Point {
    double x, y;

    Point(double x=0, double y=0) : x(x), y(y) {}

    Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

    Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

    Point operator*(const double m) const { return Point(x*m, y*m); }

    Point operator/(const double d) const { return Point(x/d, y/d); }

    bool operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

    bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }

    double cross(const Point &o) const { return x * o.y - y * o.x; }

    double dot(const Point &o) const { return x * o.x + y * o.y; }

    double atan() const { return atan2(y, x); }

    double norm() const { return sqrt(dot(*this)); }

    double distance(const Point &o) const { return (o - (*this)).norm(); }

    double area(const Point &a,const Point &b) {
        Point p = a - (*this), p2 = b - (*this); 
        return p.cross(p2);
    }

    double area_abs(const Point &a,const Point &b) const {
        Point p = a - (*this), p2 = b - (*this);
        return fabs(p.cross(p2)) / 2.0;
    }	

    //線分abが自身に含まれているのかどうか判断する
    int between(const Point &a,const Point &b) {
        if(area(a,b) != 0) return 0;

        if(a.x != b.x)  return ((a.x <= x) && (x <= b.x) || (a.x >= x) && (x >= b.x));
        else return ((a.y <= y) && (y <= b.y) || (a.y >= y) && (y >= b.y));
    }      

    double distance_seg(const Point& a,const Point& b) {
        if((b-a).dot(*this-a) < EPS) {
            return (*this-a).norm();
        }
        if((a-b).dot(*this-b) < EPS) {
            return (*this-b).norm();
        }
        return abs((b-a).cross(*this-a)) / (b-a).norm();
    }

    bool hitPolygon(const Point& a,const Point& b,const Point& c) {
        double t = (b-a).cross(*this-b);
        double t2 = (c-b).cross(*this-c);
        double t3 = (a-c).cross(*this-a);	

        if((t > 0 && t2 > 0 && t3 > 0) || ( t < 0 && t2 < 0 && t3 < 0)) {
            return true;
        }

        return false;
    }
};

struct Seg {
    Point a,b;

    Seg (Point a, Point b) : a(a),b(b) {}

    bool isOrthogonal(Seg &s) { return equals((b - a).dot(s.b - s.a),0.0); }

    bool isParallel(Seg &s) { return equals((b-a).cross(s.b - s.a),0.0); }

    bool isIntersect(Seg &s) {
        if(s.a.between(a,b) || s.b.between(a,b) || a.between(s.a,s.b) || b.between(s.a,s.b)) {
            return true;
        }
        return ((a-b).cross(s.a-a) * (a-b).cross(s.b-a) < EPS) && ((s.b-s.a).cross(a-s.a)*(s.b-s.a).cross(b-s.a) < EPS);
    }

    bool distance(Seg &s) {
        if((*this).isIntersect(s)) return 0.0;

        return min(min(a.distance_seg(s.a,s.b),b.distance_seg(s.a,s.b)),min(s.a.distance_seg(a,b),s.b.distance_seg(a,b)));
    }

    Point getCrossPoint(Seg &s) {
        Point p = s.b - s.a;
        double d = abs(p.cross(a-s.a));
        double d2 = abs(p.cross(b-s.a));

        double t = d / (d+d2);
        return a + (b-a)*t;
    }

    Point project(Point &p) {
        Point base = b - a;
        double t = base.dot(p-a) / base.dot(base);
        return a + base * t;
    }

    Point reflect(Point &p) {
        return p + (project(p) - p) * 2.0;
    }
};

int main() {
    int x,y;

    while(cin >> x >> y) {
    // cin >> x >> y;

    if(y > x) {
        cout << -1 << endl;
        return 0;
    }

    Seg seg(Point(0,0), Point(max(x,y),max(x,y)));

    Point p(x,y);
    Seg o(Point(x-max(x,y),y+max(x,y)), p);

    Point c = seg.getCrossPoint(o);

    while(c.y / 2.0 > y - EPS) {
        c.x /= 2.0;
        c.y /= 2.0;
    }

    double ans = c.x;
    int nx = x - y;

    Seg o2(Point(nx-max(x,y), 0+max(x,y)), Point(nx,0));
    Point c2 = seg.getCrossPoint(o2);

    while(c2.y / 2.0 > y - EPS) {
        c2.x /= 2.0;
        c2.y /= 2.0;
    }

    if(c2.x > y - EPS) {
        ans = min(ans, c2.x);
    }

    int ret = min(x,y);
    if(nx % (2*y) == 0) {
        ans = min(ans, (double)y);
    }
    cout << fixed;
    cout.precision(10);
    cout << ans << endl;
    }

    return 0;
}
