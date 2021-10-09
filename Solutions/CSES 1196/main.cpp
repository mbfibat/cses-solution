#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int n, m, k;
vector<ii> adj[100001];

priority_queue<int> d[100001];

void solve() {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	d[1].push(0); pq.push(ii(0, 1));

	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d[u].size() == k && du > d[u].top()) continue;

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, w = adj[u][i].second;
			int dv = du + w;
			if (d[v].size() < k || dv < d[v].top()) {
				d[v].push(dv);
				pq.push(ii(dv, v));
			}
			if (d[v].size() > k) d[v].pop();
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
	}
	solve();

	vector<int> ans;
	for (int i = 1; i <= k; i++) {
		ans.push_back(d[n].top());
		d[n].pop();
	}
	for (int i = k - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}