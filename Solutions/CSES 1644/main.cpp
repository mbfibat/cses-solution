#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, l, r;
int a[200001], psum[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	int ans = -1e18;
	multiset<int> ms;
	for (int i = 1; i <= n; i++) {
		if (i > r) ms.erase(ms.find(psum[i - r - 1]));
		if (i >= l) {
			ms.insert(psum[i - l]);
			ans = max(ans, psum[i] - (*ms.begin()));
		}	
	}
	cout << ans;
}