#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int p(int a, int b) {
	if (b == 0)
		return 1;
	int tmp = p(a, b/2);
	if (b % 2 == 0) return tmp * tmp % mod;
	return tmp * tmp % mod * a % mod;
}

int inv(int x) {
	return p(x, mod - 2);
}

int n;
int cnt[1000001];
int pre[1000011], suf[1000011];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, k; cin >> x >> k;
		cnt[x] += k;
	}

	pre[0] = 1; suf[1000001] = 1;
	for (int i = 1; i <= 1000000; i++) pre[i] = (pre[i - 1] * (cnt[i] + 1)) % (mod - 1);
	for (int i = 1000000; i >= 1; i--) suf[i] = (suf[i + 1] * (cnt[i] + 1)) % (mod - 1);

	int cnt_div = 1, sum_div = 1, prod_div = 1;
	for (int i = 1; i <= 1000000; i++) if (cnt[i]) {
		cnt_div = cnt_div * (cnt[i] + 1) % mod;

		int cur_sum = ((p(i, cnt[i] + 1) - 1) * inv(i - 1) % mod + mod) % mod;
		sum_div = sum_div * cur_sum % mod;

		int lul = (cnt[i] * (cnt[i] + 1) / 2) % (mod - 1);
		int cur_prod = p(p(i, lul), pre[i - 1] * suf[i + 1] % (mod - 1));
		prod_div = prod_div * cur_prod % mod;
	}
	cout << cnt_div << ' ' << sum_div << ' ' << prod_div << '\n';
}