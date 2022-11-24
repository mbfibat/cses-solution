#include <bits/stdc++.h>            	
 
using namespace std;
 
const string filename = "test";
 
typedef long long LL;
typedef pair<LL, int> li;
 
struct Event {
	int t, id;
	LL x, y1, y2;
	Event() {}
	Event(int _t, LL _x, LL _y1, LL _y2, int _id) : t(_t), x(_x), y1(_y1), y2(_y2), id(_id) {}
};
 
bool operator < (const Event& lhs, const Event& rhs) {
	if (lhs.x != rhs.x) return lhs.x < rhs.x;
	if (lhs.t != rhs.t) return lhs.t < rhs.t;
	return lhs.y2 < rhs.y2;
}
 
struct Query {
	int t;
	LL y1, y2;
	int id_y1, id_y2;
	Query() {}
	Query(int _t, LL _y1, LL _y2, int id_y1, int id_y2) : t(_t), y1(_y1), y2(_y2), id_y1(id_y1), id_y2(id_y2) {}
};
 
struct Line {
	LL x1, y1, x2, y2;
	Line(){}
	Line(LL _x1, LL _x2, LL _y1, LL _y2) : x1(_x1), x2(_x2), y1(_y1), y2(_y2) {}
}L[100001];
 
int n;
LL D[100001];
char C[100001];
vector<Event> vi;

LL BIT[200001];

void upd(int x, int val) {
	for (; x <= 200000; x += x & (-x))
		BIT[x] += val;
}

LL query_cnt(int x) {         
	
	LL ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += BIT[x];
	return ans;	
}

LL query_cnt_range(int l, int r) {
	return query_cnt(r) - query_cnt(l - 1);
}                 

int inc[200001];
vector<LL> val_y;

bool check(int b) {
	vector<Event> a;
	for (int i = 0; i < vi.size(); i++)
		if (vi[i].id <= b)
			a.push_back(vi[i]);

	for (int i = 1; i <= 200000; i++)
		BIT[i] = inc[i] = 0;
 
	LL tot = 0;
	for (int i = 0; i < a.size(); i++) {
		vector<Query> q;
		LL cur_x = a[i].x;
		while (i < a.size() && a[i].x == cur_x) {
			int id_y1 = lower_bound(val_y.begin(), val_y.end(), a[i].y1) - val_y.begin() + 1;
			int id_y2 = lower_bound(val_y.begin(), val_y.end(), a[i].y2) - val_y.begin() + 1;
			q.push_back(Query(a[i].t, a[i].y1, a[i].y2, id_y1, id_y2));
			++i;
		}
		--i;
 
		LL max_y2 = -1e18;
 
		for (const Query& cur_q : q) {
		    int id_y1 = cur_q.id_y1, id_y2 = cur_q.id_y2;
			if (cur_q.t == 0) {
				tot += inc[id_y1];
				inc[id_y1]++;
				upd(id_y1, 1);
			} else if (cur_q.t == 2) { 
				inc[id_y1]--;
				upd(id_y1, -1);
			} else {
				if (cur_q.y1 < max_y2) return false;

				tot += max_y2 == cur_q.y1;          
				max_y2 = max(max_y2, cur_q.y2);

				tot += query_cnt_range(id_y1, id_y2);
			}
		}

		for (const Query& cur_q : q)
			if (cur_q.t == 0) {
				int id_y1 = cur_q.id_y1;
				if (inc[id_y1] >= 2) return false;
			}
	}

	return tot == b - 1;
}
 
bool intersect(Line l1, Line l2) {
	if (l1.x2 < l2.x1 || l2.x2 < l1.x1) return false;
	if (l1.y2 < l2.y1 || l2.y2 < l1.y1) return false;
	return true;
}
 
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	cin >> n;
 
	char pre_c = '*';
	LL pre_x = 0, pre_y = 0;
 
    int b = 0, l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		char c; int d; cin >> c >> d;
		C[i] = c; D[i] = d;
 
		LL cur_x = pre_x, cur_y = pre_y;
 
		if (c == 'U') {
			cur_y += d;
			if (C[i - 1] == 'D') r = min(r, i);
		}	
		else if (c == 'D') {
			cur_y -= d;
			if (C[i - 1] == 'U') r = min(r, i);
		}	
		else if (c == 'L') {
			cur_x -= d;
			if (C[i - 1] == 'R') r = min(r, i);
		}	
		else if (c == 'R') {
			cur_x += d;
			if (C[i - 1] == 'L') r = min(r, i);
		}	
		
		if (c == 'L' || c == 'R') {
			vi.push_back(Event(0, min(pre_x, cur_x), cur_y, cur_y, i));
			vi.push_back(Event(2, max(pre_x, cur_x), cur_y, cur_y, i));
		}	
		else vi.push_back(Event(1, cur_x, min(pre_y, cur_y), max(pre_y, cur_y), i));
		L[i] = Line(min(pre_x, cur_x), max(pre_x, cur_x), min(pre_y, cur_y), max(pre_y, cur_y));
 
		pre_x = cur_x, pre_y = cur_y;
	}
 
    sort(vi.begin(), vi.end());
	for (int i = 0; i < vi.size(); i++) {
		val_y.push_back(vi[i].y1);
		val_y.push_back(vi[i].y2);
	}
	sort(val_y.begin(), val_y.end());
	val_y.resize(unique(val_y.begin(), val_y.end()) - val_y.begin());

	while (l <= r) {
		int mi = (l + r)/2;
		if (check(mi)) {
			b = mi;
			l = mi + 1;
		}
		else
			r = mi - 1;
	}

	LL ans = 0;
	for (int i = 1; i <= b; i++)
		ans += D[i];

	if (b + 1 <= n) {
		int l = 1, r = D[b + 1], len = D[b + 1];
		while (l <= r) {
			int mi = (l + r)/2;
			Line cur = L[b + 1];
			if (C[b + 1] == 'R') {
				cur.x2 = cur.x1 + mi;
				cur.x1++;
			}	
			else if (C[b + 1] == 'L') {
				cur.x1 = cur.x2 - mi;
				cur.x2--;
			}	
			else if (C[b + 1] == 'U') {
				cur.y2 = cur.y1 + mi;
				cur.y1++;
			}	
			else {
				cur.y1 = cur.y2 - mi;
				cur.y2--;
			}	
 
			bool ok = false;
			for (int i = 1; i <= b; i++)
				if (intersect(L[i], cur)) {
					ok = true;
					break;
				}
			if (ok) {
				len = mi;
				r = mi - 1;
			} else
				l = mi + 1;
		}                                         
		if (C[b] == 'L' && C[b + 1] == 'R') len = 0;
		if (C[b] == 'R' && C[b + 1] == 'L') len = 0;
		if (C[b] == 'D' && C[b + 1] == 'U') len = 0;
		if (C[b] == 'U' && C[b + 1] == 'D') len = 0;
		ans += len;
	}	

	cout << ans;
}