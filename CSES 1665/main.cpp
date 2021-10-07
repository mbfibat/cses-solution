#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n, x;
int a[101];
int f[2][101][5001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + 1 + n);

	f[0][0][0] = 1;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 5000; k++)
				f[(i + 1) & 1][j][k] = 0;
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 5000; k++) {
				int nxt = k + j * (a[i + 1] - a[i]);
				int val = f[i & 1][j][k];

				// Do nothing
				if (j > 0)
					(f[(i + 1) & 1][j][nxt] += 1LL * j * val % mod) %= mod;
				// Open one
				if (j < 100)
					(f[(i + 1) & 1][j + 1][nxt] += val) %= mod;
				// Close one
				if (j > 0)
					(f[(i + 1) & 1][j - 1][nxt] += 1LL * j * val % mod) %= mod;
				// Open and close one
				(f[(i + 1) & 1][j][nxt] += val) %= mod;
			}
	}
	int ans = 0;
	for (int i = 0; i <= x; i++)
		(ans += f[n & 1][0][i]) %= mod;
	cout << ans;
}