#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int t, n;

int f[2][1000001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	f[0][1] = f[1][1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		f[0][i] = (f[0][i - 1] * 4 + f[1][i - 1]) % mod;
		f[1][i] = (f[0][i - 1] + 2 * f[1][i - 1]) % mod;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << (f[0][n] + f[1][n]) % mod << '\n';
	}
}