#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
int a[200001];
ii b[200001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i]) cnt++;
		b[i] = ii(a[i], i);
	}	
	int sum = accumulate(a + 1, a + 1 + n, 0);
	int mx = *max_element(a + 1, a + 1 + n);
	if ((sum % 2) || (mx > min(sum / 2, cnt - 1)))
		return cout << "IMPOSSIBLE", 0;

	vector<ii> ans;
	set<ii, greater<ii>> S;
	for (int i = 1; i <= n; i++)
		S.insert(ii(a[i], i));
	while(!S.empty())
	{
		set<ii, greater<ii>>::iterator it = S.begin();
		ii cur_p = (*it);
		++it;
		vector<ii> upd;
		while(cur_p.first--)
		{
			ii tmp_p = (*it);
			ans.push_back(ii(cur_p.second, tmp_p.second));
			tmp_p.first--;
			if (tmp_p.first)
				upd.push_back(tmp_p);
			++it;
		}
		set<ii, greater<ii>>::iterator tmp = S.begin();
		while(tmp != it)
			S.erase(tmp++);
		for (ii x : upd)
			S.insert(x);
	}
	cout << sum / 2 << '\n';
	for (ii p : ans)
		cout << p.first << ' ' << p.second << '\n';
}