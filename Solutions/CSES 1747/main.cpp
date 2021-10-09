#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

int n;
int a[200011], pos[200011];

// Ngo doc thuat toan 100

int Seg[800001];

void upd(int node, int l, int r, int ll, int rr, int val)
{
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)	
	{
		Seg[node] += val;
		return;
	}
	int mi = (l + r)/2;
	upd(node * 2, l, mi, ll, rr, val);	
	upd(node * 2 + 1, mi + 1, r, ll, rr, val);	
}

int query(int node, int l, int r, int pos)
{
	if (l == r)
		return Seg[node];
	int mi = (l + r)/2;
	if (pos <= mi)
		return Seg[node] + query(node * 2, l, mi, pos);
	return Seg[node] + query(node * 2 + 1, mi + 1, r, pos);
}

int main(int argc, char** argv)
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
	for (ii p : val)	
	{
		if (p.first != pre)
		{
			top++;
			pre = p.first;
		}
		a[p.second] = top;
	}
	for (int i = 1; i <= n; i++)
		pos[a[i]] = i;
	ll ans = 0;
	int l = 1, r = n;
	for (int i = 1; i <= n; i++)
	{
		int cur_pos = pos[i] + query(1, 1, n, pos[i]);
		if (cur_pos - l < r - cur_pos)
		{
			ans += cur_pos - l;
			upd(1, 1, n, 1, pos[i], 1);
			l++;
		}
		else
		{
			ans += r - cur_pos;
			upd(1, 1, n, pos[i], n, -1);
			r--;
		}
	}	
	cout << ans;
}