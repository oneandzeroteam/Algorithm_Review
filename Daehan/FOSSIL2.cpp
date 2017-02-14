#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct point {
	double y, x;

	point(double X, double Y) :y(Y), x(X) {}
};

vector<pair<point, point>> upper, lower;

vector<point> hull1, hull2;

void decompose(const vector<point>& hull) {

	int n = hull.size();
	

	for (int i = 0; i < n; ++i) {
		if (hull[i].x < hull[(i + 1) % n].x)
			lower.push_back(make_pair(hull[i], hull[(i + 1) % n]));
		else if (hull[i].x > hull[(i + 1) % n].x)
			upper.push_back(make_pair(hull[i], hull[(i + 1) % n]));
	}

}


bool between(const point& a, const point& b, double x) {

	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);

}

double at(const point& a, const point& b, double x) {

	double dx = a.x - b.x, dy = a.y - b.y;

	return a.y + (x - a.x) * dy / dx;

}

double vertical(double x) {

	double minUp = 1e20, maxLow = -1e20;

	for (int i = 0; i < upper.size(); ++i) {
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));

	}

	for (int i = 0; i < lower.size(); ++i) {
		if (between(lower[i].first, lower[i].second, x))
			maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
	}
	return minUp - maxLow;

}

double minX(const vector<point>& hull) {

	double ret = 1e20;

	for (int i = 0; i < hull.size(); ++i) {
		ret = min(ret, hull[i].x);
	}

	return ret;

}

double maxX(const vector<point>& hull) {

	double ret = -1e20;

	for (int i = 0; i < hull.size(); ++i) {
		ret = max(ret, hull[i].x);
	}

	return ret;

}

int main() {

	int C;
	cin >> C;

	cout.setf(ios::fixed);
	cout.precision(10);

	while (C--) {
		
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			double temp_x, temp_y;
			cin >> temp_x >> temp_y;
			hull1.push_back(point(temp_x, temp_y));
		}

		for (int i = 0; i < m; ++i) {
			double temp_x, temp_y;
			cin >> temp_x >> temp_y;
			hull2.push_back(point(temp_x, temp_y));
		}

		decompose(hull1);
		decompose(hull2);

		double lo = min(minX(hull1), minX(hull2));
		double hi = max(maxX(hull1), maxX(hull2));

		if (hi < lo)
		{
			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < 100; ++i) {
			double mid1 =( 2*lo + hi)/3, mid2 = (lo + 2*hi)/3;
			if (vertical(mid1) < vertical(mid2))
				lo = mid1;
			else// if (vertical(mid1) >= vertical(mid2))
				hi = mid2;
		}

		double sol = vertical(hi);

	
//		if (sol < 0)
//			cout << 0.0 << endl;
//		else
//			cout << sol << endl;

		cout << max(0.0, sol) << endl;

		hull1.clear();
		hull2.clear();
		upper.clear();
		lower.clear();

	}
}
