#include <bits/stdc++.h>

using namespace std;

string s, t;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> t;
	string S = t + '*' + s;
	int n = S.size();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && S[j] != S[i])
			j = pi[j - 1];
		pi[i] = j + (S[j] == S[i]);
	}
	int ans = 0;
	for (int i = (int)t.size() + 1; i < n; i++)
		if (pi[i] == t.size()) 
			ans++;
	cout << ans;
}