#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int fact[1000001], re_fact[1000001];

int qp(int a, int b) {
	if (b == 0) return 1;
	int tmp = qp(a, b / 2);
	if (b % 2) return tmp * tmp % mod * a % mod;
	return tmp * tmp % mod;
}

int comb(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return fact[n] * re_fact[k] % mod * re_fact[n - k] % mod;
}

int n, k;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 1000000; i++) fact[i] = fact[i - 1] * i % mod;
	re_fact[1000000] = qp(fact[1000000], mod - 2);
	for (int i = 1000000; i >= 1; i--) re_fact[i - 1] = re_fact[i] * i % mod;

	int ans = 0;
	cin >> n >> k;
	for (int i = k; i >= 1; i--) {
		int tmp = (comb(k, i) * qp(i, n)) % mod;
		if ((k - i) % 2) tmp = (-tmp + mod) % mod;
		(ans += tmp) %= mod;		
	}
	cout << ans;
}