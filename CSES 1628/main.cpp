#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x;
int a[40];
map<ll, int> cnt;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	int sz_l = n / 2, sz_r = n - sz_l;
	for (int mask = 0; mask < (1 << sz_l); mask++)
	{
		ll cur = 0;
		for (int i = 0; i < sz_l; i++)
			if (mask >> i & 1)
				cur += a[i];
		if (cur > x) continue;
		cnt[cur]++;
	}
	ll ans = 0;
	for (int mask = 0; mask < (1 << sz_r); mask++)
	{
		ll cur = 0;
		for (int i = 0; i < sz_r; i++)
			if (mask >> i & 1)
				cur += a[sz_l + i];
		if (cur > x) continue;
		if (cnt.count(x - cur))
			ans += cnt[x - cur];	
	}
	cout << ans;
}