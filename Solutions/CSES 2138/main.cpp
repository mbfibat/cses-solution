#pragma GCC target("popcnt")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[50001];

bool g[50001];
bitset<50001> f[50001];

bitset<50001> dp(int u) {
	if (g[u])
		return f[u];
	f[u].set(u, 1);
	for (int v : adj[u])
		f[u] |= dp(v);
	g[u] = 1;
	return f[u];
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
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		cout << dp(i).count() << ' ';
}