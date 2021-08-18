#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];
vector<int> adj[200001];

int nChild[200001];

void dfs(int u, int p) {
	nChild[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		nChild[u] += nChild[v];
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[i].push_back(p);		
		adj[p].push_back(i);		
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		cout << nChild[i] - 1 << ' ';
}