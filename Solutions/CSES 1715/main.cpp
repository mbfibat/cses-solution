#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int p(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b/2);
	if (b%2 == 0) return (tmp * tmp)%mod;
	return ((tmp * tmp)%mod * a)%mod;
}

int fact[2000001], re_fact[2000001];

int comb(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	int tmp = fact[n] * re_fact[k] % mod * re_fact[n - k] % mod;
	return tmp; 
}

string s;
int cnt[26];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 2000000; i++)
		fact[i] = fact[i - 1] * i % mod;
	re_fact[2000000] = p(fact[2000000], mod - 2);
	for (int i = 2000000; i >= 1; i--)
		re_fact[i - 1] = re_fact[i] * i % mod;
	cin >> s;
	for (char c : s)
		cnt[c - 'a']++;
	int ans = fact[s.size()];
	for (int i = 0; i < 26; i++)
		ans = ans * re_fact[cnt[i]] % mod;
	cout << ans;
}