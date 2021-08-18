#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];

int bit[200001];

void upd(int x)
{
	for (; x > 0; x -= x & (-x))
		bit[x]++;
}

int query(int x)
{
	int ans = 0;
	for (; x <= 200000; x += x & (-x))
		ans += bit[x];
	return ans;
}

long long solve_1()
{
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += query(a[i]);		
		upd(a[i]);		
	}
	return ans;
}

bool vis[200001];
vector<int> adj[200001];

int sz;
void dfs(int u)
{
	sz++;
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int solve_2()
{
	for (int i = 1; i <= n; i++)
	{
		int u = i, v = a[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			sz = 0;
			dfs(i);
			ans += (sz - 1);
		}
	return ans;
}

int solve_3()
{
	vector<int> z;
	for (int i = 1; i <= n; i++)
	{
		vector<int>::iterator it = lower_bound(z.begin(), z.end(), a[i]);
		if (it == z.end()) z.push_back(a[i]);
		else *it = a[i];
	}
	return n - z.size();
}

int pos[200001];

int solve_4()
{
	for (int i = 1; i <= n; i++)
		pos[a[i]] = i;
	int ans = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		if (pos[i] > pos[i + 1]) break;
		ans++;
	}
	return n - ans;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << solve_1() << ' ' << solve_2() << ' ' << solve_3() << ' ' << solve_4();
}