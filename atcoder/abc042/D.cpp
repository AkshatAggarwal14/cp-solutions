#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

#define NCR
const ll N = 400200;
ll mod = 1000000007;
ll M(ll x) { return ((x % mod) + mod) % mod; }
ll add(ll x, ll y) { return (M(x) + M(y)) % mod; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % mod; }
ll f[N];
ll po(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = po(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}
ll inv(ll a, ll mod) { return po(a, mod - 2, mod); }
void init() {
    f[0] = 1;
    for (ll i = 1; i < N; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
}
ll C(ll a, ll b) {
    if (a < b) return 0;
    ll ret = mul(mul(f[a], inv(f[b], mod)), inv(f[a - b], mod));
    return ret;
}

void Solution() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    ll ans = 0;
    for (ll i = b + 1; i <= w; ++i) {
        ans = add(ans, mul(C(i + h - a - 2, h - a - 1), C(a + w - i - 1, a - 1)));
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}