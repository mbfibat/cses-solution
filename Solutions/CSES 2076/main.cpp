#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<int> adj[100001];

vector<ii> bridges;

int top = 0;
int num[100001], low[100001];
void dfs(int u, int p) {
	num[u] = low[u] = ++top;
	for (int v : adj[u]) {
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) bridges.push_back(ii(u, v));
		}
		else if (v != p)
			low[u] = min(low[u], num[v]);
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, - 1);
	cout << bridges.size() << '\n';
	for (ii p : bridges)
		cout << p.first << ' ' << p.second << '\n';
		
}