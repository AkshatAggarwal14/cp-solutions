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

void Solution() {
    ll n, L, a, t, l;
    cin >> n >> L >> a;
    if (n == 0) return void(cout << L / a);
    vector<pair<ll, ll>> q(n);
    for (auto &x : q) {
        cin >> t >> l;
        x = {t, t + l};
    }
    ranges::sort(q);
    ll s = q[0].first;
    ll ans = s / a;
    for (ll i = 1; i < sz(q); ++i) {
        ll dis = q[i].first - q[i - 1].second;
        ans += dis / a;
    }
    ans += (L - q[n - 1].second) / a;
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
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}