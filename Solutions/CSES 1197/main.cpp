#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int n, m;
vector<ii> adj[2501];

int d[2501], p[2501];

void find_cycle() {
	int s = -1;
	for (int _ = 1; _ <= n; _++)
		for (int u = 1; u <= n; u++) {
			if (d[u] == 1e18) continue;
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i].first, w = adj[u][i].second;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					p[v] = u;
					s = v;
				}
			}
		}	
	if (s == -1) return;

	for (int i = 1; i <= n; i++) s = p[s];

	cout << "YES\n";
	vector<int> ans; ans.push_back(s);
	int t = s;
	do {
		t = p[t];
		ans.push_back(t);
	} while (t != s);

	reverse(ans.begin(), ans.end());
	for (int v : ans)
		cout << v << ' ';
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
	}

	for (int _ = 1; _ <= n; _++)
		for (int u = 1; u <= n; u++) {
			if (d[u] == 1e18) continue;
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i].first, w = adj[u][i].second;
				if (d[v] > d[u] + w)
					d[v] = d[u] + w;
			}
		}	
	find_cycle();
	cout << "NO";
}