#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
vector<ii> adj[100001];
int d[2][100001];

void sp() {
	for (int i = 1; i <= n; i++)
		d[0][i] = d[1][i] = 1e18;
	d[0][1] = 0;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push(iii(0, ii(0, 1))); 

	while (!pq.empty()) {
		int du = pq.top().first, t = pq.top().second.first, u = pq.top().second.second;
		pq.pop();
		if (du != d[t][u]) continue;

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (d[t][v] > d[t][u] + w) {
				d[t][v] = d[t][u] + w;
				pq.push(iii(d[t][v], ii(t, v)));
			}
			if (!t && d[t + 1][v] > d[t][u] + w/2) {
				d[t + 1][v] = d[t][u] + w/2;
				pq.push(iii(d[t + 1][v], ii(t + 1, v)));								
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
		adj[u].push_back(ii(v, c));
	}

	sp();

	cout << min(d[0][n], d[1][n]);
}