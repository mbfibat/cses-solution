#include <bits/stdc++.h>
 
using namespace std;
 
int t;
 
struct Point {
	double x, y;
	Point(){}
	Point(double _x, double _y) : x(_x), y(_y) {}
};

bool onLine(Point A, Point B, Point P) {
	if (A.x >= B.x) swap(A.x, B.x);
	if (A.y >= B.y) swap(A.y, B.y);
	return (A.x <= P.x && P.x <= B.x) && (A.y <= P.y && P.y <= B.y);
}

double cross(const Point &A, const Point &B) {
	return A.x * B.y - A.y * B.x;
}
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int t; cin >> t;
	while (t--) {
		Point A, B, C, D;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
		Point AB(B.x - A.x, B.y - A.y);
		Point AC(C.x - A.x, C.y - A.y);
		Point AD(D.x - A.x, D.y - A.y);
		double val_1 = cross(AB, AC), val_2 = cross(AB, AD);
 
		Point CA(A.x - C.x, A.y - C.y);
		Point CB(B.x - C.x, B.y - C.y);
		Point CD(D.x - C.x, D.y - C.y);
		double val_3 = cross(CD, CA), val_4 = cross(CD, CB);
		if (val_1 == 0 && onLine(A, B, C) ||
		val_2 == 0 && onLine(A, B, D) ||
		val_3 == 0 && onLine(C, D, A) ||
		val_4 == 0 && onLine(C, D, B)) cout << "YES\n";
		else if (val_1 * val_2 < 0 && val_3 * val_4 < 0) cout << "YES\n";
		else cout << "NO\n";
	}
}