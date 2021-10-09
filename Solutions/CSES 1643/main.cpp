#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int pSum = 0, mn = 0, ans = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pSum += a[i];
		ans = max(ans, pSum - mn);
		mn = min(mn, pSum);
	}
	cout << ans;
}