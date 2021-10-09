#include <bits/stdc++.h>

using namespace std;

int n;
string s;

vector<int> zf(const string &s) {
	vector<int> f(n);
	for (int i = 1, l = -1, r = -1; i < n; i++) {
		f[i] = ((i > r) ? 0 : min(f[i - l], r - i + 1));
		while (i + f[i] < n && s[f[i]] == s[i + f[i]])
			++f[i];
		if (i + f[i] - 1 > r)
			l = i, r = i + f[i] - 1;
	}
	return f;
}

vector<int> pf(const string &s) {
	vector<int> f(n);
	for (int i = 1; i < n; i++) {
		int j = f[i - 1];
		while (j > 0 && s[j] != s[i])
			j = f[j - 1];
		f[i] = j + (s[j] == s[i]);
	}
	return f;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s; n = s.size();
	vector<int> z = zf(s);
	vector<int> pi = pf(s);

	for (int v : z) cout << v << ' ';
	cout << '\n';
	for (int v : pi) cout << v << ' ';
}