#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
 
int n, m;
vector<ii> adj[2501];
 
int d[2501];

 
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back(ii(v, -c));
	}

	for (int i = 1; i <= n; i++) d[i] = 1e18;
	d[1] = 0;
 
	for (int _ = 1; _ <= n; _++)
		for (int u = 1; u <= n; u++) {
			if (d[u] == 1e18) continue;
			for (int k = 0; k < adj[u].size(); k++) {
				int v = adj[u][k].first, w = adj[u][k].second;
				if (d[v] > d[u] + w)
					d[v] = d[u] + w;
			}
		}

	for (int _ = 1; _ <= n; _++)
		for (int u = 1; u <= n; u++) {
			if (d[u] == 1e18) continue;
			for (int k = 0; k < adj[u].size(); k++) {
				int v = adj[u][k].first, w = adj[u][k].second;
				if (d[v] > d[u] + w)
					d[v] = -1e18;
			}
		}	

	if (d[n] == -1e18) d[n] = 1;
	cout << -d[n];
}