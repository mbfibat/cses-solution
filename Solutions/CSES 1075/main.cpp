#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n;
int f[1001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	f[0] = f[1] = 1;
	for (int i = 4; i <= 1000; i++)
		f[i] = (((i + 1) * f[i - 1] - (i - 2) * f[i - 2] - (i - 5) * f[i - 3] + (i - 3) * f[i - 4]) % mod + mod) % mod;
	cin >> n;
	cout << f[n];
}