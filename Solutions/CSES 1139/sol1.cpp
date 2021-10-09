#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
int a[200001];
vector<int> adj[200001];

int top = 0;
int b[200001];
int st[200001], ed[200001];

void dfs(int u, int p)
{
	st[u] = ++top;
	b[top] = a[u];
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);
	ed[u] = top;
}

vector<iii> q;
map<int, int> pre;

int bit[200001], ans[200001];

void upd(int x, int val)
{
	for (; x <= 200000; x += x & (-x))
		bit[x] += val;
}

int query(int x)
{
	int ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += bit[x];
	return ans;	
}

bool cmp(const iii &a, const iii &b)
{
	return a.second.second < b.second.second;
}

void solve()
{
	for (int i = 1; i <= n; i++)
		q.push_back(iii(i, ii(st[i], ed[i])));
	sort(q.begin(), q.end(), cmp);
	int pos = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pre.find(b[i]) != pre.end())
			upd(pre[b[i]], -1);
		upd(i, 1);
		pre[b[i]] = i;
		while(pos < q.size() && q[pos].second.second == i)
		{
			ans[q[pos].first] = query(i) - query(q[pos].second.first - 1);						
			pos++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	solve();
}