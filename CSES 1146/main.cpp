#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

map<ll, ll> val;

ll cal(ll x)
{
	if (x == 0) return 0;
	if (val.count(x))
		return val[x];
	if (x % 2 == 0)
		return val[x] = cal(x / 2) + cal(x / 2 - 1) + x / 2;
	return val[x] = 2 * cal((x - 1) / 2) + (x - 1) / 2 + 1;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cout << cal(n);
}