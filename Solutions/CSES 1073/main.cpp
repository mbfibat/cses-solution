#include <bits/stdc++.h>

using namespace std;

vector<int> vi;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		auto it = upper_bound(vi.begin(), vi.end(), x);
		if (it == vi.end())
			vi.push_back(x);
		else
			(*it) = x;	
	}
	cout << vi.size();
}