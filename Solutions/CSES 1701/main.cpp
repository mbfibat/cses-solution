#include <bits/stdc++.h>

using namespace std;

int t, n;
int deg[2][100001];
vector<int> s[2];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int j = 0; j <= 1; j++)
		{
			s[j].clear();
			for (int i = 1; i <= n; i++)
				deg[j][i] = 0;
			for (int i = 1; i <= n - 1; i++)
			{
				int u, v;
				cin >> u >> v;
				deg[j][u]++, deg[j][v]++;
			}
		}	
		for (int j = 0; j <= 1; j++)
		{
			for (int i = 1; i <= n; i++)
				s[j].push_back(deg[j][i]);
			sort(s[j].begin(), s[j].end());
		}
		bool ok = true;
		for (int i = 0; i < n; i++)	
			if (s[0][i] != s[1][i])
				ok = false;
		cout << (ok ? "YES" : "NO") << '\n';
	}
}