#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001], re_adj[100001];

vector<int> vi;
bool vis[100001];

void dfs(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
	vi.push_back(u);
}

void dfs2(int u) {
	vis[u] = true;
	for (int v : re_adj[u])
		if (!vis[v])
			dfs2(v);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		re_adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
	reverse(vi.begin(), vi.end());

	memset(vis, false, sizeof vis);
	for (int v : vi) {
		if (vis[v]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		dfs2(v);
	}

	for (int v : vi)
		cout << v << ' ';
}