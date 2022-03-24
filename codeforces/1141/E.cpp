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

const ll INF = 1e12 + 5;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, H;
    cin >> H >> n;
    vector<ll> d(n);
    ll sum = 0, most_neg = 0;
    for (ll i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        most_neg = min(most_neg, sum);
    }
    if (H + most_neg > 0 && sum >= 0)
        cout << "-1\n";
    else {
        ll ans, steps;
        steps = ll(max(0.0L, floor((-1.0L * ((H + most_neg)) / double(sum)))));
        ans = steps * n;
        H += steps * sum;
        ll i = 0;
        while (H > 0) ans++, H += d[(i++ % n)];
        cout << ans;
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
