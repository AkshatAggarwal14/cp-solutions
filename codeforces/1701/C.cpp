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
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> cnt(n + 1, 0);
    ll mx = 0;
    for (ll &i : a) cin >> i, ++cnt[i], mx = max(mx, cnt[i]);
    auto can = [&](ll hours) -> bool {
        vector<ll> hours_free(n + 1);
        ll left_tasks = 0;
        ll left_2hours = 0;
        for (ll i = 1; i <= n; ++i) {
            hours_free[i] = max(hours - cnt[i], 0LL);
            left_tasks += cnt[i] - min(hours, cnt[i]);
            left_2hours += hours_free[i] / 2;
        }
        return left_tasks <= left_2hours;
    };
    ll L = 1, R = mx;
    --L, ++R;
    while (R > L + 1) {
        ll M = (R + L) / 2;
        if (can(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << '\n';
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
