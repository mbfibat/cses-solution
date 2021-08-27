#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<int> adj[200001];

int fd[200001], fu[200001], nChild[200001];

void dfs1(int u, int p) {
	nChild[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs1(v, u);
		fd[u] += (fd[v] + nChild[v]);
		nChild[u] += nChild[v];
	}
}

void dfs2(int u, int p) {
	if (p != -1)
		fu[u] = (fu[p] + fd[p] - fd[u] + n - 2 * nChild[u]);
	for (int v : adj[u])
		if (v != p)
			dfs2(v, u);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1, -1);	
	dfs2(1, -1);
	for (int i = 1; i <= n; i++)
		cout << fu[i] + fd[i] << ' ';
}