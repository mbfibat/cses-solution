#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];

int vis[100001];

vector<int> cur;

void dfs(int u, int p) {
	cur.push_back(u);
	vis[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		if (!vis[v]) {
			dfs(v, u);
		}
		else if (vis[v] == 1) {
			vector<int> ans;
			ans.push_back(v);
			while (cur.back() != v) {
				ans.push_back(cur.back());
				cur.pop_back();				
			}
			ans.push_back(v);
			cout << ans.size() << '\n';
			for (int v : ans)
				cout << v << ' ';
			exit(0);
		}
	}
	cur.pop_back();
	vis[u] = 2;
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

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, -1);
	cout << "IMPOSSIBLE";
}