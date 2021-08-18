#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	multiset<int> mn;
	multiset<int, greater<int>> mx; 

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (mx.empty() || a[i] <= (*mx.begin()))
			mx.insert(a[i]);
		else
			mn.insert(a[i]);	
		if (i > k) {
			if (mx.find(a[i - k]) != mx.end()) mx.erase(mx.find(a[i - k]));
			else mn.erase(mn.find(a[i - k]));		
		}
		while (mx.size() >= mn.size() + 2) {
			mn.insert(*mx.begin());
			mx.erase(mx.begin());
		}
		while (mn.size() >= mx.size() + 1) {
			mx.insert(*mn.begin());
			mn.erase(mn.begin());
		}

		if (i >= k)
			cout << (*mx.begin()) << ' ';
//		for (int v : mx) cerr << v << ' '; cerr << '\n';
//		for (int v : mn) cerr << v << ' ';
//		cerr << '\n' << '\n';
	}
}