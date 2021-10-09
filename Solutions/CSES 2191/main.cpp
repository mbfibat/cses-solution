#include <bits/stdc++.h>
 
using namespace std;
 
int t;
 
template <class T>
struct Point {
	T x, y;
	Point(){}
	Point(T _x, T _y) : x(_x), y(_y) {}
};

template <class T>
bool onLine(Point<T> A, Point<T> B, Point<T> P) {
	if (A.x >= B.x) swap(A.x, B.x);
	if (A.y >= B.y) swap(A.y, B.y);
	return (A.x <= P.x && P.x <= B.x) && (A.y <= P.y && P.y <= B.y);
}

template <class T>
T cross(const Point<T> &A, const Point<T> &B) {
	return A.x * B.y - A.y * B.x;
}

template <class T>
T area(vector<Point<T>> Poly) {
	if ((int)Poly.size() <= 2) return 0;
	T ans = 0;
	int n = Poly.size();
	for (int u = 0; u < n; u++) {
		int v = (u + 1) % n;
		ans += (Poly[v].x - Poly[u].x) * (Poly[v].y + Poly[u].y);
	}
	return abs(ans);
}
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<Point<long long>> Poly(n);
	for (int i = 0; i < n; i++) cin >> Poly[i].x >> Poly[i].y;
	cout << area(Poly);
}