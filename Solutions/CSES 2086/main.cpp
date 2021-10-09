#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[3001];
int c[3001][3001];
int f[3001][3001], opt[3001][3001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int l = 1; l <= n; l++) {
		int cur = 0;
		for (int r = l; r <= n; r++) {
			cur += a[r];
			c[l][r] = cur * cur;
		}
	}		
	for (int i = 1; i <= n; i++) {
		f[1][i] = c[1][i];
		opt[1][i] = 1;
	}
	for (int i = 2; i <= k; i++) {
		for (int j = n; j >= 1; j--) {
			int l = opt[i - 1][j];
			int r = (j == n) ? n : opt[i][j + 1];
			f[i][j] = 1e18;
			for (int m = l; m <= r; m++) {
				if (f[i][j] > f[i - 1][m - 1] + c[m][j]) {
					f[i][j] = f[i - 1][m - 1] + c[m][j];
					opt[i][j] = m;
				}
			}
		}
	}		
	cout << f[k][n];
}