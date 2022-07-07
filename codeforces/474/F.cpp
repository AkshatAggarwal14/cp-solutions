#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

template <class T>
class Sparse_Table {
    int N, K;
    vector<int> LOG;
    vector<vector<T>> st;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr)
        : N(int(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)) {
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = T::merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(int L, int R) {
        if (L > R) swap(L, R);
        int j = LOG[R - L + 1];
        T res = T::merge(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
    T slow_query(int L, int R) {
        T res = T();
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                res = T::merge(res, st[L][j]);
                L += (1 << j);
            }
        }
        return res;
    }
};

struct Node {
    int Gcd, cnt;
    Node() : Node(0) {}
    Node(int v) : Gcd(v), cnt(1) {}
    Node(int g, int c) : Gcd(g), cnt(c) {}
    static Node merge(const Node &i, const Node &j) {
        int g = gcd(i.Gcd, j.Gcd);
        int c = 0;
        if (i.Gcd == g) c += i.cnt;
        if (j.Gcd == g) c += j.cnt;
        return Node(g, c);
    }
};

void test() {
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        a[i] = num;
    }
    // ans[l, r] = length[l, r] - cnt[gcd[l, r]]
    Sparse_Table<Node> st(a);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r, --l, --r;
        cout << r - l + 1 - st.slow_query(l, r).cnt << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
