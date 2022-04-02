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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    ll sum = 0;
    for (ll &A : a) cin >> A, sum += A;
    ll cnt = 0;
    for (ll &A : a) cnt += A / x;
    sort(all(a), [&](const ll &A, const ll &B) { return A % x > B % x; });
    if (k >= cnt) {
        k -= cnt;
        ll ans = 0;
        for (ll i = k; i < n; ++i) {
            ans += (a[i] % x);
        }
        cout << ans << '\n';
    } else {
        cout << sum - k * x << '\n';
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
