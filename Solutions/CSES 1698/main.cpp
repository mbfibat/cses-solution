#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
int a[200001];
vector<ii> ans;

vector< vector<int> > np;

void output()
{
	cout << ans.size() << '\n';
	for (ii &p : ans)
		cout << p.first << ' ' << p.second << '\n';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int mx_size = 0;
	for (int i = 1; i <= n; i++)
		if (a[i])
		{
			vector<int> p;
			int j = i;
			do                                                                  
			{
				p.push_back(j);
				j = a[j];
			}while(j != i);
			for (int &v : p)
				a[v] = 0;
			mx_size = max(mx_size, (int)p.size());
			np.push_back(p);					
		}		
	if (mx_size == 1)
		cout << 0;
	else if (mx_size == 2)
	{
		cout << 1 << '\n';
		for (vector<int> &p : np)
			if (p.size() == 2)
				ans.push_back(ii(p[0], p[1]));
		output();							
	}
	else
	{
		cout << 2 << '\n';
		for (vector<int> &p : np)
		{
			if (p.size() == 2)
				ans.push_back(ii(p[0], p[1]));
			else if (p.size() > 2)
				for (int i = 1; i < ((int)p.size() + 1) / 2; i++)
					ans.push_back(ii(p[i], p[p.size() - i]));
		}
		output();
		ans.clear();
		for (vector<int> &p : np)
			if (p.size() > 2)
			{
				ans.push_back(ii(p[0], p[1]));
				for (int i = 2; i <= (int)p.size() / 2; i++)
					ans.push_back(ii(p[i], p[p.size() + 1 - i]));
			}
		output();
	}
}