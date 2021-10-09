#include <bits/stdc++.h>

using namespace std;

int t;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k * k < n) cout << "IMPOSSIBLE";
		else {
			for (int i = k; (i - k) <= n; i += k)
				for (int j = min(n, i); j > (i - k); j--)
					cout << j << ' ';
		}
		cout << '\n';
	}
}