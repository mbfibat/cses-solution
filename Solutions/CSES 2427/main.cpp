#include <bits/stdc++.h>

using namespace std;

int n;
string s;

vector<string> ans;
void out() {
	cout << ans.size() << '\n';
	for (const string& s : ans) cout << s << '\n';
	exit(0);
}

void cant() {
	cout << -1;
	exit(0);
}

// move s[x], s[x + 1] to s[y], s[y + 1]
void move(int x, int y) { // assume that s[x], s[x + 1] are chars and s[y], s[y + 1] are ..
	for (int i = 0; i <= 1; i++) {
		assert(0 <= x + i && x + i < s.size());
		assert(0 <= y + i && y + i < s.size());
	}	
	assert(x + 1 < y || y + 1 < x);
	assert(s[y] == '.'); assert(s[y + 1] == '.');
	s[y] = s[x]; s[y + 1] = s[x + 1];
	s[x] = '.'; s[x + 1] = '.';
	ans.push_back(s);
}

// move .. to end of s
// assume that s.size() >= 6
void moveToEnd() {
	if (s[s.size() - 2] != '.' || s[s.size() - 1] != '.') {
		int pos = -1;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '.') {
				pos = i;
				break;
			}	
		if (pos < s.size() - 3)
			move(s.size() - 2, pos);
		else {
			move(s.size() - 5, pos);
			move(s.size() - 2, s.size() - 5);
		}	
	}
}

void base_case() {
	if (n == 1) out();
	else if (n == 2) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'B') cant();
			else if (s[i] == 'A') out();
		}
	}
}

void small_case() {
	moveToEnd();
	if (s == "AABB..") {}
	else if (s == "BBAA..") move(0, 4);
	else if (s == "ABAB..") cant();
	else if (s == "BABA..") cant();
	else if (s == "ABBA..") {
		move(0, 4);
		move(3, 0);
	} else if (s == "BAAB..") {
		move(2, 4);
		move(0, 2);
		move(3, 0);
	}
	out();		
}

bool notOk(string s) {
	int cnt = 0;
	for (char c : s) {
		if (c == 'B') {
			if (cnt < n - 1) return true;
			else return false;
		}	
		else if (c == 'A') cnt++;
	}	
	return false;
}

void solve() {
	while (notOk(s)) {
		moveToEnd();
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'B') {
				int pos = -1;
				for (int j = i + 2; j < s.size(); j++)
					if (s[j] == 'A') {
						pos = j;
						break;
					}
				if (pos == -1) { // special case AABABB..
					move(i + 2, s.size() - 2);
					move(i, i + 2);
					move(i + 3, i);
					break;
				}
				move(i, s.size() - 2);
				move(pos, i);
				break;
			}			
	}
	out();
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	if (n < 3) base_case();
	else if (n == 3) small_case();
	else solve();
}