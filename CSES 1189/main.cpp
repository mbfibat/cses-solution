#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[200001], b[200001];
int p_a[200001], p_b[200001];

int c[200001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p_a[i] = p_a[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)	
	{
		cin >> b[i];
		p_b[i] = p_b[i - 1] + b[i];
	}
	for (int i = 1; i <= n - 1; i++)
		c[i] = p_a[i] - p_b[i];
	sort (c + 1, c + n);
	int mi = n / 2;
	int val = c[mi], ans = abs(c[mi]);
	for (int i = 1; i <= n - 1; i++)
		c[i] -= val;
	for (int i = 1; i <= n - 1; i++)
		ans += abs(c[i]);
	cout << ans;				
}