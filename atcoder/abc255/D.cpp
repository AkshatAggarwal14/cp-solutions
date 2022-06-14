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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), pref(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    partial_sum(all(a), pref.begin());
    while (q--) {
        ll x;
        cin >> x;
        ll id1 = -1, id2 = -1;
        // first index > x
        ll L = 0, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            ll mid = (L + R) / 2;
            if (a[mid] > x) {
                R = mid;
                id1 = mid;
            } else {
                L = mid;
            }
        }
        // last index < x
        L = 0, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            ll mid = (L + R) / 2;
            if (a[mid] < x) {
                L = mid;
                id2 = mid;
            } else {
                R = mid;
            }
        }
        ll res = 0;
        if (id2 != -1) res += (id2 + 1) * x - pref[id2];
        if (id1 != -1) res += (pref[n - 1] - ((id1 >= 1) ? pref[id1 - 1] : 0LL)) - (n - id1) * x;
        cout << res << '\n';
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
