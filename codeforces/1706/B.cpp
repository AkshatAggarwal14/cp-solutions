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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> pos(n + 1);
    for (ll i = 0; auto &A : a) cin >> A, pos[A].push_back(i++);
    for (ll i = 1; i <= n; ++i) {
        ll cnt = 1;
        if (pos[i].empty()) cnt = 0;
        for (ll j = 1; j < sz(pos[i]); ++j) {
            if ((pos[i][j] - pos[i][j - 1]) & 1) ++cnt;
        }
        cout << cnt << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
