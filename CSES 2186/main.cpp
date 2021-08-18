#include <bits/stdc++.h>

using namespace std;

string s;
map<vector<int>, int> mp;

int id[505];
int cnt[200001][31];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	s = '*' + s;

	vector<char> allC;
	for (int i = 1; i < s.size(); i++)
		allC.push_back(s[i]);
	sort(allC.begin(), allC.end());
	allC.resize(unique(allC.begin(), allC.end()) - allC.begin());
	for (int i = 0; i < allC.size(); i++)
		id[allC[i]] = i;  

	int sz = allC.size();
	
	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j < sz; j++)
			cnt[i][j] = cnt[i - 1][j];
		cnt[i][id[s[i]]]++;
	}

	vector<int> cur(sz - 1, 0);
	mp[cur]++;
	long long ans = 0;
	for (int i = 1; i < s.size(); i++) {
		vector<int> cur;
		for (int j = 1; j < sz; j++)
			cur.push_back(cnt[i][j] - cnt[i][j - 1]);
//		for (int val : cur)
//			cerr << val << ' ';
//		cerr << '\n';	
		ans += mp[cur];
		mp[cur]++;
	}
	cout << ans;
}