#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];

int f[100001];
bool g[100001];

int dp(int u) {
	if (u == n) return f[u] = 1;
	if (g[u]) return f[u];

	int cur = -1e9;
	for (int v : adj[u])
		cur = max(cur, dp(v) + 1);
	g[u] = true;
	return f[u] = cur;
}

void trace(int u) {
	cout << u << ' ';
	if (u == n) return;
	for (int v : adj[u])
		if (dp(u) == dp(v) + 1) {
			trace(v);
			return;
		}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	dp(1);
	if (!f[n]) {
		cout << "IMPOSSIBLE";
		return 0;
	}
		
	cout << dp(1) << '\n';
	trace(1);
}