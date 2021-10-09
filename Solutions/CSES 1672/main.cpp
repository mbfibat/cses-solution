#include <bits/stdc++.h>

using namespace std;

int n, m, q;

long long f[501][501];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = 1e18;

	for (int i = 1; i <= n; i++) f[i][i] = 0;

	for (int i = 1; i <= m; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		f[u][v] = min(f[u][v], w);
		f[v][u] = min(f[v][u], w);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	while (q--) {
		int u, v; cin >> u >> v;
		long long ans = (f[u][v] != 1e18 ? f[u][v] : -1);
		cout << ans << '\n';
	}	            
}