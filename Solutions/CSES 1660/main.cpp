#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
int a[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;

	int s = 0, ans = 0;
	int l = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		while (l <= i && s > x) {
			s -= a[l];
			l++;
		}
		if (s == x) ans++;
	}
	cout << ans;
}