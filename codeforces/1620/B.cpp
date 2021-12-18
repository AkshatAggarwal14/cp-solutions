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
    ll w, h;
    cin >> w >> h;
    ll ans = 0;
    for (ll i = 0; i < 2; ++i) {
        ll k;
        cin >> k;
        vector<ll> x(k);
        for (ll j = 0; j < k; ++j) cin >> x[j];
        ans = max(ans, (x.back() - x.front()) * h);  // area = base * height
    }
    swap(w, h);
    for (ll i = 0; i < 2; ++i) {
        ll k;
        cin >> k;
        vector<ll> x(k);
        for (ll j = 0; j < k; ++j) cin >> x[j];
        ans = max(ans, (x.back() - x.front()) * h);
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
    return 0;
}