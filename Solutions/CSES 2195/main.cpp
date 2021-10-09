#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Point {
	T x, y;
	Point(){}
	Point(T _x, T _y) : x(_x), y(_y) {}

	bool operator<(Point<T> B) {
		if (this->x != B.x) return this->x < B.x;
		return this->y < B.y;
	}
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
bool cw(Point<T> A, Point<T> B, Point<T> C) {
	return cross(C - A, B - A) >= 0;
}

template <class T>
bool ccw(Point<T> A, Point<T> B, Point<T> C) {
	return cross(C - A, B - A) <= 0;
}

template <class T>
vector<Point<T>> convexHull(vector<Point<T>> P) {
	sort(P.begin(), P.end());	
	vector<Point<T>> up, down;
	Point<T> p0 = P[0], pn = P.back();
	up.push_back(p0);
	for (int i = 1; i < (int)P.size(); i++) {
		if (cw(p0, P[i], pn)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], P[i]))
				up.pop_back();
			up.push_back(P[i]);
		}
	}
	down.push_back(pn);
	for (int i = (int)P.size() - 2; i >= 0; i--) {
		if (ccw(p0, P[i], pn)) {
			while (down.size() >= 2 && !cw(down[down.size() - 2], down[down.size() - 1], P[i]))
				down.pop_back();
			down.push_back(P[i]);
		}
	}

	vector<Point<T>> ans;
	for (int i = 0; i < (int)up.size() - 1; i++) ans.push_back(up[i]);
	for (int i = 0; i < (int)down.size() - 1; i++) ans.push_back(down[i]);
	return ans;
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
	vector<Point<long long>> P(n);
	for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;
	vector<Point<long long>> ans = convexHull(P);
	cout << ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i].x << ' ' << ans[i].y << '\n';	
}