#include <bits/stdc++.h>

using namespace std;

int n;

struct Node {
	int sum, mx, mn;
	Node (){}
}Seg[800001];

void update(int node, int l, int r, int p, int v) {
	if (l == r) {
		Seg[node].sum = Seg[node].mx = Seg[node].mn = v;
		return;
	}
	int mi = (l + r) / 2;
	if (p <= mi) update(node * 2, l, mi, p, v);
	else update(node * 2 + 1, mi + 1, r, p, v);
	Seg[node].sum = Seg[node * 2].sum + Seg[node * 2 + 1].sum;
	Seg[node].mx = max(Seg[node * 2].mx + Seg[node * 2 + 1].sum, Seg[node * 2 + 1].mx);
	Seg[node].mn = min(Seg[node * 2].mn + Seg[node * 2 + 1].sum, Seg[node * 2 + 1].mn);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p, id; cin >> p >> id;
		update(1, 1, n, p, (id == 1) ? 1 : -1);
		if (Seg[1].mn >= 0) cout << '>' << '\n';
		else if (Seg[1].mx <= 0) cout << '<' << '\n';
		else cout << '?' << '\n';	
	}
}