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
    vector<vector<ll>> g(n), ans(n, vector<ll>(20));
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto add = [&](ll index, ll value) {
        if (sz(ans[index]) < 20) {
            ans[index].push_back(value);
        } else {
            ll mini = *min_element(all(ans[index]));
            if (mini < value) {
                ans[index].erase(find(all(ans[index]), mini));
                ans[index].push_back(value);
            }
        }
    };

    // add children's ans to parents + add parent itself
    auto dfs = [&](const auto &self, ll node, ll parent = -1) -> void {
        add(node, x[node]);
        for (ll &child : g[node]) {
            if (child == parent) continue;
            self(self, child, node);
            for (auto &&res : ans[child]) add(node, res);
        }
    };
    dfs(dfs, 0);
    for (ll i = 0; i < n; ++i) sort(all(ans[i]), greater<ll>());
    while (q--) {
        ll v, k;
        cin >> v >> k, --v, --k;
        cout << ans[v][k] << '\n';
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