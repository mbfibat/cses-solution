#include <bits/stdc++.h>
 
using namespace std;
//const string filename = "test";
 
typedef long long LL;
 
struct Event
{
	int x, y1, y2, type;
	Event(){}
	Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}
}E[200011];
 
bool operator < (const Event &a, const Event &b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.type < b.type;	
}
 
int top = 0;
 
int n;
 
int Seg[10000011], cnt[10000111];
 
void update(int node, int l, int r, int ll, int rr, int val)
{
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)
	{
		cnt[node] += val;
		if (cnt[node] >= 1) Seg[node] = (r - l + 1);
		else Seg[node] = Seg[node * 2] + Seg[node * 2 + 1];
		return;
	}
	int mi = (l + r)/2;
	update(node * 2, l, mi, ll, rr, val);
	update(node * 2 + 1, mi + 1, r, ll, rr, val);
	if (cnt[node] >= 1) Seg[node] = (r - l + 1);
	else Seg[node] = Seg[node * 2] + Seg[node * 2 + 1];
}
 
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	//freopen( (filename + ".inp").c_str(), "r", stdin);
	//freopen( (filename + ".out").c_str(), "w", stdout);
    
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1 += 1000000, y2 += 1000000;
		E[++top] = Event(x1, y1, y2, 1);
		E[++top] = Event(x2, y1, y2, 2);
	}
	sort(E + 1, E + 1 + top);
	LL ans = 0;
	for (int i = 1; i <= top; i++)
	{
		if (i)
			ans += (1LL * (E[i].x  - E[i - 1].x) * Seg[1]);
		if (E[i].type == 1)
			update(1, 0, 2000000, E[i].y1, E[i].y2 - 1, 1);
		else if (E[i].type == 2)
			update(1, 0, 2000000, E[i].y1, E[i].y2 - 1, -1);
	}
	cout << ans;
}