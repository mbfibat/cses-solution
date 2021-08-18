#include <bits/stdc++.h>

using namespace std;

int n;
int cnt[1000001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		cnt[x]++;
	}
	int ans = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		int cur = 0;
		for (int j = i; j <= 1000000; j += i)
			cur += cnt[j];
		if (cur >= 2)
			ans = max(ans, i);
	}
	cout << ans;
}