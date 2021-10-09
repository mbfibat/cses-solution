#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> sw = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8}, {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}};

int d[2000001];
vector<int> z[2000001];

int fact[11];
int cal(vector<int> &x) // find id
{
	int cur = 1, mask = 0;
	for (int i = 0; i < 9; i++)
	{
		int v = x[i];
		int cnt_s = v - __builtin_popcount(mask & ((1 << v) - 1));
		cur += cnt_s * fact[9 - 1 - i];
		mask |= (1 << v);
	}
	//cerr << cur << '\n';
	return cur;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 10; i++)
		fact[i] = fact[i - 1] * i;
	vector<int> p;
	for (int i = 1; i <= 9; i++)
		p.push_back(i);
	int T = cal(p);
	do
	{
		assert(z[cal(p)].empty());
		z[cal(p)] = p;			
	} while(next_permutation(p.begin(), p.end()));	
	vector<int> x;
	for (int i = 1; i <= 9; i++)
	{
		int v; cin >> v;
		x.push_back(v);
	}
	for (int i = 0; i <= 2000000; i++)
		d[i] = 1e9;
	queue<int> q;
	int id_x = cal(x);
	q.push(id_x);
	d[id_x] = 0;
	while(!q.empty()) 
	{
		int u = q.front();
		q.pop();
		if (u == T)
		{
			cout << d[u];
			return 0;
		}	
		vector<int> tmp = z[u];
		for (ii p : sw)
		{
			swap(tmp[p.first], tmp[p.second]);
			int nxt = cal(tmp);
			if (d[nxt] == 1e9)
			{
				d[nxt] = d[u] + 1;	
				q.push(nxt);
			}
			swap(tmp[p.first], tmp[p.second]);	
		}
	}
}