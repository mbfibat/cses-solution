#include <bits/stdc++.h>

using namespace std;

struct state {
	int link, len, firstPos;
	map<char, int> nxt;
};

state st[200001];
int sz, lst;

void init() {
	st[0].link = -1, st[0].len = 0;
	sz = 1, lst = 0;
}

void add(char c) {
	int cur = sz++, p = lst;
	st[cur].len = st[p].len + 1;
	st[cur].firstPos = st[cur].len;
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
			st[clone].firstPos = st[q].firstPos;
			while (p != -1 && st[p].nxt[c] == q) {
				st[p].nxt[c] = clone;
				p = st[p].link;				
			}
			st[cur].link = st[q].link = clone;
		}	
	}
	lst = cur;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	string s; cin >> s;
	for (char c : s)
		add(c);
	int n; cin >> n;
	while (n--) {
		string t; cin >> t;
		int cur = 0; bool ok = true;
		for (char c : t) {
			if (!st[cur].nxt.count(c)) {
				ok = false;
				break;
			}
			cur = st[cur].nxt[c];
		}
		cout << (ok ? st[cur].firstPos - (int)t.size() + 1 : -1) << '\n';
	}
}