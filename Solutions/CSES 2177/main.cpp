#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int n, m;
set<int> adj[100001];

int top = 0;
int low[100001], num[100001];
vector<ii> ans;

void dfs(int u, int p) {
	num[u] = low[u] = ++top;
	while (!adj[u].empty()) {
		int v = *adj[u].begin();
		adj[u].erase(v);
		adj[v].erase(u);
		ans.push_back(ii(u, v));
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) {
				cout << "IMPOSSIBLE";
				exit(0);
			}	
		}
		else if (v != p)
			low[u] = min(low[u], num[v]);
	}
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		if (!num[i]) {
			cout << "IMPOSSIBLE";
			return 0;
		}	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}