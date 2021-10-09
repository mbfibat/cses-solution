#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[200001];

bool check(int x) {
	int s = 0, cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > x) return false;
		s += a[i];
		if (s > x) {
			cnt++;
			s = a[i];
		}
	}
	return (cnt <= k);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int l = 1, r = 1e18, ans = -1;
	while (l <= r) {
		int mi = (l + r) / 2;
		if (check(mi)) {
			ans = mi;
			r = mi - 1;
		}
		else
			l = mi + 1;
	}
	cout << ans;
}