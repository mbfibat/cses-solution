#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

struct State {
	int link, len, cnt;
	map<char, int> nxt;
	State(){}
};

State st[200001];
int sz, lst;

void init() {
	st[0].link = -1; st[0].len = 0;
	sz = 1, lst = 0;		
}

void add(char c) {
	int cur = sz++, p = lst;
	st[cur].cnt = 1;
	st[cur].len = st[p].len + 1;
	while (p != -1 && !st[p].nxt.count(c)) {
		st[p].nxt[c] = cur;
		p = st[p].link;
	}
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].nxt[c];
		if (st[q].len == st[p].len + 1)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].link = st[q].link;
			st[clone].nxt = st[q].nxt;
			while (p != -1 && st[p].nxt[c] == q) {
				st[p].nxt[c] = clone;
				p = st[p].link;
			}
			st[q].link = st[cur].link = clone;
		}	
	}
	lst = cur;
}

void upd_cnt() {
	vector<ii> v;
	for (int i = 1; i < sz; i++)
		v.push_back(ii(st[i].len, i));
	sort(v.begin(), v.end(), greater<ii>());
	for (int i = 0; i < v.size(); i++) {
		int u = v[i].second;
		st[st[u].link].cnt += st[u].cnt;
	}	
}

int f[200001], g[200001];

int dp (int cur) {
	if (g[cur]) return f[cur];
	int ans = st[cur].cnt;
	for (auto it : st[cur].nxt)
		ans += dp(it.second);
	g[cur] = 1;
	return f[cur] = ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	string s; cin >> s;
	for (char c : s)
		add(c);
	upd_cnt();

	int k; cin >> k;
	int cur = 0;
	string ans;
	while (k) {
		if (cur) {
			k -= st[cur].cnt;
			if (k <= 0) break;
		}
		for (auto it : st[cur].nxt) {
			int v = it.second;
			if (k <= dp(v)) {
				ans += it.first;
				cur = v;
				break;
			}
			else
				k -= dp(v);
		}		
	}
	cout << ans;
}