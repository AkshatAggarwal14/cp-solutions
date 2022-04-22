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
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<vector<ll>> segs;
    segs.emplace_back();
    segs.back().emplace_back(a[0]);
    for (ll i = 1; i < n; ++i) {
        if (a[i] != segs.back().back() + 1) segs.emplace_back();
        segs.back().emplace_back(a[i]);
    }
    vector<ll> d;
    if (sz(segs) == 1) return void(cout << "YES\n");
    if (sz(segs) >= 4) return void(cout << "NO\n");
    for (ll i = 1; i < sz(segs); ++i)
        d.push_back(segs[i].front() - segs[i - 1].back());
    dbg(segs, d);
    if (sz(d) == 1) {
        if (d[0] <= 3) return void(cout << "YES\n");
    } else if (sz(d) == 2) {
        if (d[0] == 2 && d[1] == 2) return void(cout << "YES\n");
    }
    cout << "NO\n";
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
