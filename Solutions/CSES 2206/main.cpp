#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[200001];

int Seg1[800001], Seg2[800001];

void build(int node, int l, int r)
{
	if (l == r)
	{
		Seg1[node] = a[l] - l;
		Seg2[node] = a[l] + l;
		return;
	}
	int mi = (l + r)/2;
	build(node * 2, l, mi);	
	build(node * 2 + 1, mi + 1, r);
	Seg1[node] = min(Seg1[node * 2], Seg1[node * 2 + 1]);	
	Seg2[node] = min(Seg2[node * 2], Seg2[node * 2 + 1]);	
}

void upd(int node, int l, int r, int pos, int val)
{
	if (l == r)
	{
		Seg1[node] = val - l;
		Seg2[node] = val + l;
		return;
	}
	int mi = (l + r)/2;
	if (pos <= mi)
		upd(node * 2, l, mi, pos, val);
	else
		upd(node * 2 + 1, mi + 1, r, pos, val);	
	Seg1[node] = min(Seg1[node * 2], Seg1[node * 2 + 1]);	
	Seg2[node] = min(Seg2[node * 2], Seg2[node * 2 + 1]);
}

int query1(int node, int l, int r, int ll, int rr)
{
	if (ll > rr) return 2e9;
	if (r < ll || rr < l) return 2e9;
	if (ll <= l && r <= rr) return Seg1[node];
	int mi = (l + r)/2;
	int a = query1(node * 2, l, mi, ll, rr);
	int b = query1(node * 2 + 1, mi + 1, r, ll, rr);
	return min(a, b);
}

int query2(int node, int l, int r, int ll, int rr)
{
	if (ll > rr) return 2e9;
	if (r < ll || rr < l) return 2e9;
	if (ll <= l && r <= rr) return Seg2[node];
	int mi = (l + r)/2;
	int a = query2(node * 2, l, mi, ll, rr);
	int b = query2(node * 2 + 1, mi + 1, r, ll, rr);
	return min(a, b);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	while (q--)
	{
		int type; cin >> type;
		if (type == 1)
		{
			int pos, val;
			cin >> pos >> val;
			upd(1, 1, n, pos, val);
		}
		else
		{
			int pos;
			cin >> pos;
			cout << min(query1(1, 1, n, 1, pos - 1) + pos, query2(1, 1, n, pos, n) - pos) << '\n';
		}
	}
}