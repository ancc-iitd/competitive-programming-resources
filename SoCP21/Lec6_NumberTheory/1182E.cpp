#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

using matrix = array<array<int, 3>, 3>;

const int M = 1e9 + 7;

int mul(ll a, int b, int m) { return a * b % m; }
int& add(int &a, int b, int m) { a += b; if (m <= a) a -= m; return a; }
int& sub(int &a, int b, int m) { a -= b; if (a < 0) a += m; return a; }

const matrix null = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
};

matrix mul(matrix a, matrix b, int m) {
    matrix c = null;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                add(c[i][j], mul(a[i][k], b[k][j], m), m);
    return c;
}

int bpow(int a, ll n, int m) {
    int res = 1;
    while (n != 0) {
        if (n & 1)
            res = mul(res, a, m);
        n >>= 1;
        a = mul(a, a, m);
    }
    return res;
}

matrix bpow(matrix a, ll n, int m) {
    matrix res = null;
    for (int i = 0; i < 3; ++i)
        res[i][i] = 1;
    
    while (n != 0) {
        if (n & 1)
            res = mul(res, a, m);
        n >>= 1;
        a = mul(a, a, m);
    }
    return res;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
  
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    matrix init = {
        1, 1, 1,
        1, 0, 0,
        0, 1, 0
    };
    matrix a = bpow(init, n - 3, M - 1);

    ll k = 3ll * a[0][0] + 2ll * a[0][1] + a[0][2] - n;
    k %= M - 1; if (k < 0) k += M - 1;

    int res = bpow(c, k, M);
    res = mul(res, bpow(f3, a[0][0], M), M);
    res = mul(res, bpow(f2, a[0][1], M), M);
    res = mul(res, bpow(f1, a[0][2], M), M);
    cout << res << '\n';
}