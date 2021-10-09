#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q;
int a[200001];

struct Node
{
	int val, lazy_a, lazy_d;
	Node(){}
}Seg[800001];	

void build(int node, int l, int r)
{
	if (l == r)
	{
		Seg[node].val = a[l];
		return;
	}
	int mi = (l + r)/2;
	build(node * 2, l, mi);
	build(node * 2 + 1, mi + 1, r);	
	Seg[node].val = Seg[node * 2].val + Seg[node * 2 + 1].val;
}

void diffuse(int node, int l, int r)
{
	Seg[node].val += (Seg[node].lazy_a * (r - l + 1) + Seg[node].lazy_d * (r - l) * (r - l + 1) / 2);
	if (l != r)
	{
		Seg[node * 2].lazy_a += Seg[node].lazy_a;
		Seg[node * 2].lazy_d += Seg[node].lazy_d;
		int mi = (l + r)/2;
		int nxt_a = Seg[node].lazy_a + (mi + 1 - l) * Seg[node].lazy_d;
		Seg[node * 2 + 1].lazy_a += nxt_a;
		Seg[node * 2 + 1].lazy_d += Seg[node].lazy_d;
	}
	Seg[node].lazy_a = Seg[node].lazy_d = 0;
}

void upd(int node, int l, int r, int ll, int rr, int val, int d)
{
	diffuse(node, l, r);
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)
	{
		Seg[node].lazy_a += val + (l - ll) * d;
		Seg[node].lazy_d += d;
		diffuse(node, l, r);
		return;
	}
	int mi = (l + r)/2;
	upd(node * 2, l, mi, ll, rr, val, d);
	upd(node * 2 + 1, mi + 1, r, ll, rr, val, d);
	Seg[node].val = Seg[node * 2].val + Seg[node * 2 + 1].val;
}

int query(int node, int l, int r, int ll, int rr)
{
	diffuse(node, l, r);
	if (r < ll || rr < l)
		return 0;
	if (ll <= l && r <= rr)
		return Seg[node].val;
	int mi = (l + r)/2;
	int a = query(node * 2, l, mi, ll, rr);
	int b = query(node * 2 + 1, mi + 1, r, ll, rr);
	return a + b;	
}

int32_t main()
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
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1)
			upd(1, 1, n, a, b, 1, 1);
		else
			cout << query(1, 1, n, a, b) << '\n';	
	}
}