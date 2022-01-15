#include <bits/stdc++.h>

using namespace std;

int t, n;
int deg[2][100001];
vector<int> adj[2][100001];

map<vector<int>, int> mp;

vector<int> find_c(int k) {
	vector<int> leaf;
	for (int u = 1; u <= n; u++)
		if (deg[k][u] == 1) 
			leaf.push_back(u);
	while (leaf.size() > 2) {
		vector<int> nxt_leaf;
		for (int u : leaf)
			for (int v : adj[k][u]) {
				deg[k][v]--;
				if (deg[k][v] == 1)
					nxt_leaf.push_back(v);
			}
		leaf.swap(nxt_leaf);
	}
	return leaf;
}

int id(vector<int>& vi) {
	if (!mp.count(vi)) mp[vi] = mp.size() + 1;
	return mp[vi];
}

int dfs(int u, int p, int k) {
	vector<int> vi;
	for (int v : adj[k][u]) {
		if (v == p) continue;
		vi.push_back(dfs(v, u, k));
	}
	sort(vi.begin(), vi.end());
	return id(vi);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		mp.clear();
		cin >> n;
		for (int k = 0; k < 2; k++) {
			for (int i = 1; i <= n; i++) {
				adj[k][i].clear();
				deg[k][i] = 0;
			}	
			for (int i = 1; i <= n - 1; i++) {
				int u, v; cin >> u >> v;
				adj[k][u].push_back(v);
				adj[k][v].push_back(u);
				deg[k][u]++; deg[k][v]++;
			}
		}	

		vector<int> c0 = find_c(0), c1 = find_c(1);

		bool ok = false;
		for (int s0 : c0) 
			for (int s1 : c1) {
				int h0 = dfs(s0, 0, 0);				
				int h1 = dfs(s1, 0, 1);
				if (h0 == h1) {
					ok = true;
					break;
				}
			}

		cout << (ok ? "YES" : "NO") << '\n';
	}
}