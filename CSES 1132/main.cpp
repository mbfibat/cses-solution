#include <bits/stdc++.h>

using namespace std;

int n;
int a, b;
vector<int> adj[200001];

int mxd[200001], fd[200001], smxd[200001], mxu[200001];

void dfs1(int u, int p) {
	int mx_1 = 0, mx_2 = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs1(v, u);
		if (mxd[v] + 1 > mxd[u]) {
			fd[u] = v;
			smxd[u] = mxd[u];
			mxd[u] = mxd[v] + 1;
		}
		else if (mxd[v] + 1 > smxd[u])
			smxd[u] = mxd[v] + 1;
	}
}

void dfs2(int u, int p) {
	if (p != -1) {
		mxu[u] = mxu[p] + 1;
		if (fd[p] == u) mxu[u] = max(mxu[u], smxd[p] + 1);
		else mxu[u] = max(mxu[u], mxd[p] + 1);
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs2(v, u);
	}
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

	dfs1(1, -1);
	dfs2(1, -1);

	for (int i = 1; i <= n; i++) cout << max(mxu[i], mxd[i]) << ' ';
}