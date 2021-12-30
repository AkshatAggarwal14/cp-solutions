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

void Solution() {
    ll n, v, a, b;
    cin >> n >> v;
    vector<ll> cnt(3003, 0);
    for (ll i = 0; i < n; ++i) cin >> a >> b, cnt[a] += b;
    ll ans = 0;
    for (ll i = 1; i <= 3001; ++i) {
        ll prev = cnt[i - 1];
        ll used = min(prev, v);
        ans += used;
        cnt[i - 1] -= used;
        ll left = cnt[i];
        used = min(left, v - used);
        cnt[i] -= used;
        ans += used;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}