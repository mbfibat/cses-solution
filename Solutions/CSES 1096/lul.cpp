#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n = 1000000;
int f[1000001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++)
			if (i - j >= 0)
				f[i] += f[i - j];
	int k;
	cin >> k;
	cout << f[k];
}