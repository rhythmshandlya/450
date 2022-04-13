/*
Optimum location of point to minimize total distance.
Given a set of points as and a line as ax+by+c = 0.
We need to find a point on given line for which sum of
distances from given set of points is minimum.
*/

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;


class line {
	int x, y, c;
public:
	line(int x, int y, int c) {
		this->x = x;
		this->y = y;
		this->c = c;
	}
	void print() {
		cout << x << "x"
		     << (y >= 0 ? "+" : "-") << abs(y) << "y"
		     << (c >= 0 ? "+" : "-") << abs(c)
		     << "=0";
	};
};

class point {
	int x, y;
public:
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << "(" << x << "," << y << ")";
	}
};


double distance(point p1, point p2) {

}

double sumOfDistances(vector<points> &arr, point p) {

}

int main()
{
	line l(1, 20, 100);
	point p(10, -20);

	l.print();
	cout << "\n";
	p.print();

	vector<point> v = {};

	return 0;
}