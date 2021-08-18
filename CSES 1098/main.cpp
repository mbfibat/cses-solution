#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n;
		int nim_sum = 0;
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			int grundy_value = x % 4;
			nim_sum ^= grundy_value;
		}
		cout << ((nim_sum) ? "first" : "second") << '\n';
	}
}