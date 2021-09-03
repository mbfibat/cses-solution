#include <bits/stdc++.h>

using namespace std;

#define int long long     

const int mod = 1e9 + 7;

typedef pair<int, int> ii;

int n, m;
vector<ii> adj[100001];

int d[100001], cnt[100001], mn[100001], mx[100001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
	}

	for (int i = 1; i <= n; i++)
		d[i] = 1e18;
	d[1] = 0; cnt[1] = 1;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 1));
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				cnt[v] = cnt[u];
				mn[v] = mn[u] + 1; mx[v] = mx[u] + 1;
				pq.push(ii(d[v], v));
			}
			else if (d[v] == d[u] + w) {
				(cnt[v] += cnt[u]) %= mod;
				mn[v] = min(mn[v], mn[u] + 1); mx[v] = max(mx[v], mx[u] + 1);
			}
		}
	}
	cout << d[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n];
}