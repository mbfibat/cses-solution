#include <bits/stdc++.h>

using namespace std;

int n;
int a[100001], b[100001];
int pos[100001];

int nxt[100001][3];

int cur = 1;

void build(int pre, int l, int r, int dir)
{
	int id = a[cur];
	int x = pos[id];
	if (x < l || r < x)
		return;
	if (pre)	
		nxt[pre][dir] = id;
	cur++;
	build(id, l, x - 1, 1);
	build(id, x + 1, r, 2);
}

vector<int> ans;

void dfs(int u)
{
	if (nxt[u][1]) dfs(nxt[u][1]);
	if (nxt[u][2]) dfs(nxt[u][2]);
	cout << u << ' ';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)	
	{
		cin >> b[i];
		pos[b[i]] = i;
	}
	build(0, 1, n, 0);	
	dfs(a[1]);
}