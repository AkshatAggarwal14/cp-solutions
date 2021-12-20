#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const ll N = 2e5;
const ll MOD = 998244353;
ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
array<ll, N + 1> fact;
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
ll inv(ll a, ll m = MOD) { return modpow(a, m - 2, m); }  //Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}
ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv(fact[b], MOD)), inv(fact[a - b], MOD));
}

int main() {
    init();
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, c, x;
    cin >> n >> c >> x;
    ll ans = 0;
    for (ll i = 0; i <= x; ++i)
        ans = add(ans, mul(mul(c, C(n - 1, i)), modpow(c - 1, n - i - 1, MOD)));
    cout << ans << '\n';

    return 0;
}