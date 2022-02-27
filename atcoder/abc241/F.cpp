#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

void Solution() {
    ll h, w, n;
    cin >> h >> w >> n;
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    map<ll, vector<ll>> X, Y;
    for (ll i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    auto req_pair = [&](const vector<ll> &a, const ll &value) -> pair<ll, ll> {
        ll L = 0, R = sz(a) - 1;
        ll ans_L = INT_MAX, ans_R = INT_MIN;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (a[M] < value) {
                L = M;
                ans_L = a[L];
            } else {
                R = M;
                ans_R = a[R];
            }
        }
        return {ans_L, ans_R};
    };
    for (auto &[_, v] : X) sort(all(v));
    for (auto &[_, v] : Y) sort(all(v));
    map<pair<ll, ll>, ll> d;
    queue<pair<ll, ll>> bfs;
    bfs.emplace(sx, sy);
    d[{sx, sy}] = 0;
    while (!bfs.empty()) {
        auto [x, y] = bfs.front();
        bfs.pop();
        if (X.count(x)) {
            auto [L, R] = req_pair(X[x], y);
            if (L != INT_MAX && !d.count({x, L + 1})) {
                bfs.emplace(x, L + 1);
                d[{x, L + 1}] = d[{x, y}] + 1;
            }
            if (R != INT_MIN && !d.count({x, R - 1})) {
                bfs.emplace(x, R - 1);
                d[{x, R - 1}] = d[{x, y}] + 1;
            }
        }
        if (Y.count(y)) {
            auto [L, R] = req_pair(Y[y], x);
            if (L != INT_MAX && !d.count({L + 1, y})) {
                bfs.emplace(L + 1, y);
                d[{L + 1, y}] = d[{x, y}] + 1;
            }
            if (R != INT_MIN && !d.count({R - 1, y})) {
                bfs.emplace(R - 1, y);
                d[{R - 1, y}] = d[{x, y}] + 1;
            }
        }
    }
    cout << (d.count({gx, gy}) ? d[{gx, gy}] : -1) << '\n';
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