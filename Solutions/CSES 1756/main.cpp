#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m, a, b;
ii ans[200001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		cout << a << ' ' << b << '\n';
	}
}