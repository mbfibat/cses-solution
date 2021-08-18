#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int p(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b/2);
	if (b % 2 == 0) return tmp * tmp % mod;
	return tmp * tmp % mod * a % mod;
}

int n;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int ans = p(2, n * n);
	if (n % 2 == 0)
	{
		ans += 2 * p(2, n * n / 4);
		ans += p(2, n * n / 2);
	}
	else	
	{
		ans += 2 * p(2, n * n / 4 + 1);	
		ans += p(2, n * n / 2 + 1);
	}
	ans %= mod;
	ans = ans * p(4, mod - 2) % mod;
	cout << ans;	
}