#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n, x;
int a[200001];
 
map<int, int> cnt;
 
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> x;
 
	cnt[0]++;
	int s = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		if (cnt.count(s - x))
			ans += cnt[s - x];
		cnt[s]++;
	}
	cout << ans;
}