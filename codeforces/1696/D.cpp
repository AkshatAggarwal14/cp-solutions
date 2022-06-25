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

struct graph {
    int n;
    vector<vector<ll>> adj;
    vector<ll> d;
    graph(int &vertices) : n(vertices), adj(n), d(n, -1) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void bfs(ll source) {
        queue<ll> q;
        q.push(source), d[source] = 0;
        while (!q.empty()) {
            ll parent = q.front();
            q.pop();
            for (ll &child : adj[parent]) {
                if (d[child] != -1) continue;
                d[child] = d[parent] + 1;
                q.push(child);
            }
        }
    }
};

template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    ll N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(ll(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP) {
        LOG[1] = 0;
        for (ll i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (ll i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(ll L, ll R) {
        if (L > R) swap(L, R);
        ll j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> p(n);
    iota(all(p), 0LL);
    // gives minimum idx
    Sparse_Table<int> Min(p, [&](const ll &i, const ll &j) { return ((a[i] < a[j]) ? i : j); });
    // gives maximum idx
    Sparse_Table<int> Max(p, [&](const ll &i, const ll &j) { return ((a[i] > a[j]) ? i : j); });

    // {mx, mn}
    auto edge_type_1 = [&](int i) {
        int L = i, R = n - 1;
        --L, ++R;
        // find farthest L such that in [i, L] a[i] is maximum
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (i == Max.query(i, M)) {
                L = M;
            } else {
                R = M;
            }
        }
        // find index with minimum element in [i, L] and reduce it to [i, found] -> [mx, mn]
        return Min.query(i, L);
    };
    // {mn, mx}
    auto edge_type_2 = [&](int i) {
        int L = i, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (i == Min.query(i, M)) {
                L = M;
            } else {
                R = M;
            }
        }
        return Max.query(i, L);
    };
    graph g(n);
    for (int i = 0; i < n; ++i) {
        int e1 = edge_type_1(i);
        int e2 = edge_type_2(i);
        if (e1 != i) g.add_edge(i, e1);
        if (e2 != i) g.add_edge(i, e2);
    }
    g.bfs(0);
    cout << g.d[n - 1] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
