#include <bits/stdc++.h>

using namespace std;

int x, y;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> y; x--, y--;
	int cur = 1;
	while (cur <= max(x, y)) cur *= 2;

	int ans = 0;
	while (cur > 1) {
		bool fx = (x >= cur / 2), fy = (y >= cur / 2);
		if (fx ^ fy) ans += cur / 2;
		if (fx) x -= cur / 2;
		if (fy) y -= cur / 2;
		cur /= 2;
	}
	cout << ans;
}          