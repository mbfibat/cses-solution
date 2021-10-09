#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

bitset<100001> bs;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bs.set(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		bs |= (bs << x);		
	}

	cout << bs.count() - 1 << '\n';
	for (int i = 1; i <= 100000; i++)
		if (bs.test(i)) cout << i << ' ';
}