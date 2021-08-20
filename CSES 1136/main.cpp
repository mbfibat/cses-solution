#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q;
vector<int> adj[200001];

int lca[200001][21], h[200001];
void dfs(int u, int p) {
	for (int v : adj[u])
		if (v != p) {
			h[v] = h[u] + 1;
			lca[v][0] = u;
			dfs(v, u);
		}
}

int cal_lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int j = 20; j >= 0; j--)
		if (h[lca[v][j]] >= h[u])
			v = lca[v][j];
	if (u == v) return u;
	for (int j = 20; j >= 0; j--)
		if (lca[u][j] != lca[v][j]) {
			u = lca[u][j];
			v = lca[v][j];
		}
	return lca[u][0];	
}

int inc[200001], val[200001];
void dfs2(int u, int p) {
	for (int v : adj[u])
		if (v != p)
			dfs2(v, u);
	if (p != -1)
		val[p] += val[u];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	h[1] = 1;
	dfs(1, -1);
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n; i++)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];

	while (q--) {
		int x, y; cin >> x >> y;
		int l = cal_lca(x, y);
		val[x]++, val[y]++, val[l]--, val[lca[l][0]]--;
	}

	dfs2(1, -1);
	for (int i = 1; i <= n; i++) cout << val[i] << ' ';
}