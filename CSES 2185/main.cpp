#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll n, k;
ll a[21];
 
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
 
	ll ans = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
		ll cur = 1;
		for (int i = 0; i < k; i++)
			if (mask >> i & 1) {
				ll nxt = cur * a[i + 1];
				if (nxt / a[i + 1] != cur) {
					cur = 0;
					break;
				}
				else cur = nxt;	
			}
		if (cur) {
			if (__builtin_popcount(mask) % 2) ans += n / cur;
			else ans -= n / cur;
		}
	}
	cout << ans;
}	