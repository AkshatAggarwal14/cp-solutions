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

vector<vector<ll>> adj, adj_rev;
vector<ll> used;
vector<ll> order, component;

void dfs1(ll v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(ll v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

void test() {
    // find cycles in directed graph
    // find sum of minimum weight in a cycle
    ll n;
    cin >> n;
    adj.resize(n), adj_rev.resize(n);
    vector<ll> val(n);
    for (ll i = 0; i < n; ++i) {
        ll u;
        cin >> u, --u;
        adj[i].push_back(u);
        adj_rev[u].push_back(i);
    }
    for (ll &i : val) cin >> i;
    // find SCC for each component
    used.assign(n, false);

    for (ll i = 0; i < n; i++)
        if (!used[i]) dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    ll ans = 0;
    for (auto v : order) {
        if (!used[v]) {
            dfs2(v);
            if (sz(component) > 1) {
                ll mini = INF;
                for (auto &u : component)
                    mini = min(mini, val[u]);
                ans += mini;
            }
            dbg(component);
            // ... processing next component ...

            component.clear();
        }
    }
    cout << ans << '\n';
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
