#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001], l[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	stack<int> S; S.push(0);

	for (int i = 1; i <= n; i++) {
		while (a[S.top()] >= a[i]) S.pop();
		l[i] = S.top();
		S.push(i);
	}

	for (int i = 1; i <= n; i++) cout << l[i] << ' ';
}