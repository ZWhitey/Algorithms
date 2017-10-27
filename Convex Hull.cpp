#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
#define pb emplace_back
struct Point
{
	int x;
	int y;
	bool c=false;
};
typedef vector<Point> vp;

int cross(Point o,Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int len(Point a, Point b)
{
	return (a.x - b.x)*(a.x - b.x) - (a.y - b.y)*(a.y - b.y);
}
bool far(Point o, Point a, Point b)
{
	return len(o, a) > len(o, b);
}
vp convex(vp p)
{
	int start = 0;
	for (int i = 1, s = p.size(); i < s; ++i)
	{
		if (p[start].y > p[i].y || (p[start].y == p[i].y&&p[start].x > p[i].x))
			start = i;
	}
	p[start].c = true;
	vp r(1,p[start]);
	while (true)
	{
		int n = start;
		for (int i = 0, s = p.size(); i < s; ++i)
		{
			if (!p[i].c)
			{
				int cro = cross(r.back(), p[i], p[n]);
				if (cro < 0 || (cro == 0 && far(r.back(), p[i], p[n])))
					n = i;
			}
		}
		if (n == start)
			break;
		r.pb(p[n]);
		p[n].c = true;
	}
	return r;
}

int main()
{
	string input[3];
	input[0] = "7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9";
	input[1] = "7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5";
	input[2] = "0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 0 0 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 1 1 2 2 3 3 4 4 5 5 6 6 1 -1 2 -2 3 -3 4 -4 5 -5 6 -6 -1 1 -2 2 -3 3 -4 4 -5 5 -6 6 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 -6";
	for (auto i : input)
	{
		vp p;
		stringstream ss;
		ss << i;
		Point t;
		while (ss >> t.x >> t.y)
			p.pb(t);
		vp r = convex(p);//8 (0, -9) (7, -7) (9, 0) (7, 7) (0, 9) (-7, 7) (-9, 0) (-7, -7)
	}
	return 0;
}