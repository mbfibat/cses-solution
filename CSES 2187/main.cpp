#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int qp(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = qp(a, b/2);
	if (b % 2 == 0) return tmp * tmp % mod;
	return tmp * tmp % mod * a % mod;
}

int n;
string s;
int fact[2000001], re_fact[2000001];

int comb(int n, int k)
{
	if (k > n || k < 0 || n < 0) return 0;
	return fact[n] * re_fact[k] % mod * re_fact[n - k] % mod;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 2000000; i++)
		fact[i] = fact[i - 1] * i % mod;
	re_fact[2000000] = qp(fact[2000000], mod - 2);
	for (int i = 2000000; i >= 1; i--)
		re_fact[i - 1] = re_fact[i] * i % mod;
	
	cin >> n;       
	cin >> s;
	if (n % 2) return !(cout << 0);
	else
	{
		int cnt_st = n / 2;
		int cur = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') 
			{
				cnt_st--;
				cur++;
			}
			else cur--;
			if (cur < 0)
				return !(cout << 0);
		}
		cout << ((comb(n - (int)s.size(), cnt_st) - comb(n - (int)s.size(), cnt_st + cur + 1))%mod + mod)%mod;
	}
}