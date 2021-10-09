#include <bits/stdc++.h>
 
using namespace std;
 
template <class T>
struct Point {
	T x, y;
	Point(){}
	Point(T _x, T _y) : x(_x), y(_y) {}
};

template <class T>
Point<T> operator-(Point<T> A, Point<T> B) {
	return Point<T>(B.x - A.x, B.y - A.y);
}

template <class T>
T cross(Point<T> A, Point<T> B) {
	return A.x * B.y - A.y * B.x;
}

template <class T>
T dot(Point<T> A, Point<T> B) {
	return A.x * B.x + A.y * B.y;
}

template <class T>
T norm(Point<T> A) {
	return sqrt(dot(A, A));
}

template <class T>
T dist(Point<T> A, Point <T> B) {
	return norm(B - A);
}

template <class T>
bool onLine(Point<T> A, Point<T> B, Point<T> P) {
	return dist(A, P) + dist(P, B) == dist(A, B);
}

template <class T>
T area(vector<Point<T>>& Poly) { // times 2
	if ((int)Poly.size() <= 2) return 0;
	T ans = 0;
	int n = Poly.size();
	for (int u = 0; u < n; u++) {
		int v = (u + 1) % n;
		ans += (Poly[v].x - Poly[u].x) * (Poly[v].y + Poly[u].y);
	}
	return abs(ans);
}

template <class T>
bool inPoly(vector<Point<T>>& Poly, Point<T> P) {
	int n = Poly.size();
	int c = 0;
	for (int u = 0; u < n; u++) {
		int v = (u + 1) % n;
		if ((P.y < Poly[u].y != P.y < Poly[v].y) && (P.x < Poly[u].x + (Poly[v].x - Poly[u].x) * (P.y - Poly[u].y) / (Poly[v].y - Poly[u].y)))
			c ^= 1;
	}
	return c;
}
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	vector<Point<double>> Poly(n);
	for (int i = 0; i < n; i++) cin >> Poly[i].x >> Poly[i].y;

	while (m--) {
		Point<double> P;
		cin >> P.x >> P.y;
		bool on = false;
		for (int u = 0; u < n; u++) {
			int v = (u + 1) % n;
			if (onLine(Poly[u], Poly[v], P)) {
				on = true;
				break;
			}
		}
		if (on) cout << "BOUNDARY\n";
		else cout << (inPoly(Poly, P) ? "INSIDE" : "OUTSIDE") << '\n';
	}
}