#include <bits/stdc++.h>

using namespace std;

int n, m;
bool vis[100001];
vector<int> adj[100001], re_adj[100001];

stack<int> S;

void dfs1(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs1(v);
	S.push(u);						
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
			dfs1(i);
	memset(vis, false, sizeof vis);

	int s = S.top();
	dfs2(s);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			cout << "NO\n";
			cout << i << ' ' << s << '\n';
			return 0;
		}
	cout << "YES";			
}
