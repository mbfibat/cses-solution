#include <bits/stdc++.h>

using namespace std;

#define int long long

struct state {
	int link, len;
	map<char, int> nxt;
};

int sz, lst;
state st[200001];

void init() {
	st[0].link = -1; st[0].len = 0;
	sz = 1, lst = 0;
}

void add(char c) {
	int cur = sz++, p = lst;
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
			st[clone].nxt = st[q].nxt;
			st[clone].link = st[q].link;
			while (p != -1 && st[p].nxt[c] == q) {
				st[p].nxt[c] = clone;
				p = st[p].link;
			}
			st[cur].link = st[q].link = clone;
		}	
	}	
	lst = cur;
}

int f[200001], g[200001];
int dp(int u) {
	if (g[u]) return f[u];
	int cur = 1;
	for (auto it : st[u].nxt)
		cur += dp(it.second);
	g[u] = true;
	return f[u] = cur;				
}

string s;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> s;
	for (char c : s)
		add(c);
	cout << dp(0) - 1;
}