#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> adj[2][100001];

map<vector<int>, int> mp;

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
			for (int i = 1; i <= n; i++) adj[k][i].clear();
			for (int i = 1; i <= n - 1; i++) {
				int u, v; cin >> u >> v;
				adj[k][u].push_back(v);
				adj[k][v].push_back(u);
			}
		}	

		int h0 = dfs(1, 0, 0);				
		int h1 = dfs(1, 0, 1);

		cout << ((h0 == h1) ? "YES" : "NO") << '\n';
	}
}