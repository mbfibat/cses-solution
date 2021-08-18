#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;

int cnt(int x) {
	int ans = 0, sq = sqrt(x);
	for (int i = 1; i <= sq; i++) {	
		int j = x / i;
		j = min(j, n);
		ans += j;
		ans += max(0LL, j - sq);

	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int l = 1, r = n * n, ans = -1;
	while (l <= r) {
		int mi = (l + r) / 2;
		if (cnt(mi) >= (n * n + 1) / 2) {
			ans = mi;
			r = mi - 1;
		}
		else
			l = mi + 1;
	}
	cout << ans;
}