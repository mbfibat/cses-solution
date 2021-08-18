#include <bits/stdc++.h>

using namespace std;

#define int long long

int f[200001][2];

int n;
vector<int> adj[200001];

void dfs(int u, int p) {
	if (adj[u].size() == 1 && u != 1) {
		f[u][0] = 0;
		f[u][1] = -1e9;
		return;
	} 

	int sum_1 = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		sum_1 += max(f[v][0], f[v][1]);
		f[u][0] += max(f[v][0], f[v][1]);
	}

	for (int v : adj[u]) {
		if (v == p) continue;
		f[u][1] = max(f[u][1], sum_1 - max(f[v][0], f[v][1]) + f[v][0] + 1);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	dfs(1, -1);
	cout << max(f[1][0], f[1][1]);
}