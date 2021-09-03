#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n, m;
vector<int> adj[100001];

int f[100001];
bool g[100001];

int dp(int u) {
	if (u == n) return 1;
	if (g[u]) return f[u];

	int &cur = f[u];
	for (int v : adj[u])
		(cur += dp(v)) %= mod;
	g[u] = true;
	return cur;	
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	cout << dp(1);
}