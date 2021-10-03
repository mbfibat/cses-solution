#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[3001];
int c[3001][3001];
int f[3001][3001], opt[3001][3001];

int cost(int l, int r) {
	if (l == 1)
		return c[r][r];
	int mi = (r + l - 1) / 2;
	int lhs = c[l - 1][mi] - c[l - 1][l - 1]; 
	int rhs = c[r][r] - c[r][mi];
	return lhs + rhs;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = c[i][j - 1] + a[j] * abs(i - j);
	for (int i = 1; i <= n; i++) {
		f[1][i] = c[i][i];
		opt[1][i] = 1;
	}
	cerr << cost(3, 5);

	for (int i = 2; i <= k; i++)
		for (int j = n; j >= 1; j--) {
			int l = opt[i - 1][j];
			int r = (j == n) ? n : opt[i][j + 1];
			f[i][j] = 1e18;
			for (int m = l; m <= r; m++)
				if (f[i][j] > f[i - 1][m - 1] + cost(m, j)) {   
					f[i][j] = f[i - 1][m - 1] + cost(m, j);
					opt[i][j] = m;
				}
		}
	int ans = 1e18;
	for (int i = n; i >= k; i--) 
		ans = min(ans, f[k][i] + c[i][n] - c[i][i]);
	cout << ans;
}