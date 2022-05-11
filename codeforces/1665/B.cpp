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
    map<ll, ll> cnt;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++cnt[x];
    }
    ll maxi = 0;
    for (auto &[x, y] : cnt) maxi = max(maxi, y);
    dbg(maxi);
    ll swaps = n - maxi;
    ll ops = 0;
    while (maxi < n) maxi *= 2, ++ops;
    cout << ops + swaps << '\n';
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
