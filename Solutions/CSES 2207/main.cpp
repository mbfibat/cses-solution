#include <bits/stdc++.h>

using namespace std;

int f[2001];
void cal() {
	f[1] = f[2] = 0;
	for (int i = 3; i <= 2000; i++) {
		vector<int> cur;
		for (int j = 1; j < (i + 1) / 2; j++)
			cur.push_back(f[j] ^ f[i - j]);
		sort(cur.begin(), cur.end());
		cur.resize(unique(cur.begin(), cur.end()) - cur.begin());

		f[i] = cur.size();
		for (int j = 0; j < cur.size(); j++)
			if (j != cur[j]) {
				f[i] = j;
				break;
			}
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cal();

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n > 2000) cout << "first" << '\n';
		else cout << (f[n] ? "first" : "second") << '\n';
	}
}