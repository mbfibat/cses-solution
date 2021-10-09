#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + 1 < a[i]) {
			cout << sum + 1;
			return 0;
		}		
		sum += a[i];
	}
	cout << sum + 1;
}