#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];

int vis[100001];

vector<int> cur;
void dfs(int u) {
	vis[u] = 1; cur.push_back(u);
	for (int v : adj[u]) {
		if (vis[v] == 1) {
			vector<int> ans;
			while (cur.back() != v) {
				ans.push_back(cur.back());
				cur.pop_back();
			}
			reverse(ans.begin(), ans.end());
			cout << 2 + (int) ans.size() << '\n';
			cout << v << ' ';
			for (int val : ans) cout << val << ' ';
			cout << v << ' ';
			exit(0);
		}
		else if (!vis[v])
			dfs(v);
	}
	vis[u] = 2;
	cur.pop_back();
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	cout << "IMPOSSIBLE";
}