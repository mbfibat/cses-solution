#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n;

// http://oeis.org/A060281
// http://oeis.org/A008275

int pn[5001];
int s[5001][5001];
int comb[5001][5001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	s[0][0] = 1;
	for (int i = 1; i <= 5000; i++)
		for (int j = 1; j <= 5000; j++)
			s[i][j] = ((s[i - 1][j - 1] - (i - 1) * s[i - 1][j] % mod) % mod + mod) % mod;

	for (int i = 0; i <= 5000; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) comb[i][j] = 1;
			else comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		}

	cin >> n;
	pn[0] = 1;
	for (int i = 1; i <= n; i++)
		pn[i] = pn[i - 1] * n % mod;
	for (int k = 1; k <= n; k++) {
		int ans = 0;
		for (int j = 0; j <= n - 1; j++) {
			int cur = comb[n - 1][j] * pn[n - 1 - j] % mod * s[j + 1][k] % mod;
			if ((k + j + 1) % 2) cur = (-cur + mod) % mod; 
			(ans += cur) %= mod;
		}
		cout << ans << '\n';
	}
}