#include <bits/stdc++.h>

using namespace std;
const string filename = "test";


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	int n;
	cin >> n;
	set<int> S;
	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		s = '*' + s;
		for (int j = 1; j <= n; j++)
			if (s[j] == 'o')
				S.insert(j);	
	}
	cout << S.size() << '\n';
	for (auto &p : S)
		cout << p << '\n';
}