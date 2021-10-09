#include <bits/stdc++.h>

using namespace std;
const string filename = "test";

int t, n;
vector<int> adj[2][100001], nxt[2][100001];

void init(int u, int p, int ver)
{
	for (int v : adj[ver][u])
		if (v != p)
		{
			nxt[ver][u].push_back(v);
			init(v, u, ver);
		}	
}

bool check(int node1, int node2)
{
//	cerr << '?' << node1 << ' ' << node2 << '\n';
	if (nxt[0][node1].size() != nxt[1][node2].size())
		return false;

	if (!nxt[0][node1].size())
		return true;

	if (nxt[0][node1].size() == 1)
		return check(nxt[0][node1][0], nxt[1][node2][0]);

	for (int i = 0; i < nxt[0][node1].size(); i++)
		for (int j = 0; j < nxt[1][node2].size(); j++)
			if (check(nxt[0][node1][i], nxt[1][node2][j]) && check(nxt[0][node1][1 - i], nxt[1][node2][1 - j]))
				return true;
	return false;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int j = 0; j <= 1; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				adj[j][i].clear();
				nxt[j][i].clear();
			}
			for (int i = 1; i <= n - 1; i++)
			{
				int u, v;
				cin >> u >> v;
				adj[j][u].push_back(v);
				adj[j][v].push_back(u);
			}
		}
		for (int i = 0; i <= 1; i++)
			init(1, -1, i);
		cout << (check(1, 1) ? "YES" : "NO") << '\n'; 	
	}
}