#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;
// works only for idempotent functions f(a, a) = a
// Updates not supported
template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    int N, K;
    vector<vector<T>> st;
    vector<int> LOG;
    U op;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(int(arr.size())), K(__lg(N)), op(OP) {
        st.resize(N, vector<T>(K + 1));
        LOG.resize(N + 1);
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(int L, int R) {
        if (L > R) return T();
        int j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void Solution() {
    map<int, ll> cnt;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    Sparse_Table<int> st(a, [](int A, int B) { return gcd(A, B); });

    for (int i = 0; i < n; ++i) {
        // gcd decreases as we move right
        // T T F F F -> gcd(0, m) >= a[0]
        // for each i, we find last a[i], such that gcd(i, x) is equal to a[i] to find its count
        for (int last = i; last < n;) {
            // last index for given val
            int l = last, r = n - 1;
            ll count = 1;
            --l, ++r;
            while (r > l + 1) {
                int m = l + (r - l) / 2;
                if (st.query(i, m) >= st.query(i, last)) {
                    l = m;
                    count = m - last + 1;
                } else {
                    r = m;
                }
            }
            cnt[st.query(i, last)] += count;
            last = l + 1;  // for each i, scan how many are equal.
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int qi;
        cin >> qi;
        cout << cnt[qi] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}