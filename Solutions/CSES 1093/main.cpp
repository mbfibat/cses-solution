#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n;

int f[2][500001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	f[0][250000] = 1;

	for (int i = 1; i <= n; i++) {
		int l = 250000 - i * (i + 1) / 2;
		int r = 250000 + i * (i + 1) / 2;
		for (int j = l; j <= r; j++) f[i & 1][j] = 0;
		for (int j = l; j <+ r; j++) {
			if (j - i >= l) (f[i & 1][j] += f[(i - 1) & 1][j - i]) %= mod;
			if (j + i <= r) (f[i & 1][j] += f[(i - 1) & 1][j + i]) %= mod;
		}
	}
	cout << f[n & 1][250000];
}