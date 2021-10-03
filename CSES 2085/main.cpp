#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define int long long

// Template Lichao Tree

int org[1000001]; // Compressed value

struct Line
{
	int a, b;
	Line() : a(0), b(1e18) {}
	Line(int _a, int _b) : a(_a), b(_b) {}
}Tree[4000001];
 
int cal(Line cur,int x)
{
	return cur.a * x + cur.b;
}

void update(int node, int l, int r, Line cur)
{
	int mi = (l+r)/2;
	bool lef = (cal(cur, org[l]) < cal(Tree[node], org[l]));
	bool mid = (cal(cur, org[mi]) < cal(Tree[node], org[mi]));
	if (mid)
		swap(Tree[node], cur);
	if (l == r)
		return;
	if (lef != mid)
		update(node * 2, l, mi, cur);
	else
		update(node * 2 + 1, mi + 1, r, cur);			
}
 
int query(int node, int l, int r, int x)
{
	int cur = cal(Tree[node], org[x]);
	if (l == r)
		return cur;
	int mi = (l + r) / 2;	
	if (x <= mi)
		cur = min(cur, query(node * 2, l, mi, x));
	else
		cur = min(cur, query(node * 2 + 1, mi + 1, r, x));	
	return cur;
}

int n, x;
int a[1000001], b[1000001];
int f[1000001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> x;
    vector<ii> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val.push_back(ii(a[i], i));
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(val.begin(), val.end());
    for (int i = 0; i < val.size(); i++) {
        org[i + 1] = val[i].first;
        a[val[i].second] = i + 1;
    }        
    update(1, 1, n, Line(x, 0));        
    for (int i = 1; i <= n; i++) {
        f[i] = query(1, 1, n, a[i]);
        update(1, 1, n, Line(b[i], f[i]));
    }        
    cout << f[n];
}