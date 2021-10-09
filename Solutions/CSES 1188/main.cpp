#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;

struct Node
{
	int sum[2], f[2], pre[2], suf[2];
	Node()
	{
		sum[0] = sum[1] = -1e9;
		for (int i = 0; i < 2; i++)
			f[i] = pre[i] = suf[i] = 0;
	}
}Seg[800001];

void update(int node, int l, int r, int pos)
{
	if (l == r)
	{
		int val = s[pos] - '0';
		Seg[node].sum[val] = Seg[node].f[val] = Seg[node].pre[val] = Seg[node].suf[val] = 1;
		Seg[node].sum[1 - val] = -1e9;
		Seg[node].f[1 - val] = Seg[node].pre[1 - val] = Seg[node].suf[1 - val] = 0;
		return;
	}
	int mi = (l + r)/2;
	if (pos <= mi) update(node * 2, l, mi, pos);
	else update(node * 2 + 1, mi + 1, r, pos);
	for (int val = 0; val < 2; val++)
	{
		Seg[node].sum[val] = max(-1000000000, Seg[node * 2].sum[val] + Seg[node * 2 + 1].sum[val]);
		Seg[node].f[val] = max(Seg[node * 2].f[val], max(Seg[node * 2 + 1].f[val], Seg[node * 2].suf[val] + Seg[node * 2 + 1].pre[val]));
		Seg[node].pre[val] = max(Seg[node * 2].pre[val], Seg[node * 2].sum[val] + Seg[node * 2 + 1].pre[val]);
		Seg[node].suf[val] = max(Seg[node * 2 + 1].suf[val], Seg[node * 2].suf[val] + Seg[node * 2 + 1].sum[val]);
	}
	return;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s; n = s.size();
	s = '*' + s;
	for (int i = 1; i <= n; i++)	
		update(1, 1, n, i);
	cin >> q;
	while (q--)
	{
		int p; cin >> p;
		s[p] = ((s[p] == '1') ? '0' : '1');
		update(1, 1, n, p);
		cout << max(Seg[1].f[0], Seg[1].f[1]) << ' ';
	}
}