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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    ll k;
    cin >> k;
    vector<ll> b(k);
    for (ll &i : b) cin >> i;
    vector<pair<ll, ll>> breaks;
    for (ll i = 0; i < n; ++i) {
        ll t = a[i];
        ll p = 1;
        while (t % m == 0) {
            t /= m;
            p *= m;
        }
        breaks.push_back({t, p});
    }
    vector<pair<ll, ll>> n_breaks = {breaks[0]};
    for (ll i = 1; i < n; ++i) {
        if (n_breaks.back().first == breaks[i].first)
            n_breaks.back().second += breaks[i].second;
        else
            n_breaks.push_back(breaks[i]);
    }
    reverse(all(n_breaks));
    dbg(n_breaks);
    for (ll i = 0; i < k; ++i) {
        if (n_breaks.empty()) return void(cout << "No\n");
        auto &f = n_breaks.back();
        if (b[i] % f.first) return void(cout << "No\n");
        ll occ = b[i] / f.first;
        dbg(occ);
        ll t = occ;
        while (t % m == 0) t /= m;
        if (occ > f.second || t != 1) return void(cout << "No\n");
        f.second -= occ;
        if (f.second == 0) n_breaks.pop_back();
    }
    dbg(n_breaks);
    if (!n_breaks.empty()) return void(cout << "No\n");
    cout << "Yes\n";
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
