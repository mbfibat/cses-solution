#include <bits/stdc++.h>

using namespace std;

int n;
int a, b;
vector<int> adj[200001];

int ans = 0;
int mx_dist[200001];

void dfs(int u, int p) {
	int mx_1 = 0, mx_2 = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		if (mx_dist[v] + 1 >= mx_1) {
			mx_2 = mx_1;
			mx_1 = mx_dist[v] + 1;
		}	
		else if (mx_dist[v] + 1 > mx_2)
			mx_2 = mx_dist[v] + 1;
	}
	ans = max(ans, mx_1 + mx_2); 
	mx_dist[u] = mx_1;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);

	cout << ans;
}