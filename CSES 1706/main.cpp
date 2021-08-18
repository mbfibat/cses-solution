#pragma GCC target("popcnt")

#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
 
int par[100001], sz[100001];
 
int anc(int x)
{
	if (par[x] == x) return x;
	return par[x] = anc(par[x]);
}
 
void join(int x, int y)
{
	sz[anc(y)] += sz[anc(x)];
	par[anc(x)] = anc(y);
}
 
int cnt[100001];
vector<int> trans;
bitset<100001> f;
bool done[100001];
 
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		sz[i] = 1;
		par[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (anc(u) != anc(v))
			join(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (!done[anc(i)])
		{
			cnt[sz[anc(i)]]++;
			trans.push_back(sz[anc(i)]);
			done[anc(i)] = true;
		}	
	f.set(0);	
	for (int v : trans)
		f |= (f << v);		
	for (int i = 1; i <= n; i++)
		cout << f.test(i);
}