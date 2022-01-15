#include <bits/stdc++.h>

using namespace std;

#define int long long

// Template FFT

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

// For a fixed K only:
// Count numbers of pair (l, r) that psum[r] - psum[l] == K
// Let cnt[i] be the numbers of psum[pos] such that psum[pos] = i
// For a pair (l, r) that r - l = K, add to result cnt[r] * cnt[l]
// Or in other words, r + (-l) = k, add cnt[r] * cnt[l] => Convolution => FFT stuff
// Special case K = 0 :cheems:

string s;

int psum[200001], cnt[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s; int n = s.size();

	cnt[0]++;
	for (int i = 0; i < n; i++) {
		int val = s[i] - '0';
		psum[i] = (i > 0 ? psum[i - 1] + val : val);
		cnt[psum[i]]++;
	}

	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i <= n; i++) a[i] = cnt[i];
	for (int i = 0; i <= n; i++) b[i] = cnt[n - i];
	vector<int> c = multiply(a, b);

	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += cnt[i] * (cnt[i] - 1) / 2;
	cout << sum << ' ';	
	for (int i = n + 1; i <= 2 * n; i++)
		cout << c[i] << ' ';
}