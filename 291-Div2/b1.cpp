#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS

using namespace std;

struct Point
{
    double x, y;

    Point(double x=0, double y=0) : x(x), y(y) {}

    Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

    Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

    Point operator*(const double m) const { return Point(x*m, y*m); }

    Point operator/(const double d) const { return Point(x/d, y/d); }

    Point operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

	bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }

	double cross(const Point &o) const { return x * o.y - y * o.x; }

    double dot(const Point &o) const { return x * o.x + y * o.y; }

    double atan() const { return atan2(y, x); }

    double norm() const { return sqrt(dot(*this)); }

    double distance(const Point &o) const { return (o - (*this)).norm(); }

    double area(const Point &a,const Point &b)
    {
	    Point p = a - (*this), p2 = b - (*this); 
	    return p.cross(p2);
    }

    double area_abs(const Point &a,const Point &b) const
    {
	    Point p = a - (*this), p2 = b - (*this);
	    return fabs(p.cross(p2)) / 2.0;
    }	

    //線分abが自身に含まれているのかどうか判断する
    int between(const Point &a,const Point &b)
	{
		if(area(a,b) != 0) return 0;

    	if(a.x != b.x)  return ((a.x <= x) && (x <= b.x) || (a.x >= x) && (x >= b.x));
	    else return ((a.y <= y) && (y <= b.y) || (a.y >= y) && (y >= b.y));
    }      

	double distance_seg(const Point& a,const Point& b)
	{
    	if((b-a).dot(*this-a) < EPS)
    	{
	    	return (*this-a).norm();
	    }
	    if((a-b).dot(*this-b) < EPS)
    	{
	    	return (*this-b).norm();
    	}
	    return abs((b-a).cross(*this-a)) / (b-a).norm();
	}

	bool hitPolygon(const Point& a,const Point& b,const Point& c)
	{
    	double t = (b-a).cross(*this-b);
    	double t2 = (c-b).cross(*this-c);
    	double t3 = (a-c).cross(*this-a);
    	if((t > 0 && t2 > 0 && t3 > 0) || ( t < 0 && t2 < 0 && t3 < 0))
    	{
    		return true;
    	}

	    return false;
    }
};

int main()
{
	int n;
	cin >> n;

	int sx,sy;
	cin >> sx >> sy;
	Point s(sx,sy);

	queue<Point> que;
	rep(i,n)
	{
		int x,y;
		cin >> x >> y;
		que.push(Point(x,y));
	}

	int ans = 0;
	while(que.size())
	{
		Point p = que.front();
		que.pop();

		vector<Point> v;
		while(que.size())
		{
			Point ret = que.front();
			que.pop();

			Point a = s - ret;
			Point b = p - ret;

			if(a.cross(b) != 0) v.push_back(ret);
		}

		rep(i,v.size()) que.push(v[i]);
		ans++;
	}

	cout << ans << endl;
	
	return 0;
}
