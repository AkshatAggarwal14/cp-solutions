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

void Solution() {
    ll n, a;
    cin >> n >> a;
    vector<ll> x(n);
    fo(i, n) cin >> x[i];
    sort(x.begin(), x.end());
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    ll ans = LLONG_MAX;
    vector<pair<ll, ll>> V = {{x[0], x[n - 1]}, {x[0], x[n - 2]}, {x[1], x[n - 1]}};
    for (auto [x, y] : V) {
        ll mn = x, mx = y;
        if (a >= mn && a <= mx) {
            ans = min(ans, (mx - mn) + min(mx - a, a - mn));
        } else {
            vector<ll> vv = {mn, mx, a};
            sort(vv.begin(), vv.end());
            ans = min(ans, vv[2] - vv[0]);
        }
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