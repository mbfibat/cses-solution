#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);

	int v = a[(n + 1) / 2];
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += abs(a[i] - v);		
	cout << ans;
}