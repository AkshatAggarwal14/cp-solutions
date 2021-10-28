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

void Solution() {
    ll n, m, k, u, v;
    auto get = [&](ll x, ll y) -> ll { return x * m + y; };
    queue<ll> bfs;
    cin >> n >> m >> k;
    vector<vector<ll>> dist(n, vector<ll>(m, -1));
    for (ll i = 0; i < k; ++i) {
        cin >> u >> v;
        bfs.push(get(u - 1, v - 1));  // pushing initial for multisource bfs
        dist[u - 1][v - 1] = 0;
    }
    ll dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    ll d = 0, mx = -1, my = -1;
    while (!bfs.empty()) {
        ll x = bfs.front() / m, y = bfs.front() % m;
        bfs.pop();
        for (ll i = 0; i < 4; ++i) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
            if (dist[nx][ny] != -1) continue;
            bfs.push(get(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
        }
        if (dist[x][y] >= d) d = dist[x][y], mx = x, my = y;
    }
    dbg(dist);
    cout << mx + 1 << ' ' << my + 1 << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solution();
    return 0;
}