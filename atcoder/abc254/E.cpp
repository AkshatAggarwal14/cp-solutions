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

void test() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0, a, b; i < m; ++i) {
        cin >> a >> b, --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    set<ll> vis;
    queue<pair<ll, ll>> bfs;
    ll sum = 0, k, q, x;
    cin >> q;
    while (q--) {
        cin >> x >> k, --x;
        sum = 0, vis.clear();
        while (!bfs.empty()) bfs.pop();

        bfs.push({x, 0});
        vis.insert(x);
        while (!bfs.empty()) {
            auto par = bfs.front();
            bfs.pop();
            if (par.second > k) continue;
            sum += (par.first + 1);
            for (auto &it : g[par.first]) {
                if (vis.count(it)) continue;
                vis.insert(it);
                bfs.push({it, par.second + 1});
            }
        }

        cout << sum << '\n';
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
