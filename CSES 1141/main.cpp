#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];

map<int, int> cnt;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int l = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		while (cnt[a[i]] >= 2)
			cnt[a[l++]]--;
		ans = max(ans, i - l + 1);		
	}
	cout << ans;
}