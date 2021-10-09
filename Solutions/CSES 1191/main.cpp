#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[400011], nxt[400011][21];

int solve(int pos)
{
	int cur = pos, ans = 0;
	for (int i = 20; i >= 0; i--)
	{
		if (nxt[cur][i] <= pos + n)
		{
			cur = nxt[cur][i];
			ans |= (1 << i);
		}
		if (cur == pos + n) break;
	}	
	if (cur != pos + n)
		ans++;					
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	int r = 1, cur = 0;
	for (int i = 1; i <= 2 * n; i++)			
	{
		while(r <= 2 * n && cur + a[r] <= k) 
		{
			cur += a[r];
			r++;
		}	
		nxt[i][0] = r;
		cur -= a[i];
	}
	for (int j = 0; j <= 20; j++)
		nxt[2 * n + 1][j] = 2 * n + 1;
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= 2 * n; i++)
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	//cerr << nxt[16][1];
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
		ans = min(ans, solve(i));
	cout << ans;		
}