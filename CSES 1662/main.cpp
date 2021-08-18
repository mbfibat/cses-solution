#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[200001], cnt[200001];


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int s = 0, ans = 0; cnt[0]++;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; s += a[i];
		ans += cnt[(s % n + n) % n];
		cnt[(s % n + n) % n]++;
	}
	cout << ans;
}