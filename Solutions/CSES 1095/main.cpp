#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
int p(int a, int b)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b / 2);
	if (b % 2 == 0) return (tmp * tmp)%mod;
	return ((tmp * tmp)%mod * a)%mod;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while ( t--)
	{
		int a, b;
		cin >> a >> b;
		cout << p(a, b) << '\n';
	}
}