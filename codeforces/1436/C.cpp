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

ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}

// a**(p - 1) % p == 1
// a*(a**(p - 2)) % p == 1
// a**(p - 2) % p == 1 / a
ll inverse(ll a, ll m = MOD) { return modpow(a, m - 2, m); }  // Fermats little theorem

ll fact(ll n) {
    ll p = 1;
    for (ll i = 2; i <= n; ++i) {
        p *= i;
        p %= MOD;
    }
    return p;
};

ll ncr(ll n, ll r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    ll res = fact(n);
    res *= inverse(fact(r));
    res %= MOD;
    res *= inverse(fact(n - r));
    res %= MOD;
    return res;
}

void test() {
    ll n, x, pos;
    cin >> n >> x >> pos;
    auto simulate = [&]() -> pair<ll, ll> {
        ll less = 0, greater = 0;
        ll l = 0, r = n;
        while (l < r) {
            ll m = (l + r) / 2;
            if (m < pos) ++less;
            if (m > pos) ++greater;
            if (m <= pos) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return {less, greater};
    };
    auto C = simulate();
    ll larger = n - x;
    ll smaller = x - 1;
    ll ans = 1;
    (ans *= ncr(larger, C.second)) %= MOD;  // ways to choose greater elems
    (ans *= fact(C.second)) %= MOD;         // relative ordering of greater elems

    (ans *= ncr(smaller, C.first)) %= MOD;  // ways to choose smaller elems
    (ans *= fact(C.first)) %= MOD;          // relative ordering of smaller elems

    ll left = n - (1 + C.first + C.second);  // left! = ways to order other elems
    cout << (ans * fact(left)) % MOD << '\n';
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
