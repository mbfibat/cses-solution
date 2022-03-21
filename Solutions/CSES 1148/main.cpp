#include <bits/stdc++.h>      	

using namespace std;

typedef pair<int, int> ii;

int n, m;
string s[1011];
int h[1011], l[1011], r[1011];

int ans[1011][1011];
ii inc[1011][1011], suf[1011][1011];

ii operator+(const ii& lhs, const ii& rhs) {
	return ii(lhs.first + rhs.first, lhs.second + rhs.second);	
}

ii& operator+=(ii& lhs, const ii& rhs) {
	lhs.first += rhs.first;
	lhs.second += rhs.second;
	return lhs;
}

ii operator-(const ii& lhs, const ii& rhs) {
	return ii(lhs.first - rhs.first, lhs.second - rhs.second);	
}

ii& operator-=(ii& lhs, const ii& rhs) {
	lhs.first -= rhs.first;
	lhs.second -= rhs.second;
	return lhs;
}

void upd(int h, int l, int r, ii ab) {
//	cerr << h << ' ' << l << ' ' <<  r << ' ' << '{' << ab.first << ' ' << ab.second << '}' << '\n';
	inc[h][r] += ab;
	inc[h][l - 1] -= ab;
}

void solve() {
	stack<int> S;
	for (int i = 1; i <= m; i++) {
		while(!S.empty() && h[S.top()] >= h[i])
			S.pop();
		if (S.empty()) l[i] = 0;
		else l[i] = S.top();
		S.push(i);
	}
	while(!S.empty()) S.pop();
	for (int i = m; i >= 1; i--) {
		while(!S.empty() && h[S.top()] > h[i])
			S.pop();
		if (S.empty()) r[i] = m + 1;
		else r[i] = S.top();
		S.push(i);
	}

	for (int i = 1; i <= m; i++) {
		if (!h[i]) continue;

		int L = i - l[i], R = r[i] - i;      
		if (L > R) swap(L, R);
//		cerr << '!' << L << ' ' << R << '\n';
		upd(h[i], 1, L, ii(1, 0));
		if (L + 1 <= R)
			upd(h[i], L + 1, R, ii(0, L));
		if (R + 1 <= L + R - 1)	
			upd(h[i], R + 1, L + R - 1, ii(-1, L + R));
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '*') h[j] = 0;
			else h[j]++;
		}
		solve();	
	}

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--) {
			suf[i][j] = suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1] + inc[i][j];
			ans[i][j] = suf[i][j].first * j + suf[i][j].second;
		}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}	
}