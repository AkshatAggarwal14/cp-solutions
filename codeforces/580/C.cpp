#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
const ll inf = LLONG_MAX;

void Solution() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<ll> is_cat(n);
    for (ll i = 0; i < n; ++i) cin >> is_cat[i];
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    ll ans = 0;
    function<void(ll, ll, ll)> dfs = [&](ll node, ll parent, ll cnt) {
        if (cnt > m) return;
        if (sz(g[node]) == 1 && node != 0) {
            ans++;
            return;
        }
        for (auto &child : g[node]) {
            if (child != parent) {
                if (is_cat[child]) {
                    dfs(child, node, cnt + 1);
                } else {
                    dfs(child, node, 0);
                }
            }
        }
    };
    dfs(0, -1, is_cat[0]);
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}