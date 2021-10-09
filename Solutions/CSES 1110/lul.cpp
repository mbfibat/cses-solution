#include <bits/stdc++.h>

using namespace std;

#define int long long

const int p = 31;
const int mod = 1e9 + 8181;

int pow_p[1000001];

string s;
int h[2000001];

int cal_h(int l, int r)
{
	return ((h[r] - h[l - 1] * pow_p[r - l + 1])%mod + mod)%mod;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s; int n = s.size();
	s = '*' + s;
	for (int i = n + 1; i <= 2 * n; i++)
		s += s[i - n]; 
	pow_p[0] = 1;
	for (int i = 1; i <= n; i++)
		pow_p[i] = (pow_p[i - 1] * p) % mod;
	for (int i = 1; i <= 2 * n; i++)
		h[i] = (h[i - 1] * p + (s[i] - 'a' + 1)) % mod;
	int ans = 1;
	for (int i = 2; i <= n; i++)	
	{
		int LCP = 0;
		int l = 1, r = n;
		while(l <= r)
		{
			int mi = (l + r)/2;
			if (cal_h(ans, ans + mi - 1) == cal_h(i, i + mi - 1))
			{
				LCP = mi;
				l = mi + 1;
			}
			else
				r = mi - 1;
		}
		if (LCP != n && s[ans + LCP] > s[i + LCP])
			ans = i;
	}
	for (int i = ans; i < ans + n; i++)
		cout << s[i];
}