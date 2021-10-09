#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int n; cin >> n;
		int s = 0;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			s += x % 2;
		}
		cout << (s ? "first" : "second") << '\n';	
	}
}