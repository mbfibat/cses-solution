#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, t;
int a[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int l = 1, r = 1e18, ans = -1;
	while (l <= r) {
		int mi = (l + r) / 2, cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += mi / a[i];
			if (cnt < 0) {
				cnt = t; 
				break;
			}	
		}
		if (cnt >= t) {
			ans = mi;
			r = mi - 1;
		}
		else
			l = mi + 1;
	}
	cout << ans;
}