#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct Edges {
	int u, v, c, w, f = 0;
	Edges(){}
	Edges(int _u, int _v, int _c, int _w) : u(_u), v(_v), c(_c), w(_w) {}
};
vector<Edges> E;

int n, m, k;
vector<int> adj[501];

int d[501], pre[501];
bool aug_path() {
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
		pre[i] = -1;
	}		
	d[1] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 1));
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;
		for (int id : adj[u]) {
			int v = E[id].v, c = E[id].c, w = E[id].w;
			if (E[id].f < c && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pre[v] = id;
				pq.push(ii(d[v], v));
			}
		}
	}
	if (pre[n] == -1) return false;
	return true;			
}

void update() {
	int cur = n;
	while (cur != 1) {
		E[pre[cur]].f++;
		E[pre[cur] ^ 1].f--;
		cur = E[pre[cur]].u;
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	while (m--) {
		int u, v, c, w; cin >> u >> v >> c >> w;
		E.push_back(Edges(u, v, c, w));
		adj[u].push_back((int)E.size() - 1);
		E.push_back(Edges(v, u, 0, -w));
		adj[v].push_back((int)E.size() - 1);
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (!aug_path())
			return cout << -1, 0;
		ans += d[n];
		update();
	}
	cout << ans;
}