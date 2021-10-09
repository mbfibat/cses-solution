#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, x;
int w[20];
ii f[1 << 20];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < (1 << n); i++)
		f[i] = ii(1e9, 1e9);
	f[0] = ii(0, 0);
	for (int mask = 0; mask < (1 << n); mask++)
		for (int i = 0; i < n; i++)
			if (!(mask >> i & 1))
			{
				ii nxt = f[mask];
				nxt.second += w[i];
				if (nxt.second > x)
				{
					nxt.first++;
					nxt.second = w[i];
				}
				f[mask | (1 << i)] = min(f[mask | (1 << i)], nxt);	
			}
	cout << f[(1 << n) - 1].first + (f[(1 << n) - 1].second ? 1 : 0);
}