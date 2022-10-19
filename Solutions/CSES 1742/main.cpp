#include <bits/stdc++.h>            	

using namespace std;

struct Event {
	int t, x, y1, y2;
	Event() {}
	Event(int _t, int _x, int _y1, int _y2) : t(_t), x(_x), y1(_y1), y2(_y2) {}
};

bool operator<(const Event& lhs, const Event& rhs) {
	if (lhs.x != rhs.x) return lhs.x < rhs.x;
	return lhs.t < rhs.t;
}

int n;
vector<Event> vi;

bool check(int b) {
	vector<Event> a;
	for (int i = 0; i < b; i++)
		a.emplace_back(vi[i]);
	sort(a.begin(), a.end());
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	char pre_c = '*';
	int pre_x = 0, pre_y = 0;

	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		char c; int d; cin >> c >> d;

		int cur_x = pre_x, cur_y = pre_y;

		if (c == 'U') {
			if (pre_c == 'D') {
				r = i - 1;
				break;
			}
			pre_y += d;
		}
		else if (c == 'D') {
			if (pre_c == 'U') {
				r = i - 1;
				break;
			}
			pre_y -= d;
		}
		else if (c == 'L') {
			if (pre_c == 'R') {
				r = i - 1;
				break;
			}
			pre_x -= d;
		}
		else {
			if (pre_c == 'L') {
				r = i - 1;
				break;
			}
			pre_x += d;
		}
		
		if (c == 'L' || c == 'R') {
			vi.emplace_back(0, cur_x, cur_y, cur_y);
			vi.emplace_back(1, pre_x + 1, cur_y, cur_y);
		}
		else vi.emplace_back(2, cur_x, cur_y, pre_y);
		pre_c = c;
	}

	int b = 0;
	while (l <= r) {
		int mi = (l + r)/2;
		if (check(mi)) {
			b = mi;
			r = mi - 1;
		}
		else
			l = mi + 1;
	}
}