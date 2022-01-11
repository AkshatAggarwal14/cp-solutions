#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

template <class T>
struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T &t) { payload.push_back(t); }
    T &front() { return payload[pos]; }
    void clear() { payload.clear(), pos = 0; }
    void pop() { pos++; }
};

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    for (auto &[u, v, w] : edges) cin >> u >> v >> w, --u, --v;
    vector<bool> vis(n, false);
    vector<basic_string<ll>> g(n);
    // to check connected
    auto connected = [&](const vector<array<ll, 3>> &Edges) -> bool {
        for (auto &x : g) x.clear();  // faster
        for (const auto &[u, v, w] : Edges) g[u].push_back(v), g[v].push_back(u);
        fill(all(vis), false);
        simple_queue<ll> bfs;
        bfs.push(0);
        vis[0] = true;
        while (!bfs.empty()) {
            ll node = bfs.front();
            bfs.pop();
            for (ll &child : g[node]) {
                if (vis[child]) continue;
                vis[child] = true;
                bfs.push(child);
            }
        }
        return (count(all(vis), true) == n);
    };

    ll ans = 0;
    // go bitwise from highest to lowest to reduce OR
    for (ll bit = 29; bit >= 0; --bit) {
        vector<array<ll, 3>> n_edges;
        // remove edges with w & (1LL << bit)
        for (auto &[u, v, w] : edges)
            if (!(w & (1 << bit))) n_edges.push_back({u, v, w});
        if (connected(n_edges)) {
            edges = n_edges;  // removed
        } else {
            ans |= (1 << bit);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}