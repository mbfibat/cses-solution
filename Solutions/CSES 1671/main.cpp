#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int n, m;
vector<ii> adj[100001];

int d[100001];

void sp(int u) {
	for (int i = 1; i <= n; i++) d[i] = 1e18;
	d[u] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, u));

	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int w = adj[u][i].first, v = adj[u][i].second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push(ii(d[v], v));
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(ii(c, v));
	}

	sp(1);
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
}