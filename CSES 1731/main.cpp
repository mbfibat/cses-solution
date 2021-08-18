#include <bits/stdc++.h>

using namespace std;
const string filename = "test";

#define int long long

const int h_mod = 1000008181;
const int mod = 1e9 + 7;
const int p = 31;
int pow_p[10001];

int n, k;
string s;
int h[10001], f[10001]; 
int cal_h(int l, int r)
{
	return ((h[r] - h[l - 1] * pow_p[r - l + 1])%h_mod + h_mod)%h_mod;
}

vector<int> l;
map<int, int> mp[1000001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pow_p[0] = 1;
	for (int i = 1; i <= 5000; i++)
		pow_p[i] = (pow_p[i - 1] * p) % h_mod;
	cin >> s;
	n = s.size();
	s = '*' + s;
	for (int i = 1; i <= n; i++)
		h[i] = (h[i - 1] * p + (s[i] - 'a' + 1))%h_mod;		
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		string t;
		cin >> t;
		l.push_back(t.size());
		int cur_h = 0;
		for (int j = 0; j < t.size(); j++)
			cur_h = (cur_h * p + (t[j] - 'a' + 1))%h_mod;
		mp[t.size()][cur_h]++;
	}
	sort(l.begin(), l.end());
	l.resize(unique(l.begin(), l.end()) - l.begin());
	f[0] = 1;
	for (int i = 1; i <= n; i++)	
	{
		for (int len : l)
		{
			int z = i - len + 1;
			if (z <= 0) break;
			int cur_h = cal_h(z, i);
			if (mp[len].count(cur_h))
				(f[i] += (f[i - len] * mp[len][cur_h])%mod) %= mod;
		}
	}
	cout << f[n];
}