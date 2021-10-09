#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n, q;
int a[200001];

struct Node {
	LL sum, lazyVal, lazySum;
	Node(){}
}Seg[800001];

void build(int node, int l, int r) {
	if (l == r) {
		Seg[node].sum = a[l];
		return;
	}            

	int mi = (l + r) / 2;
	build(node * 2, l, mi);
	build(node * 2 + 1, mi + 1, r);
	Seg[node].sum = Seg[node * 2].sum + Seg[node * 2 + 1].sum;
}

void diffuse(int node, int l, int r) {
	if (Seg[node].lazyVal) {
		Seg[node].sum = Seg[node].lazyVal * (r - l + 1);
		if (l != r) {	
			Seg[node * 2].lazyVal = Seg[node].lazyVal;
			Seg[node * 2 + 1].lazyVal = Seg[node].lazyVal;
			Seg[node * 2].lazySum = 0;
			Seg[node * 2 + 1].lazySum = 0;
		}
		Seg[node].lazyVal = 0;
	}
	if (Seg[node].lazySum) {
		Seg[node].sum += Seg[node].lazySum * (r - l + 1);
		if (l != r) {
			Seg[node * 2].lazySum += Seg[node].lazySum;
			Seg[node * 2 + 1].lazySum += Seg[node].lazySum;
		}
		Seg[node].lazySum = 0;
	}
}

void updateVal(int node, int l, int r, int ll, int rr, int v) {
	diffuse(node, l, r);
	if (r < ll || rr < l) return;
	if (ll <= l && r <= rr) {
		Seg[node].lazySum = 0;
		Seg[node].lazyVal = v;
		diffuse(node, l, r);
		return;
	}
	int mi = (l + r) / 2;
	updateVal(node * 2, l, mi, ll, rr, v);
	updateVal(node * 2 + 1, mi + 1, r, ll, rr, v);
	Seg[node].sum = Seg[node * 2].sum + Seg[node * 2 + 1].sum;
}

void updateSum(int node, int l, int r, int ll, int rr, int v) {
	diffuse(node, l, r);
	if (r < ll || rr < l) return;
	if (ll <= l && r <= rr) {
		Seg[node].lazySum += v;
		diffuse(node, l, r);
		return;		
	}
	int mi = (l + r) / 2;
	updateSum(node * 2, l, mi, ll, rr, v);
	updateSum(node * 2 + 1, mi + 1, r, ll, rr, v);
	Seg[node].sum = Seg[node * 2].sum + Seg[node * 2 + 1].sum;		
}

LL query(int node, int l, int r, int ll, int rr) {
	diffuse(node, l, r);
	if (r < ll || rr < l) return 0;
	if (ll <= l && r <= rr) return Seg[node].sum;
	int mi = (l + r) / 2;
	LL a = query(node * 2, l, mi, ll, rr);
	LL b = query(node * 2 + 1, mi + 1, r, ll, rr);
	return a + b;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, v; cin >> l >> r >> v;
			updateSum(1, 1, n, l, r, v);
		}
		else if (t == 2) {
			int l, r, v; cin >> l >> r >> v;
			updateVal(1, 1, n, l, r, v);
		}
		else {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}