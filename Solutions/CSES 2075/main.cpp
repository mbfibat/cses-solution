#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef struct Item* pItem;

struct Item {
	bool rev = false;
	int prior, val, cnt = 1, mn;
	pItem l = nullptr, r = nullptr;
	Item(int val) : prior(rand()), val(val), mn(val) {}
};

int cnt(pItem T) {
	if (!T) return 0;
	return T -> cnt;
}

int mn(pItem T) {
	if (!T) return 1e9;
	return T -> mn;
}

void upd(pItem T) {
	T -> cnt = 1 + cnt(T -> l) + cnt(T -> r);
	T -> mn = min(T -> val, min(mn(T -> l), mn(T -> r)));
}

void push(pItem T) {
	if (T && T -> rev) {
		T -> rev = false;
		if (T -> l) T -> l -> rev ^= 1;
		if (T -> r) T -> r -> rev ^= 1;
		swap(T -> l, T -> r);
	}
}

void split(pItem T, int key, pItem& l, pItem& r, int add = 0) {
	if (!T) {
		l = r = nullptr;
		return;
	}	
	push(T);
	int cur_key = add + cnt(T -> l);
	if (cur_key > key)
		split(T -> l, key, l, T -> l, add), r = T;
	else		
		split(T -> r, key, T -> r, r, add + 1 + cnt(T -> l)), l = T;
	upd(T);
}

void merge(pItem &T, pItem l, pItem r) {
	push(l);
	push(r);
	if (!l || !r)
		T = (l ? l : r);
	else if (l -> prior > r -> prior)
		merge(l -> r, l -> r, r), T = l;
	else
		merge(r -> l, l, r -> l), T = r;
	upd(T);
}

pItem T = nullptr;

int n;
int a[200001];

void insert(pItem &T, pItem cur, int pos) {
	pItem T1, T2;	
	split(T, pos - 1, T1, T2); 
	merge(T, T1, cur);
	merge(T, T, T2);
}

int find_val(pItem T, int val, int add = 0) {
	if (!T)
		return 1e9; // This means that you're fuked
	push(T);
	int cur_key = add + cnt(T -> l);
	if (T -> val == val) return cur_key;
	else {
		if (val == mn(T -> l)) return find_val(T -> l, val, add);
		else return find_val(T -> r, val, add + cnt(T -> l) + 1);
	}			
}

void output(pItem T) {
	if (!T) return;
	output(T -> l);
	cout << T -> val << '\n';
	output(T -> r);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pItem cur = new Item(a[i]);
		insert(T, cur, i);
	}
	vector<ii> ans;
	for (int i = 0; i < n; i++) {	
		pItem T1, T2, T3;
		split(T, i - 1, T1, T2);
		int pos = find_val(T2, i + 1) + i;
		merge(T, T1, T2);
		if (i == pos) continue;
		int l = i, r = pos;
		ans.push_back(ii(l, r));
		split(T, l - 1, T1, T2);
		split(T2, r - l, T2, T3);

		T2 -> rev = true;
		merge(T, T1, T2);
		merge(T, T, T3);
	}
	cout << ans.size() << '\n';
	for (auto& [u, v] : ans)
		cout << u + 1 << ' ' << v + 1 << '\n';
}