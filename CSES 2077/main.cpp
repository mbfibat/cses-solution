#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<int> adj[100001];

vector<int> ans;

int top = 0, r = 0;
int num[100001], low[100001];
void dfs(int u, int p) {
	num[u] = low[u] = ++top;
	for (int v : adj[u]) {
		if (!num[v]) {
			if (u == 1) r++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (u != 1 && low[v] >= num[u]) ans.push_back(u);
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

	dfs(1, -1);
	if (r >= 2) ans.push_back(1);
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << ans.size() << '\n';
	for (int v : ans)
		cout << v << ' ';
		
}