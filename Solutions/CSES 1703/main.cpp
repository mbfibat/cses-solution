#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];

int p[100001];
bool vis[100001];

void dfs1(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v]) {
			dfs1(v);
			p[v] = u;
		}
}

int id[100001], val[100001];
bool on_path[100001];

void dfs2(int u) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (!on_path[v] && !vis[v])
			dfs2(v);
		val[u] = max(val[u], val[v]);
	}
}        
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	dfs1(1);

	vector<int> path;
	int cur = n;
	while (cur) {
		path.push_back(cur);
		on_path[cur] = true;
		cur = p[cur];
	}

	reverse(path.begin(), path.end());

	for (int i = 0; i < path.size(); i++) {
		val[path[i]] = i + 1;
		id[path[i]] = i;
	}

	memset(vis, false, sizeof vis);	

	for (int u : path)
		dfs2(u);

	int mx = 0;
	vector<int> ans;
	for (int i = 0; i < path.size() - 2; i++) {
		mx = max(mx, val[path[i]]);
		if (mx <= i + 2) 
			ans.push_back(path[i + 1]);
	}
	ans.push_back(1); ans.push_back(n);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int x : ans)
		cout << x << ' ';
}