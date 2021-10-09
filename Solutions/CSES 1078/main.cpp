#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

int fact[3000001], re_fact[3000001];

int p(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b / 2);
	if (b % 2 == 0)
		return (tmp * tmp)%mod;
	return ((tmp * tmp)%mod * a)%mod;	
}

int comb(int n, int k)
{
	if (k < 0 || n < 0 || k > n)
		return 0;
	return ((fact[n] * re_fact[k])%mod * re_fact[n - k])%mod;
}

ii a[1001];

int n, m;
int f[1001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 3000000; i++)
		fact[i] = (fact[i - 1] * i)%mod;
	re_fact[3000000] = p(fact[3000000], mod - 2);
	for (int i = 3000000; i >= 1; i--)
		re_fact[i - 1] = (re_fact[i] * i)%mod;

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].first >> a[i].second;
	sort (a + 1, a + 1 + m);
	for (int i = 1; i <= m; i++)
	{
		int cur = comb(a[i].first + a[i].second - 2, a[i].first - 1);
		for (int j = 1; j <= m; j++)
			if (a[j].first <= a[i].first && a[j].second <= a[i].second)
				cur = ((cur - (f[j] * comb(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first))%mod)%mod + mod)%mod;
		f[i] = cur;							
	}
	int cur = comb(2 * n - 2, n - 1);
	for (int i = 1; i <= m; i++)
		cur = ((cur - (f[i] * comb(n - a[i].first + n - a[i].second, n - a[i].first))%mod)%mod + mod)%mod;
	cout << cur;
}