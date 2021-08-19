#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int n;
ii a[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	sort (a + 1, a + 1 + n);

	int cur = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i].first;
		ans += a[i].second - cur;
	}
	cout << ans;
}