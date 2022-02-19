#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n, q;
    cin >> n >> q;
    vector<ll> x(n);
    for (ll &X : x) cin >> X;
    vector<vector<ll>> g(n);
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<multiset<ll>> vals(n);  // 20 atmax in each

    auto add = [&](ll id, ll value) {
        if (sz(vals[id]) < 20)
            vals[id].insert(value);
        else {
            ll mini = *vals[id].begin();
            if (value > mini) {
                vals[id].erase(mini);
                vals[id].insert(value);
            }
        }
    };

    auto dfs = [&](const auto &self, ll node, ll parent = -1) -> void {
        add(node, x[node]);
        for (ll &child : g[node]) {
            if (child == parent) continue;
            self(self, child, node);
            for (auto &&res : vals[child]) {
                add(node, res);
            }
        }
    };
    dfs(dfs, 0);
    dbg(vals);

    while (q--) {
        ll v, k;
        cin >> v >> k, --v, --k;
        auto it = vals[v].begin();
        for (ll i = 0; i < sz(vals[v]) - 1 - k; ++i) it = next(it);
        cout << *it << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}