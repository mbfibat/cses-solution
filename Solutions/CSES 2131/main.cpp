#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, s, t;
int a[51], b[51];
vector<ii> adj[1001];

int ans = 0;
int d[1001], pre[1001], f[1001][1001], c[1001][1001];

bool aug_path() {
	for (int i = 0; i <= t; i++) d[i] = 1e9;

	priority_queue<ii, vector<ii>, greater<ii>>	pq;
	pq.emplace(0, s); d[s] = 0;
	
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;
		for (auto& [v, w] : adj[u])
			if (d[v] > du + w && f[u][v] < c[u][v]) {
				d[v] = du + w;
				pre[v] = u;
				pq.emplace(d[v], v);
			}
	}
	if (d[t] != 1e9) ans -= d[t];
	return d[t] != 1e9;
}

int mx_flow = 0;
void update() {
	int cur = t;
	while (cur != s) {
		f[pre[cur]][cur]++;
		f[cur][pre[cur]]--;
		cur = pre[cur];
	}
	mx_flow++;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n; s = 0, t = 2 * n + 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[s][i] = a[i];
		adj[s].emplace_back(i, 0);
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		c[n + i][t] = b[i];
		adj[n + i].emplace_back(t, 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int w; cin >> w;
			c[i][n + j] = 1;
			adj[i].emplace_back(n + j, -w);
			adj[n + j].emplace_back(i, w);
		}

	while (aug_path())
		update();

	int sa = accumulate(a + 1, a + 1 + n, 0);
	int sb = accumulate(b + 1, b + 1 + n, 0);
	if (sa != sb) {
		cout << -1;
		return 0;
	}
 
	if (mx_flow != sa) {
		cout << -1;
		return 0;
	}

	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (f[i][n + j] ? 'X' : '.');
		cout << '\n';
	}	
}