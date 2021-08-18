#pragma GCC target("popcnt")

#include <bits/stdc++.h>
 
using namespace std;
 
int n;
bitset<3001> bs[3001];
 
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n;
	for (int i = 1; i <= n; i++) { 
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++)
			bs[i].set(j + 1, s[j] == '1');
	}	
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			int cnt = (bs[i] & bs[j]).count();
			ans += (long long) cnt * (cnt - 1) / 2;
		}
	cout << ans;	
}