#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];
int f[1 << 20], g[1 << 20];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++, g[a[i]]++;
	}
	for (int i = 0; i < 20; i++)
	{
		for (int mask = 0; mask < (1 << 20); mask++)
			if (mask >> i & 1)
				f[mask] += f[mask ^ (1 << i)];	
		for (int mask = (1 << 20) - 1; mask >= 0; mask--)
			if (!(mask >> i & 1))
				g[mask] += g[mask | (1 << i)];
	}
	for (int i = 1; i <= n; i++)
		cout << f[a[i]] << ' ' << g[a[i]] << ' ' << (n - f[(1 << 20) - 1 - a[i]]) << '\n';
}