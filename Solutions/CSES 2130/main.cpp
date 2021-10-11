#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct Edge {
	int u, v, c, f = 0;
	Edge(){}
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c){}
};

vector<Edge> E;
int n, m, k;
vector<int> adj[511];

int d[511], p[511];
bool aug_path() {
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
		p[i] = -1;
	}		
	d[1] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 1));
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;
		for (int id : adj[u]) {
			int v = E[id].v, c = E[id].c, f = E[id].f;
			int w = (E[id].c ? 1 : -1);
			if (f < c && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = id;
				pq.push(ii(d[v], v));
			}
		}
	}
	return (p[n] != -1);
}

void update() {
	int id = p[n];
	while (id != -1) {
		E[id].f++;
		E[id ^ 1].f--;
		id = p[E[id].u];
	} 
}

void trace() {
	for (int id : adj[1]) {
		if (E[id].f > 0) {
			E[id].f = 0;
			vector<int> cur = {1};
			while (true) {
				cur.push_back(E[id].v);
				if (E[id].v == n) break;
				for (int nxt_id : adj[E[id].v])
					if (E[nxt_id].f > 0) {
						E[nxt_id].f = 0;
						id = nxt_id;
						break;
					}
			}	
			cout << cur.size() << '\n';
			for (int v : cur)
				cout << v << ' ';
			cout << '\n';
		}
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		E.push_back(Edge(u, v, 1));
		adj[u].push_back(int(E.size()) - 1);
		E.push_back(Edge(v, u, 0));
		adj[v].push_back(int(E.size()) - 1);
	}
	
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (!aug_path())
			return cout << -1, 0;
		ans += d[n];
		update();
	}
	cout << ans << '\n';
	trace();
}