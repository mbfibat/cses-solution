#pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> adj[50001], re_adj[50001];

stack<int> S;
bool vis[50001];
void dfs(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
	S.push(u);
}

int top = 0;
int r[50001];
vector<int> newAdj[50001];
void dfs2(int u) {
	r[u] = top;
	for (int v : re_adj[u]) {
		if (!r[v])
			dfs2(v);		
		else if (r[v] != r[u])
			newAdj[r[v]].push_back(r[u]);
	}	
}

bool g[50001];
bitset<50001> f[50001];
 
bitset<50001> dp(int u) {
	if (g[u])
		return f[u];
	f[u].set(u, 1);
	for (int v : newAdj[u])
		f[u] |= dp(v);
	g[u] = 1;
	return f[u];
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		re_adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
	while (!S.empty()) {
		int u = S.top(); S.pop();
		if (!r[u]) {
			top++;
			dfs2(u);
		}
	}

	for (int i = 1; i <= top; i++) 
		if (!g[i])
			dp(i);
	while (q--) {
		int u, v; cin >> u >> v;
		if (f[r[u]][r[v]]) cout << "YES\n";
		else cout << "NO\n";		
	}
}