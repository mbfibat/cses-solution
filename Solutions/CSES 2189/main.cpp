#include <bits/stdc++.h>

using namespace std;

int t;

struct Point {
	double x, y;
	Point(){}
	Point(double _x, double _y) : x(_x), y(_y) {}
};

double cross(const Point &A, const Point &B) {
	return A.x * B.y - A.y * B.x;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		Point A, B, C;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
		Point AB(B.x - A.x, B.y - A.y);
		Point AC(C.x - A.x, C.y - A.y);
		double val = cross(AB, AC);
		if (!val) cout << "TOUCH\n";
		else if (val > 0) cout << "LEFT\n";
		else cout << "RIGHT\n";
	}
}