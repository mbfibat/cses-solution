#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, q;
ii t[200011];

int f[1000011][21];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> t[i].first >> t[i].second;
	sort(t + 1, t + 1 + n);
	int pos = n, mn_r = 1000001;
	for (int i = 1000000; i >= 1; i--)
	{
		while(pos >= 1 && t[pos].first == i)
		{
			mn_r = min(mn_r, t[pos].second);
			pos--;
		}	
		f[i][0] = mn_r;
	}
	for (int j = 0; j <= 20; j++)
		f[1000001][j] = 1000001;		
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= 1000000; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		int cur = a, ans = 0;
		for (int j = 20; j >= 0; j--)
			if (f[cur][j] <= b)
			{
				cur = f[cur][j];
				ans |= (1 << j);
			}	
		cout << ans << '\n';	
	}
}