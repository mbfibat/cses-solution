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
T norm(Point<T> A) {
	return sqrt(A.x * A.x + A.y * A.y);
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

template <class T>
long long bound(vector<Point<T>>& Poly) { // lattice point on boundary
	int n = Poly.size();
	long long cnt = n;
	for (int u = 0; u < n; u++) {
		int v = (u + 1) % n;
		if (Poly[u].x == Poly[v].x) cnt += abs(Poly[u].y - Poly[v].y) - 1;
		else if (Poly[u].y == Poly[v].y) cnt += abs(Poly[u].x - Poly[v].x) - 1;
		else cnt += (__gcd(abs(Poly[u].y - Poly[v].y), abs(Poly[u].x - Poly[v].x)) - 1);
	}
	return cnt;
}

template <class T>
long long inside(vector<Point<T>>& Poly) { // lattice point inside
	return area(Poly)/2 + 1 - bound(Poly)/2;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<Point<long long>> Poly(n);
	for (int i = 0; i < n; i++)
		cin >> Poly[i].x >> Poly[i].y;
	cout << inside(Poly) << ' ' << bound(Poly);
}