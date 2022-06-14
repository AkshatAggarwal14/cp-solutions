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
    for (auto &it : a) cin >> it;
    vector<vector<ll>> segs = {{1}};
    segs.emplace_back();
    for (ll i = 1; i < n; ++i) {
        if (!segs.back().empty() && segs.back().back() > a[i]) segs.emplace_back();
        segs.back().push_back(a[i]);
    }
    ll cnt = 0;
    function<void(ll, ll)> bfs = [&](ll start, ll len) {
        if (start >= sz(segs)) return;
        ll nlen = 0;
        for (ll i = start; i < start + len && i < sz(segs); ++i) nlen += sz(segs[i]);
        bfs(start + len, nlen);
        ++cnt;
    };
    bfs(1, 1);
    cout << cnt << '\n';
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
