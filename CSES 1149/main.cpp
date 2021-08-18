#include <bits/stdc++.h>

using namespace std;

#define int long long

string s;
int f[500001];
int pre[26];
const int mod = 1e9 + 7;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s; int n = s.size();
	s = '*' + s;
	for (int i = 0; i < 26; i++)
		pre[i] = -1;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (2 * f[i - 1])%mod;
		if (pre[s[i] - 'a'] != -1)
			f[i] = ((f[i] - f[pre[s[i] - 'a'] - 1])%mod + mod)%mod;
		pre[s[i] - 'a'] = i;
	}                       
	cout << (f[n] - 1 + mod)%mod;
}