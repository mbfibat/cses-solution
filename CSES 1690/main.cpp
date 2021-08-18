#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, m;
int adj[20][20];
long long f[1 << 20][20];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u][v]++;
	}
	f[1][0] = 1;
	for (int mask = 1; mask < (1 << n); mask++)
		for (int i = 0; i < n; i++)
			if (mask >> i & 1)
				for (int j = 0; j < n; j++)
					if (!(mask >> j & 1))
						(f[mask | (1 << j)][j] += f[mask][i] * adj[i][j]) %= mod;
	cout << f[(1 << n) - 1][n - 1];
}