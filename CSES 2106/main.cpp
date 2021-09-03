#include <bits/stdc++.h>

using namespace std;

#define int long long


int n;
string s;

const int p = 31;
int pow_p[100001];
int h[100001];

int cal_h(int l, int r) {
	return h[r] - h[l - 1] * pow_p[r - l + 1];
}

bool check(int len) {
	map<int, bool> cnt;
	for (int i = len; i <= n; i++) {
		if (cnt.count(cal_h(i - len + 1, i)))
			return true;	
		
		cnt[cal_h(i - len + 1, i)] = true;
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pow_p[0] = 1;
	for (int i = 1; i <= 100000; i++)
		pow_p[i] = pow_p[i - 1] * p;
	cin >> s; n = s.size();
	s = '*' + s;
	for (int i = 1; i <= n; i++)
		h[i] = h[i - 1] * p + (s[i] - 'a' + 1);

	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mi = (l + r)/2;
		if (check(mi)) {
			ans = mi;
			l = mi + 1;
		}
		else
			r = mi - 1;
	}
	if (ans == -1) {
		cout << ans;
		return 0;   
	}	

	map<int, bool> cnt;
	for (int i = ans; i <= n; i++) {
		if (cnt.count(cal_h(i - ans + 1, i))) {
			for (int j = i - ans + 1; j <= i; j++)
				cout << s[j];
			return 0;	
		}	
		
		cnt[cal_h(i - ans + 1, i)] = true;
	}
	return false;

}