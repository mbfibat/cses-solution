#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Event
{
	int x, y1, y2, type;
	Event(){}
	Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}
}E[200001];

bool operator < (const Event &a, const Event &b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.type < b.type;	
}

int top = 0;

int n;
vector<int> val_y;

int Seg[800001];

void update(int node, int l, int r, int pos, int val)
{
	if (l == r)
	{
		Seg[node] += val;
		return;
	}
	int mi = (l + r)/2;
	if (pos <= mi) update(node * 2, l, mi, pos, val);
	else update(node * 2 + 1, mi + 1, r, pos , val);
	Seg[node] = Seg[node * 2] + Seg[node * 2 + 1];
}

int query(int node, int l, int r, int ll, int rr)
{
	if (r < ll || rr < l)
		return 0;
	if (ll <= l && r <= rr)
		return Seg[node];
	int mi = (l + r)/2;
	int a = query(node * 2, l, mi, ll, rr);
	int b = query(node * 2 + 1, mi + 1, r, ll, rr);
	return a + b;		
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		val_y.push_back(y1); val_y.push_back(y2);
		if (x1 == x2)
			E[++top] = Event(x1, y1, y2, 3);
		else
		{
			E[++top] = Event(x1, y1, y1, 1);
			E[++top] = Event(x2 + 1, y1, y1, 2);
		}
	}
	sort(val_y.begin(), val_y.end());
	sort(E + 1, E + 1 + top);
	LL ans = 0;
	for (int i = 1; i <= top; i++)
	{
		if (E[i].type == 3)
		{
			int y1 = lower_bound(val_y.begin(), val_y.end(), E[i].y1) - val_y.begin() + 1;
			int y2 = lower_bound(val_y.begin(), val_y.end(), E[i].y2) - val_y.begin() + 1;
			ans += query(1, 1, 200000, y1, y2); 
		}	
		else if (E[i].type == 1)
		{
			int y = lower_bound(val_y.begin(), val_y.end(), E[i].y1) - val_y.begin() + 1;
			update(1, 1, 200000, y, 1);
		}
		else if (E[i].type == 2)
		{
			int y = lower_bound(val_y.begin(), val_y.end(), E[i].y1) - val_y.begin() + 1;
			update(1, 1, 200000, y, -1);
		}
	}
	cout << ans;
}