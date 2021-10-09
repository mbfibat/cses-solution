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
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort (a + 1, a + 1 + n);

	int sum = accumulate(a + 1, a + n, 0LL);
	if (sum >= a[n]) cout << sum + a[n];
	else cout << 2 * a[n]; 
}