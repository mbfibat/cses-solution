#include <bits/stdc++.h>
 
using namespace std;
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int N = 20;
    vector<int> f(1 << N), cnt(1 << N), g(1 << N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        ++f[a[i]];
        ++g[a[i]];
    }
    for (int k = 0; k < N; ++k)
        for (int mask = 0; mask < (1 << N); ++mask)
            if (mask >> k & 1)
                f[mask] += f[mask ^ (1 << k)];
            else 
            {
            	cerr << mask << ' ' << (mask ^ (1 << k)) << '\n';
                g[mask] += g[mask ^ (1 << k)];
			}
    for (int i = 0; i < n; ++i) {
        //x | y = x -> y is subset of x
        cout << f[a[i]] << ' ';
        //x & y = x -> x is subset of y
        cout << g[a[i]] << ' ';
        //x & y != 0 
        cout << n - f[(1 << N) - 1 ^ a[i]] << '\n';
    }
    return 0;
}