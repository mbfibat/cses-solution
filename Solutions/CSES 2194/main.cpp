#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii; 
typedef pair<ii, int> iii;

int n;
iii p[200011];

int dist(const ii &lhs, const ii &rhs) {
	int tmp = (lhs.first - rhs.first) * (lhs.first - rhs.first) + (lhs.second - rhs.second) * (lhs.second - rhs.second);
	return tmp;
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
  	for (int i = 1; i <= n; i++) {
  		cin >> p[i].first.first >> p[i].first.second;
  		p[i].second = i;
  	}	
  	sort (p + 1, p + 1 + n);
  	auto cmp = [](int a, int b) { return p[a].first.second < p[b].first.second; };
  	multiset<int, decltype(cmp)> S(cmp);

  	int ans = 9e18;
  	for (int i = 1; i <= n; i++) {
  		p[n + 1] = iii(ii(-1, p[i].first.second - sqrt(ans)), -1);
  		multiset<int>::iterator it = S.lower_bound(n + 1);

  		while (it != S.end() && ans >= (p[i].first.second - p[(*it)].first.second) * (p[i].first.second - p[(*it)].first.second)) {
  			if (ans < (p[i].first.first - p[(*it)].first.first) * (p[i].first.first - p[(*it)].first.first)) it = S.erase(it);
  			else {
  				if (ans > dist(p[*it].first, p[i].first))
  					ans = dist(p[*it].first, p[i].first);
  				it++;
  			}
  		}
  		S.insert(i);
  	}
  	cout << ans << '\n';
}