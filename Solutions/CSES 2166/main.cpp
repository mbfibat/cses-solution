#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n, q;
int a[200001];

int BIT[200001];

void updBIT(int x, int val) {
	for (; x <= n; x += x & (-x))
		BIT[x] += val;
}

int queryBIT(int x) {
	int ans = 0;
	for (; x > 0; x -= x & (-x)) 
		ans += BIT[x];
	return ans;
}

int Seg[800001], lazy[800001];

void build(int node, int l, int r) {
	if (l == r) {
		Seg[node] = queryBIT(l);
		return;
	}
	int mi = (l + r) / 2;
	build(node * 2, l, mi);
	build(node * 2 + 1, mi + 1, r);
	Seg[node] = max(Seg[node * 2], Seg[node * 2 + 1]);
}

void diffuse(int node, int l, int r) {
	if (lazy[node]) {
		Seg[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int ll, int rr, int v) {
	diffuse(node, l, r);
	if (r < ll || rr < l) return;	
	if (ll <= l && r <= rr) {
		lazy[node] += v;
		diffuse(node, l, r);
		return;
	}
	int mi = (l + r) / 2;
	update(node * 2, l, mi, ll, rr, v);
	update(node * 2 + 1, mi + 1, r, ll, rr, v);
	Seg[node] = max(Seg[node * 2], Seg[node * 2 + 1]);
}

int query(int node, int l, int r, int ll, int rr) {
	diffuse(node, l, r);
	if (r < ll || rr < l) return -1e18;
	if (ll <= l && r <= rr) return Seg[node];
	int mi = (l + r) / 2;
	int a = query(node * 2, l, mi, ll, rr);
	int b = query(node * 2 + 1, mi + 1, r, ll, rr);
	return max(a, b);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		updBIT(i, a[i]);
	}	
	build(1, 1, n);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y;
			updBIT(x, y - a[x]);
			update(1, 1, n, x, n, y - a[x]);
			a[x] = y;
		}
		else {
			int x, y; cin >> x >> y;
			cout << max(0LL, query(1, 1, n, x, y) - queryBIT(x - 1)) << '\n';
		}
	}
}