#include <bits/stdc++.h>

using namespace std;

#define int long long

const int p = 31;
const int mod = 1e9 + 8181;

int pow_p[1000001];

string s;
int h[1000001];

int cal_h(int l, int r)
{
	return ((h[r] - h[l - 1] * pow_p[r - l + 1])%mod + mod)%mod;
}


int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pow_p[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		pow_p[i] = (pow_p[i - 1] * p) % mod;

	cin >> s;
	s = '*' + s;
	int n = s.size() - 1;
	for (int i = 1; i <= n; i++)
		h[i] = (h[i - 1] * p + (s[i] - 'a' + 1))%mod;	
	for (int len = 1; len <= n; len++)
	{
		bool ok = true;
		for (int i = 1; i <= n; i += len)
		{
			int j = min(n, i + len - 1);
			int l = j - i + 1;
			if (cal_h(1, l) != cal_h(i, j))
			{
				ok = false;
				break;
			}
		}
		if (ok) cout << len << ' ';
	}
}