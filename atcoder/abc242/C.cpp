#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
const ll INF = 1e18;

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll cnt(ll n, ll k) {
    ll dp[11] = {0};
    ll next[11] = {0};
    for (ll i = 1; i <= 9; i++) dp[i] = 1;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= 9; j++) {
            ll l = max(1LL, (j - k));
            ll r = min(9LL, (j + k));
            next[l] += dp[j];
            next[l] %= MOD;
            next[r + 1] -= dp[j];
            next[r + 1] += MOD;
            next[r + 1] %= MOD;
        }
        for (ll j = 1; j <= 9; j++) {
            next[j] += next[j - 1];
            next[j] %= MOD;
        }
        for (ll j = 0; j < 10; j++) {
            dp[j] = next[j];
            next[j] = 0;
        }
    }
    ll count = 0;
    for (ll i = 0; i <= 9; i++) {
        count += dp[i];
        count %= MOD;
    }
    return count % MOD;
}

void Solution() {
    ll n;
    cin >> n;
    cout << cnt(n, 1) << '\n';
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