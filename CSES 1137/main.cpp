#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q;
int a[200001];
vector<int> adj[200001];

int st[200001], ed[200001], top = 0;
void dfs(int u, int p) {
	st[u] = ++top;
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);
	ed[u] = top;
}

int BIT[200001];

void update(int x, int v) {
	for (; x <= n; x += x & (-x))
		BIT[x] += v;
}

int query(int x) {
	int ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += BIT[x];
	return ans;	
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);

	for (int i = 1; i <= n; i++)
		update(st[i], a[i]);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int p, v; cin >> p >> v;
			update(st[p], -a[p]);
			a[p] = v;
			update(st[p], a[p]);
		}
		else {
			int s; cin >> s;
			cout << query(ed[s]) - query(st[s] - 1) << '\n';
		}
	}
}