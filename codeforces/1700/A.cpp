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
    auto get = [&](ll i, ll j) { return (i - 1) * m + j; };
    auto AP = [&](ll a, ll l, ll n_) { return (n_ * (a + l)) / 2; };
    ll ans1 = AP(get(1, 1), get(n, 1), n) + AP(get(n, 1), get(n, m), m) - get(n, 1);
    ll ans2 = AP(get(1, 1), get(1, m), m) + AP(get(1, m), get(n, m), n) - get(1, m);
    cout << min(ans1, ans2) << '\n';
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
