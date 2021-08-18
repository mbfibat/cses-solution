#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m, k;
ii q[200001], E[200001];
int p[200001];

map<ii, bool> chk;

int anc(int x)
{
	if (p[x] == x) return x;
	return p[x] = anc(p[x]); 
}

void join(int x, int y)
{
	p[anc(x)] = anc(y);
}

int ans[200001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> E[i].first >> E[i].second;
		if (E[i].first > E[i].second)
			swap(E[i].first, E[i].second);
	}	
	for (int i = 1; i <= k; i++)
	{				
		cin >> q[i].first >> q[i].second;
		if (q[i].first > q[i].second)
			swap(q[i].first, q[i].second);
		chk[q[i]] = true;
	}	

	int cur = n;
	for (int i = 1; i <= m; i++)
		if (!chk[E[i]] && (anc(E[i].first) != anc(E[i].second)))
		{
			join(E[i].first, E[i].second);
			cur--;				
		}
	ans[k] = cur;
	for (int i = k; i >= 1; i--)
	{
		if (anc(q[i].first) != anc(q[i].second))
		{
			join(q[i].first, q[i].second);
			cur--;
		}	
		ans[i - 1] = cur;		
	}
	for (int i = 1; i <= k; i++)
		cout << ans[i] << ' ';
}