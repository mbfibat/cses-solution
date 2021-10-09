#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;
const int mod = 1e9 +7 ;

int n;
int a[200001];
int bit[200001];

void update(int x, int val)
{
	for (; x <= 200000; x += x&(-x))
		(bit[x] += val) %= mod;
}

int query(int x)
{
	int ans = 0;
	for (; x > 0; x -= x&(-x))
		(ans += bit[x]) %= mod;
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<ii> val;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		val.push_back(ii(a[i], i));
	}	
	sort(val.begin(), val.end());
	int pre = -1, top = 0;
	for (int i = 0; i < val.size(); i++)
	{
		if (val[i].first != pre)
		{
			pre = val[i].first;
			top++;
		}
		a[val[i].second] = top;
	}
	int ans = 0;
	update(1, 1);
	for (int i = 1; i <= n; i++)
	{
		int f = query(a[i]);
		(ans += f) %= mod;
		update(a[i] + 1, f);	
	}
	cout << ans;
}