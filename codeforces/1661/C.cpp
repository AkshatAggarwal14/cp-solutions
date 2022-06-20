/**
 *    author:  master._.mind
 *    created: 2022.06.21 00:19:35
 **/

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
    for (auto &i : a) cin >> i;
    auto solve_for = [&](ll mx) {
        vector<ll> cnt(3, 0);
        for (ll i = 0; i < n; ++i) {
            ll diff = mx - a[i];
            cnt[2] += diff / 2;
            cnt[1] += diff % 2;
        }
        ll L = 1, R = cnt[2] - cnt[1];
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (cnt[2] - M + 1 >= cnt[1] + 2 * M) {
                L = M;
            } else {
                R = M;
            }
        }
        cnt[2] -= L;
        cnt[1] += 2 * L;
        if (cnt[1] > cnt[2]) return 2 * cnt[1] - 1;
        if (cnt[1] == cnt[2]) return 2 * cnt[1];
        return 2 * cnt[2];
    };
    ll maxi = *max_element(all(a));
    cout << min(solve_for(maxi), solve_for(maxi + 1)) << '\n';
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
