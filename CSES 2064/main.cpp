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
int fact[2000001], re_fact[2000001];

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
	if (n % 2) return !(cout << 0);
	else cout << fact[n] * re_fact[n / 2] % mod * re_fact[n / 2 + 1] % mod; 
}