#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> int { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

void Solution() {
    // code here
}

void brute() {
    ll n;
    cin >> n;
    set<ll> st;
    for (ll i = 1; i * i <= n; ++i) {
        st.insert(i * i);
    }
    for (ll i = 1; i * i * i <= n; ++i) {
        st.insert(i * i * i);
    }
    cout << sz(st) << '\n';
    // for (ll i = 1; i <= n; ++i) {
    //     ll sq = sqrt(i);
    //     ll cb = cbrt(i);
    //     if (sq * sq == i || cb * cb * cb == i) ans++;
    // }
    // cout << ans << '\n';
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
        // Solution();
        brute();
    }
    return 0;
}