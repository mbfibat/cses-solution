#include <bits/stdc++.h>

using namespace std;

#define int long long

const int p = 31;
int pow_p[200001];

int n, m; string s;
int Seg[2][800001];

void update(int id, int node, int l, int r, int pos, int val) {
	if (l == r) {
		Seg[id][node] = (pow_p[n - l] * val);
		return;
	}

	int mi = (l + r) / 2;
	if (pos <= mi) update(id, node * 2, l, mi, pos, val);
	else update(id, node * 2 + 1, mi + 1, r, pos, val);
	Seg[id][node] = Seg[id][node * 2] + Seg[id][node * 2 + 1];
}

int query(int id, int node, int l, int r, int ll, int rr) {
	if (r < ll || rr < l) return 0;
	if (ll <= l && r <= rr) return Seg[id][node];

	int mi = (l + r) / 2;
	int a = query(id, node * 2, l, mi, ll, rr);
	int b = query(id, node * 2 + 1, mi + 1, r, ll, rr);
	return a + b;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pow_p[0] = 1;
	for (int i = 1; i <= 200000; i++)
		pow_p[i] = pow_p[i - 1] * p;

	cin >> n >> m;
	cin >> s; s = '*' + s;
	for (int i = 1; i <= n; i++) {
		update(0, 1, 1, n, i, s[i] - 'a' + 1);
		update(1, 1, 1, n, n - i + 1, s[i] - 'a' + 1);
	}

	for (int i = 1; i <= m; i++) {
		int t; cin >> t;
		if (t == 1) {
			int pos; char c; cin >> pos >> c;
			update(0, 1, 1, n, pos, c - 'a' + 1);
			update(1, 1, 1, n, n - pos + 1, c - 'a' + 1);				
		}
		else {
			int l, r; cin >> l >> r;
			int h0 = query(0, 1, 1, n, l, r);
			int h1 = query(1, 1, 1, n, n - r + 1, n - l + 1);
			if (r >= n - l + 1) h0 *= pow_p[r - (n - l + 1)];
			else h1 *= pow_p[(n - l + 1) - r];
			cout << ((h0 == h1) ? "YES" : "NO") << '\n';
		}
	}
}