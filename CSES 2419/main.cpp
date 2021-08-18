#include <bits/stdc++.h>

using namespace std;

int n;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (((n - 1) & i) == i)
			ans ^= x;
	}
	cout << ans;					
}