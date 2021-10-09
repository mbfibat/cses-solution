#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[1011];
int h[1011];
int l[1011], r[1011];

int ans = 0;

void solve()
{
	stack<int> S;
	for (int i = 1; i <= m; i++)
	{
		while(!S.empty() && h[S.top()] >= h[i])
			S.pop();
		if (S.empty()) l[i] = 0;
		else l[i] = S.top();
		S.push(i);
	}
	while(!S.empty()) S.pop();
	for (int i = m; i >= 1; i--)
	{
		while(!S.empty() && h[S.top()] >= h[i])
			S.pop();
		if (S.empty()) r[i] = m + 1;
		else r[i] = S.top();
		S.push(i);
	}
	for (int i = 1; i <= m; i++)
	{
		int cur = h[i] * (r[i] - l[i] - 1);
		ans = max(ans, cur);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] == '*') h[j] = 0;
			else h[j]++;
		}
		solve();	
	}
	cout << ans;
}