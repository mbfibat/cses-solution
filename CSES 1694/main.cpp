#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> adj[501];

struct Edge
{
	int u, v, c, f;
	Edge(){};
	Edge(int _u, int _v, int _c, int _f)
	{
		u = _u;
		v = _v;
		c = _c;
		f = _f;
	}
}E[100001];

int top = 0;
void add_edge(int u, int v, int c)
{
	E[top] = Edge(u, v, c, 0);	
	adj[u].push_back(top++);
	E[top] = Edge(v, u,	0, 0);
	adj[v].push_back(top++);	
}


ll ans = 0;

int p[501];
bool aug_path()
{
	for (int i = 1; i <= n; i++)
		p[i] = -1;
	queue<int> q;
	q.push(1);
	p[1] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int id : adj[u])
			if (p[E[id].v] == -1 && E[id].f < E[id].c)
			{
				p[E[id].v] = id;
				q.push(E[id].v);
			}	
	}
	return (p[n] != -1);
}

void trace()
{
	int cur = n, mn = 1e9;
	while(cur != 1)
	{
		mn = min(mn, E[p[cur]].c - E[p[cur]].f);
		cur = E[p[cur]].u;
	}
	cur = n;
	while(cur != 1)
	{
		E[p[cur]].f += mn;
		E[p[cur] ^ 1].f -= mn;
		cur = E[p[cur]].u;
	}
	ans += mn;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	while(aug_path())
		trace();
	cout << ans;
}