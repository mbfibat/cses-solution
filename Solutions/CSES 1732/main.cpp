#include <bits/stdc++.h>

using namespace std;

string s, t;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	int n = s.size();
	vector<int> pi(n, 0);
	for (int i = 1; i < n - 1; i++)
	{
		int j = pi[i - 1];
		while (j > 0 && s[j] != s[i])
			j = pi[j - 1];
		pi[i] = j + (s[j] == s[i]);
	}
	int j = pi[n - 2];
	vector<int> ans;
	while(j > 0)
	{
		if (s[j] == s.back())
			ans.push_back(j + 1);
		j = pi[j - 1];
	}	
	if (s[j] == s.back())    
		ans.push_back(1);
	for (int i = (int)ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}