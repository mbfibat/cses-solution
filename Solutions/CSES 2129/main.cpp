#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m, k;
vector<int> adj[1001];

int d[1011], pre[1011];
int f[1011][1011], c[1011][1011], w[1011][1011];
void aug_path() {
	for (int i = 1; i <= 2 * n + 1; i++) {
		d[i] = 1e9;
		pre[i] = -1;
	}		
	d[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 0));
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;
		for (int v : adj[u]) {
			if (f[u][v] < c[u][v] && d[v] > d[u] + w[u][v]) {
				d[v] = d[u] + w[u][v];
				pre[v] = u;
				pq.push(ii(d[v], v));
			}
		}
	}
}

void update() {
	int cur = 2 * n + 1;
	while (cur != 0) {
		f[pre[cur]][cur]++;
		f[cur][pre[cur]]--;
		cur = pre[cur];
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> w[i][n + j];
			adj[i].push_back(n + j);
			adj[n + j].push_back(i);
			c[i][n + j] = 1;
			w[n + j][i] = -w[i][n + j];
		}
	for (int i = 1; i <= n; i++) {
		c[0][i] = 1; adj[0].push_back(i);
		c[n + i][2 * n + 1] = 1; adj[n + i].push_back(2 * n + 1);
	}	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		aug_path();
		ans += d[2 * n + 1];
		update();
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][n + j])
				cout << i << ' ' << j << '\n';
}