#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int p2[100001];

int n, m;
vector<int> adj[100001];
bool vis[100001];

int E, V;
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	V++;
	for (int v : adj[u]) {
		E++;
		if (!vis[v])
			dfs(v);	
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	p2[0] = 1;
	for (int i = 1; i <= 100000; i++)
		p2[i] = (p2[i - 1] * 2) % mod;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 1;
	for (int i = 1; i <= n; i++) 
		if (!vis[i]) {
			E = V = 0;
			dfs(i);	
			E /= 2;
			(ans *= p2[E - V + 1]) %= mod;
		}	
	cout << ans;	
}