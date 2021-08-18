#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n, q;
int a[200001];

int top_ver = 1;
int ver[200001];

struct Node
{
	LL val;
	int l, r;
	Node(){}
};

struct PersistentSegmentTree
{
	vector<Node> Tree = {Node()};

	void build(int node, int l, int r)
	{
		if (l == r)
		{
			Tree[node].val = a[l];
			return;
		}	
		Tree[node].l = Tree.size();
		Tree.push_back(Node());
		Tree[node].r = Tree.size();
		Tree.push_back(Node());
		int mi = (l + r)/2;
		build(Tree[node].l, l, mi);
		build(Tree[node].r, mi + 1, r);
		Tree[node].val = Tree[Tree[node].l].val + Tree[Tree[node].r].val;
	}

	LL query_Seg(int node, int l, int r, int ll, int rr)
	{
		if (r < ll || rr < l)
			return 0;
		if (ll <= l && r <= rr)
			return Tree[node].val;
		int mi = (l + r)/2;
		LL a = query_Seg(Tree[node].l, l, mi, ll, rr);								
		LL b = query_Seg(Tree[node].r, mi + 1, r, ll, rr);								
		return a + b;
	}
	
	LL query(int k, int l, int r)
	{
		return query_Seg(ver[k], 1, n, l, r);
	}

	void update_Seg(int pre_node, int cur_node, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			Tree[cur_node].val = val;
			return;
		}
		int mi = (l + r)/2;
		if (pos <= mi)
		{
			Tree[cur_node].l = Tree.size();
			Tree.push_back(Node());
			Tree[cur_node].r = Tree[pre_node].r;
			update_Seg(Tree[pre_node].l, Tree[cur_node].l, l, mi, pos, val);
		}
		else
		{
			Tree[cur_node].r = Tree.size();
			Tree.push_back(Node());
			Tree[cur_node].l = Tree[pre_node].l;
			update_Seg(Tree[pre_node].r, Tree[cur_node].r, mi + 1, r, pos, val);
		}
		Tree[cur_node].val = Tree[Tree[cur_node].l].val + Tree[Tree[cur_node].r].val;
	}

	void update(int k, int pos, int val)
	{
		int tmp = Tree.size();
		Tree.push_back(Node());
		update_Seg(ver[k], tmp, 1, n, pos, val);
		ver[k] = tmp;
	}

	void update_3(int k)
	{
		ver[++top_ver] = ver[k];
	}	
}PST;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ver[1] = 0;
	PST.build(0, 1, n);
	for (int i = 1; i <= q; i++)
	{
		int type; cin >> type;
		if (type == 1)
		{
			int k, a, x;
			cin >> k >> a >> x;
			PST.update(k, a, x);
		}
		else if (type == 2)
		{
			int k, a, b;
			cin >> k >> a >> b;
			cout << PST.query(k, a, b) << '\n';
		}
		else
		{
			int k; cin >> k;
			PST.update_3(k);				
		}
	}
}