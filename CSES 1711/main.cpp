#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[501];
int c[1001][1001], f[1001][1001], id[1001][1001];

int top = 0;

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
		for (int v : adj[u])
			if (p[v] == -1 && f[u][v] < c[u][v])
			{
				p[v] = u;
				q.push(v);
			}
	}	
	return (p[n] != -1);
}

void trace()
{
	int cur = n;
	while (cur != 1)
	{
		f[p[cur]][cur]++;
		f[cur][p[cur]]--;
		cur = p[cur];
	}
}

vector<int> ans;
void find_P()
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
		for (int v : adj[u])
			if (p[v] == -1 && c[u][v] && f[u][v])
			{
				p[v] = u;
				q.push(v);
			}	
	}
	ans.clear();
	int cur = n;
	ans.push_back(n);
	while(cur != 1)
	{
		f[p[cur]][cur]--;
		cur = p[cur];
		ans.push_back(cur);
	}
	reverse(ans.begin(), ans.end());
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		c[u][v] = 1;
		adj[v].push_back(u);
	}

	while(aug_path())
	{
		top++;
		trace();
	}	

	cout << top << '\n';
	while(top--)
	{
		find_P(); 
		cout << ans.size() << '\n';
		for (int v : ans)
			cout << v << ' ';
		cout << '\n';
	}	
}