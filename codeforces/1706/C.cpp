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
    for (auto &A : a) cin >> A;
    vector<ll> cost1(n, 0), cost2(n, 0);
    for (ll i = 1; i < n - 1; ++i) {
        if (i & 1) {
            cost1[i] = max(max(a[i + 1], a[i - 1]) + 1 - a[i], 0LL);
        } else {
            cost2[i] = max(max(a[i + 1], a[i - 1]) + 1 - a[i], 0LL);
        }
    }
    for (ll i = 1; i < n; ++i) cost1[i] += cost1[i - 1];
    for (ll i = n - 2; i >= 0; --i) cost2[i] += cost2[i + 1];
    dbg(cost1, cost2);
    if (n % 2 == 0) {
        if (n >= 6) {
            // 10100101
            // 10101001
            // 10010101
            // 100101
            ll ans = min(cost1[n - 1], cost2[0]);
            for (ll i = 2; i < n - 2; i += 2) {
                ans = min(ans, cost1[i] + cost2[i + 1]);
            }
            cout << ans << '\n';
        } else {
            // only cost1 or 2 no merge
            // n - 2 = 2 here
            cout << min(cost1[1], cost2[2]) << '\n';
        }
    } else {
        cout << cost1[n - 1] << '\n';
        // only cost1
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
