#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, q;
 
int d[100001];
int lca[100001][21];
vector<int> adj[100001];
 
int dp[100001]; // numbers of back_edge pass over u - parent of u
 
int cal_lca(int u, int v) { // LCA in DFS - tree
	if (d[u] > d[v]) swap(u, v);
	for (int j = 20; j >= 0; j--)
		if (d[lca[v][j]] >= d[u])
			v = lca[v][j];
	if (u == v) return u;
	for (int j = 20; j >= 0; j--)
		if (lca[v][j] != lca[u][j]) {
			u = lca[u][j];
			v = lca[v][j];
		}	
	return lca[u][0];
}
 
bool is_anc(int u, int v) { // check if u is anc of v
	return cal_lca(u, v) == u;
}
 
int dist(int u, int v) {
	int l = cal_lca(u, v);
	return d[u] + d[v] - 2 * d[l];
}
 
int jump(int u, int k) {
	for (int j = 20; j >= 0; j--)
		if (k >> j & 1)
			u = lca[u][j];
	return u;
}

void dfs(int u, int p) {
	for (int j = 1; j <= 20; j++)
		lca[u][j] = lca[lca[u][j - 1]][j - 1];
 
	for (int v : adj[u]) {
		if (v == p) continue;
				
		if (!d[v]) { // u - v (tree_edge)
			lca[v][0] = u;
			d[v] = d[u] + 1;
			dfs(v, u);
 
			dp[u] += dp[v];
		}
		else if (d[v] < d[u]) { // u - ancestor
			int k = jump(u, dist(u, v) - 1);
			dp[k]--;
			dp[u]++;
		} 
	}             

}
  
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	d[1] = 1;
	dfs(1, 0);
 
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		if (dist(a, c) + dist(c, b) != dist(a, b)) // c is not on path from a to b on DFS tree
			cout << "YES\n";
		else {
			bool ok1 = false, ok2 = false;
			if (!is_anc(c, a)) ok1 = true;
			else { 
				int k1 = jump(a, dist(a, c) - 1);
				ok1 = dp[k1];
			}	
			if (!is_anc(c, b)) ok2 = true;
			else {
				int k2 = jump(b, dist(b, c) - 1);
				ok2 = dp[k2];
			}                       
			if (ok1 && ok2) cout << "YES\n";
			else cout << "NO\n";
		}	
	}
}