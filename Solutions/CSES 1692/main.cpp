#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
vector<ii> adj[1 << 14];

void build()
{
	for (int i = 0; i < 1 << (n - 1); i++)
	{
		int cur = (i & (i ^ 1 << (n - 2))) << 1;
		for (int j = 0; j <= 1; j++)
		{
			int nxt = cur + j;
			adj[i].push_back(ii(nxt, j));
		}	
	}
}

string ans;

void find_Path(int u)
{
	while(!adj[u].empty())
	{
		int v = adj[u].back().first;
		int w = adj[u].back().second;
		adj[u].pop_back();
		find_Path(v);
		ans += ('0' + w);
	}	
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	if (n == 1) ans = "01";
	else
	{
		build();
		find_Path(0);
		for (int i = 1; i < n; i++)
			ans += '0';
	}
	cout << ans;
}