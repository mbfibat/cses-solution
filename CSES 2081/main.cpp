#include <bits/stdc++.h>

using namespace std;

int n, k1, k2;
vector<int> adj[200001];



int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k1 >> k2;
	for (int i = 1, u, v; i <= n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	decompose(1, -1);
}