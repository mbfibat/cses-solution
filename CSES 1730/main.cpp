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
		int nim_sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			nim_sum ^= x;
		}
		cout << ((nim_sum) ? "first" : "second") << '\n';
	}
}