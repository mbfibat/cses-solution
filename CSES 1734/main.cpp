#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int n, q;
int a[200001];
iii Q[200001];
int ans[200001];

map<int, int> pre;

int BIT[200001];

void upd(int x, int val) {
	for (; x <= n; x += x & (-x))
		BIT[x] += val;
}

int query(int x) {
	int ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += BIT[x];
	return ans;	
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].first.first >> Q[i].first.second;
		Q[i].second = i;
	}	
	auto cmp = [&](const iii &lhs, const iii &rhs) -> bool {
		return lhs.first.second < rhs.first.second;
	};
	sort(Q + 1, Q + 1 + q, cmp);
	
	int p = 1;
	for (int i = 1; i <= n; i++) {
		if (pre.count(a[i]))
			upd(pre[a[i]], -1);
		upd(i, 1);
		pre[a[i]] = i;
		while (p <= q && Q[p].first.second == i) {
			ans[Q[p].second] = query(i) - query(Q[p].first.first - 1);
			p++;
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
}