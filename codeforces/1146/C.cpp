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
    auto ask = [&](ll l1, ll r1, ll l2, ll r2) {
        cout << r1 - l1 + 1 << ' ' << r2 - l2 + 1 << ' ';
        for (ll i = l1; i <= r1; ++i) cout << i << ' ';
        for (ll i = l2; i <= r2; ++i) cout << i << ' ';
        cout << endl;
        ll res;
        cin >> res;
        return res;
    };
    ll D = ask(1, 1, 2, n);
    ll l = 2, r = n;
    while (r > l) {
        ll m = (r + l) / 2;
        ll d = ask(1, 1, l, m);
        if (d != D) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    ll ans = 0;
    cout << "1 " << n - 1 << ' ' << l << ' ';
    for (ll i = 1; i <= n; ++i)
        if (i != l) cout << i << ' ';
    cout << endl;
    cin >> ans;
    cout << "-1 " << ans << endl;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
