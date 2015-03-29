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

using namespace std;

struct Point
{
	double x, y;

	Point(double x=0, double y=0) : x(x), y(y) {}

	double distance (const Point &o) const
	{
		return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
	}

	Point operator+(const Point &o) const
	{
		return Point(x+o.x, y+o.y);
	}

	Point operator-(const Point &o) const
	{
		return Point(x-o.x, y-o.y);
	}

	Point operator*(const double m) const
	{
		return Point(x*m, y*m);
	}

	Point operator/(const double d) const
	{
		return Point(x/d, y/d);
	}

	double cross(const Point &o) const
	{
		return x * o.y - y * o.x;
	}

	double dot(const Point &o) const
	{
		return x * o.x + y * o.y;
	}

	double atan() const
	{
		return atan2(y, x);
	}

	double norm() const
	{
		return sqrt(dot(*this));
	}

	double area_abs(const Point &a,const Point &b) const
	{
		double t = (a.x - x) * (b.y - y);
		double t2 = (a.y - y) * (b.x - x);
		double areas = abs(t-t2);
		return areas/2;
	}

	//符号付き面積
	double area(const Point &a,const Point &b)
	{
		return ((a.x - x) * (b.y - y)) + ((b.x - x) * (y - a.y));
	}

	//線分abが自身に含まれているのかどうか判断する
	int between(const Point &a,const Point &b)
	{
		if(area(a,b) != 0) return 0;

		if(a.x != b.x)
		{
			return ((a.x <= x) && (x <= b.x) || (a.x >= x) && (x >= b.x));
		}
		else
		{
			return ((a.y <= y) && (y <= b.y) || (a.y >= y) && (y >= b.y));
		}
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

};

struct Seg
{
	Point a,b;

	Seg (Point a, Point b) : a(a),b(b) {}

	bool isIntersect(Seg &s)
	{
		return ((a-b).cross(s.a-a) * (a-b).cross(s.b-a) < EPS) && ((s.b-s.a).cross(a-s.a)*(s.b-s.a).cross(b-s.a) < EPS);
	}

	int getCrossPoint(Seg &s,Point &p)
	{
		Point ac = s.a - a;
		int sw = -1;

		double temp = (b.x - a.x) * (s.b.y - s.a.y) - (b.y - a.y) * (s.b.x - s.a.x);

		if(fabs(temp) > EPS)
		{
			double r = ((s.b.y - s.a.y) * p.x - (s.b.x - s.a.y) * p.y) / temp;
			double s = ((b.y - a.y) * p.x - (b.x - a.x) * p.y) / temp;
			if(r > -EPS && r < 1.0 + EPS && s > -EPS && s < 1.0 + EPS)
			{
				p.x = a.x + r * (b.x - a.x);
				p.y = a.y + r * (b.y - a.y);
				sw = 1;
			}
			else sw = 0;
		}
		return sw;	
	}
};

int main()
{
	int n;
	cin >> n;

	queue<Point> que;
	int sy,sx;
	cin >> sx >> sy;
	Point s(sx,sy);

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

			if(a.cross(b) != 0)
			{
				v.push_back(ret);
			}
		}

		rep(i,v.size())
		{
			que.push(v[i]);
		}
		ans++;
	}

	cout << ans << endl;

	return 0;
}
