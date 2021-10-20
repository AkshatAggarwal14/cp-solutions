#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<vector<vector<char>>> adj(k, vector<vector<char>>(n, vector<char>(m)));
    vector<vector<vector<ll>>> vis(k, vector<vector<ll>>(n, vector<ll>(m, 0)));
    for (ll a = 0; a < k; ++a) {
        for (ll b = 0; b < n; ++b) {
            for (ll c = 0; c < m; ++c) {
                cin >> adj[a][b][c];
            }
        }
    }
    ll x, y;
    cin >> x >> y;  // source
    x--, y--;
    array<ll, 6> dx = {1, 0, -1, 0, 0, 0};
    array<ll, 6> dy = {0, 1, 0, -1, 0, 0};
    array<ll, 6> dz = {0, 0, 0, 0, 1, -1};

    auto valid = [&](ll Z, ll X, ll Y) -> bool {
        if (Z < 0 || Z >= k || X < 0 || X >= n || Y < 0 || Y >= m) return false;
        if (vis[Z][X][Y] || adj[Z][X][Y] == '#') return false;
        return true;
    };

    ll ans = 0;
    auto dfs = [&](const auto &self, ll Z, ll X, ll Y) -> void {
        if (vis[Z][X][Y]) return;
        vis[Z][X][Y] = 1;
        ans++;
        for (ll i = 0; i < 6; ++i) {
            ll nx = X + dx[i], ny = Y + dy[i], nz = Z + dz[i];
            if (valid(nz, nx, ny)) self(self, nz, nx, ny);
        }
    };

    dfs(dfs, 0LL, x, y);
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}