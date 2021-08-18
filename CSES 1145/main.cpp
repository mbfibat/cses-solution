#include <bits/stdc++.h>

using namespace std;

int n;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> vi;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		auto it = lower_bound(vi.begin(), vi.end(), x);
		if (it == vi.end()) vi.push_back(x);
		else *it = x;
	}
	cout << vi.size();
}