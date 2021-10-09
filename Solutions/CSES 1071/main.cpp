#include <bits/stdc++.h>

using namespace std;

#define int long long

int t;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		int z = max(x, y);
		int ans = (z - 1) * (z - 1) + 1; // (z - 1)^2 + 1
		if (z % 2 == 0) // Down then left
		{
			ans += (x - 1);
			ans += (z - y);
		}
		else // Right then up
		{
			ans += (y - 1);
			ans += (z - x);
		}
		cout << ans << '\n';
	}
}