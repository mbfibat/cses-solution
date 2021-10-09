#include <bits/stdc++.h>

using namespace std;

struct state {
	int link, len;
	map<char, int> nxt;	
};

int sz, lst;
state st[200001];

void init() {
	st[0].len = 0, st[0].link = -1;
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

int cnt[100011];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	string s; cin >> s;
	for (char c : s)
		add(c);

	for (int i = 1; i < sz; i++) {
		cnt[st[st[i].link].len + 1]++;
		cnt[st[i].len + 1]--;
	}
	for (int i = 1; i <= (int)s.size(); i++) {
		cnt[i] += cnt[i - 1];
		cout << cnt[i] << ' ';
	}
}