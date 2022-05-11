#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

template <bool b>
auto binsearch(auto l, auto r, const auto &pred) {
    --l, ++r;
    for (decltype(l) m; m = midpoint(l, r), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}

// returns first i in [l, r], p(i) false, and if none found, returns r + 1
auto find_first_false(auto l, auto r, const auto &p) {
    return binsearch<false>(l, r, p);
}

// returns last i in [l, r], p(i) true, and if none found, returns l - 1
auto find_last_true(auto l, auto r, const auto &p) {
    return binsearch<true>(l, r, p);
}

ll query(ll l, ll r) {
    if (l >= r) return -1;
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    ll res;
    cin >> res;
    return res - 1;
}

// if position is same, then ans in this segment, else next segment.

void Solution() {
    ll n;
    cin >> n;
    ll smax = query(0, n - 1), ans = -1;
    if (smax == 0 || query(0, smax) != smax) {
        // if 0 or q[0, smax] is smaller than smax
        // it is the first index after smax then returns same res for query
        ans = find_first_false(smax, n - 2, [&](ll m) { return (query(smax, m) != smax); }) + 1;
    } else {
        // it is the largest index less than smax, where res is same as query
        ans = find_last_true(1LL, smax, [&](ll m) { return (query(m, smax) == smax); }) + 1;
    }
    cout << "! " << ans << endl;
}

// clang-format off
int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}
