#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct Matrix {
    static const ll M = MOD;
    static const ll SQMOD = M * M;
    static ll const N = 52;
    ll mat[N][N];
    ll n, m;
    Matrix(ll _n = N, ll _m = N, ll val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    Matrix(const vector<vector<ll>> &&other) {
        n = ll(other.size());
        m = ll(other[0].size());
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = other[i][j];
    }
    Matrix &operator=(const vector<vector<ll>> &&other) {
        return *this = Matrix(forward<decltype(other)>(other));
    }
    ll *operator[](ll r) { return mat[r]; }
    const ll *operator[](ll r) const { return mat[r]; }
    static Matrix unit(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    Matrix &operator+=(const Matrix &rhs) {
        assert(n == rhs.n && m == rhs.m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j) {
                mat[i][j] += rhs[i][j];
                if (mat[i][j] >= M) mat[i][j] -= M;
            }
        return *this;
    }
    Matrix operator+(const Matrix &rhs) const {
        Matrix lhs(*this);
        return lhs += rhs;
    }
    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.m == B.n);
        Matrix res(A.n, B.m);
        for (ll i = 0; i < res.n; i++)
            for (ll j = 0; j < res.m; j++) {
                ll sum = 0LL;
                for (ll k = 0; k < A.m; k++) {
                    sum += A[i][k] * B[k][j];
                    if (sum >= SQMOD) sum -= SQMOD;
                }
                res[i][j] = (sum % M);
            }
        return res;
    }
    friend Matrix power(Matrix base, long long ex) {
        assert(base.n == base.m);
        Matrix res = Matrix::unit(base.n);
        while (ex > 0) {
            if (ex & 1) res = res * base;
            base = base * base;
            ex >>= 1;
        }
        return res;
    }
    friend string to_string(const Matrix &a) {
        string res = "\n";
        for (ll i = 0; i < a.n; ++i) {
            res += '{';
            for (ll j = 0; j < a.m; ++j) {
                res += std::to_string(a.mat[i][j]);
                if (j != a.m - 1) res += ", ";
            }
            res += "}\n";
        }
        res.append("\n");
        return res;
    }
    Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    /*
    3 3 2
    ab
    ba

    we cant have b after a, and a after b
    a[i] = a[i - 1] + c[i - 1]
    b[i] = b[i - 1] + c[i - 1]
    c[i] = a[i - 1] + b[i - 1] + c[i - 1] <- mark all 1s and then remove for each pair
    */
    ll n, m, k;
    cin >> n >> m >> k;
    Matrix Base(m, m, 1), Transform(m, 1, 1);
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        int prev = ((s[0] >= 'a') ? (s[0] - 'a') : (s[0] - 'A' + 26));
        int now = ((s[1] >= 'a') ? (s[1] - 'a') : (s[1] - 'A' + 26));
        Base[now][prev] = 0;
    }
    Matrix ans = power(Base, n - 1) * Transform;
    ll res = 0;
    for (int i = 0; i < m; ++i) (res += ans[i][0]) %= MOD;
    cout << res << '\n';
}