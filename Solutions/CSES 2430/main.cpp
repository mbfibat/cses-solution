#include <bits/stdc++.h>

using namespace std;

int n;

int cal(int x, int y) {
	if (x == y) {
		if (x == 0) return 0;
		return 1e9;
	}
	if (x > y) swap(x, y);
	int k = y / (x + 1);
	return k + cal(x, y - k * (x + 1));
}

void trace(int x, int y, bool sw = 0) {
	if (x == y) return;

	if (x > y) {
		swap(x, y);
		sw = 1 - sw;
	}	
	cout << sw;
	trace(x, y - (x + 1), sw);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int ans = 1e9, st_x = -1;
	for (int x = 0; x <= n/2; x++) {
		int c = cal(x, n - x);
		if (c < ans) {
			ans = c;		
			st_x = x;
		}	
	}

	trace(st_x, n - st_x);
}