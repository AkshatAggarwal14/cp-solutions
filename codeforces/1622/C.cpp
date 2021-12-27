#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

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

void Solution() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), pref(n, 0);
    for (ll &A : a) cin >> A;
    sort(all(a));
    partial_sum(all(a), pref.begin());
    ll steps = LLONG_MAX;
    for (ll i = n - 1; i >= 0; --i) {
        ll sum_before = pref[i] - a[0];  // sum of elements before & including i except a[0]
        ll left_sum = k - sum_before;    // sum left so total <= k
        ll to_make = min(a[0], ll(floor(double(left_sum) / double((n - i)))));
        // reduce minimum element to some value and set all n - i - 1 to that value = number of step
        amin(steps, (a[0] - to_make) + (n - i - 1));
    }
    cout << steps << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}