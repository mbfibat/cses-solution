#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int p(int a, int b, int mod)
{
	if (b == 0)
		return 1;
	int tmp = p(a, b / 2, mod);
	if (b % 2 == 0) return (tmp * tmp)%mod;
	return ((tmp * tmp)%mod * a)%mod;
}
 
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
    int mod = 1e9 + 7;
	int t; cin >> t;
	while ( t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << p(a, p(b, c, mod - 1), mod) << '\n';
	}
}