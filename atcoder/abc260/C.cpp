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
    ll n, x, y;
    cin >> n >> x >> y;
    queue<pair<char, pair<ll, ll>>> bfs;
    bfs.push({'R', {n, 1}});
    ll ans = 0;
    while (!bfs.empty()) {
        auto [col, _] = bfs.front();
        auto [lev, cnt] = _;
        bfs.pop();
        if (lev == 1) {
            if (col == 'B') ans += cnt;
            continue;
        }
        assert(lev >= 2);
        if (col == 'B') {
            bfs.push({'R', {lev - 1, cnt}});
            bfs.push({'B', {lev - 1, y * cnt}});
        } else {
            bfs.push({'R', {lev - 1, cnt}});
            bfs.push({'B', {lev, x * cnt}});
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
