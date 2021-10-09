#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001], p[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}

	int ans = 1;
	for (int i = 2; i <= n; i++)
		if (p[i - 1] > p[i])
			ans++;
	cout << ans;
}