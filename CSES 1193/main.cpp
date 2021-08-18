#include <bits/stdc++.h>
// borrow from a kouhai
//<(")
#define ll long long
using namespace std;
 
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
 
const ll siz = 1e3 + 10;
const ll base = 32;
const ll MAXX = 1e18;
const ll mod = 1e9 + 7;  
 
ll nX[] = {-1, 1, 0, 0};
ll nY[] = {0, 0, -1, 1};
char mov[] = {'D', 'U', 'R', 'L'};
ll n, m;
ll hold[siz][siz];
ll sub;
ii sta, en;
 
bool check(ll x, ll y) {
    return (x > 0) && (x <= n) && (y > 0) && (y <= m) && hold[x][y];
}
 
queue<iii> nxt;
ll res[siz][siz];
 
void bfs(ll x, ll y) {
    nxt.push(make_pair(0, ii(x, y)));
    res[x][y] = 0;
    while (!nxt.empty()) {
        ii pos = nxt.front().second;
        ll val = nxt.front().first;
        nxt.pop();
        if (pos == en) {
            break;
        }
        for (ll i = 0; i < 4; i++) {
            x = pos.first + nX[i];
            y = pos.second + nY[i];
            if (check(x, y)) {
            	res[x][y] = val + 1;
            	hold[x][y] = false;
                nxt.push(make_pair(val + 1, ii(x, y)));
            }
        }
    }
}
 
string str;
 
void trace(ll x, ll y, ll ans) {
    if ((x == sta.first) && (y == sta.second)) {
        return;
    }
    for (ll i = 0; i < 4; i++) {
        ll a = x + nX[i], b = y + nY[i];
        if ((a > 0) && (a <= n) && (b > 0) && (b <= m) && (res[a][b] == ans - 1)) {
            str += mov[i];
            trace(a, b, ans - 1);
            return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("INP.txt", "r", stdin);
    //freopen("OUT.txt", "w", stdout);
    cin >> n >> m; 
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == 'A') {
                sta = ii(i, j);
            }
            else if (x == 'B') {
                hold[i][j] = true;
                en = ii(i, j);
            }
            else if (x == '.') {
                hold[i][j] = true;
            }
        }
    }
    memset(res, -1, sizeof(res));
    bfs(sta.first, sta.second);
    if (res[en.first][en.second] == -1) {
        cout << "NO" << '\n';
        return 0;
    }
    // for (ll i = 1; i <= n; i++) {
        // for (ll j = 1; j <= m; j++) {
            // cerr << res[i][j] << ' ';
        // }
        // cerr << '\n';
    // }
    cout << "YES" << '\n';
    sub = res[en.first][en.second];
    cout << sub << '\n';
    trace(en.first, en.second, sub);
    reverse(str.begin(), str.end());
    cout << str << '\n';
    return 0;
}