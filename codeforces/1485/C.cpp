#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto& container) -> ll { return container.size(); };

template <bool b>
auto binsearch(auto l, auto r, const auto& pred) {
    --l, ++r;
    for (decltype(l) m; m = midpoint(l, r), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}

// returns first i in [l, r], p(i) false, and if none found, returns r + 1
auto find_first_false(auto l, auto r, const auto& p) {
    return binsearch<false>(l, r, p);
}

// returns last i in [l, r], p(i) true, and if none found, returns l - 1
auto find_last_true(auto l, auto r, const auto& p) {
    return binsearch<true>(l, r, p);
}

void Solution() {
    ll x, y;
    cin >> x >> y;
    ll full = min(ll(sqrt(x + 1)), y);
    ll ans = (full * (full - 1)) / 2;
    ll max_x = min(x, y * y - 1);
    ll max_y = min(y, max_x - 1);
    vector<array<ll, 2>> vals;
    //  cnt = count of vals of x for a particular y
    for (ll cnt = 1; cnt * cnt - 1 < (ll)1e9; ++cnt) {
        ll xx = find_last_true(2LL, max_y, [&](ll yy) -> bool { return (max_x / (yy + 1) >= cnt); });
        if (xx <= cnt + 1) break;
        vals.push_back({xx, cnt});
        // cout << xx << ' ' << cnt << '\n';
    }
    vals.push_back({full, full - 1});
    dbg(ans, full);
    dbg(vals);
    for (ll i = 0; i < sz(vals) - 1; ++i) {
        ans += (vals[i][0] - vals[i + 1][0]) * vals[i][1];
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}