#include <bits/stdc++.h>

using namespace std;

int n, m;
int vis[100001], state[100001];
vector<int> adj[100001];

vector<pair<int, int>> ans;

int top = 0;

void dfs(int u, int p) {
	vis[u] = ++top;

	for (int v : adj[u]) {
		if (v == p) continue;

		if (!vis[v])
			dfs(v, u);
		else if (vis[v] < vis[u]) {
			state[v] ^= 1;
			ans.push_back(pair<int, int>(v, u));
		}
	}

	if (p != -1) {
		if (state[u]) {
			ans.push_back(pair<int, int>(u, p));
			state[u] ^= 1;
		}	
		else {
			ans.push_back(pair<int, int>(p, u));
			state[p] ^= 1;
		}	
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, -1);

	if (accumulate(state + 1, state + 1 + n, 0)) return cout << "IMPOSSIBLE", 0;
	for (pair<int, int> pi : ans)
		cout << pi.first << ' ' << pi.second << '\n';
}