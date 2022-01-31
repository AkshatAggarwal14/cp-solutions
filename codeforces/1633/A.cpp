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
    string s;
    cin >> s;
    ll ans = 10;
    for (ll i = 10; i <= 999; ++i) {
        if (i % 7 == 0) {
            string n = to_string(i);
            if (sz(n) == sz(s)) {
                ll cnt = 0;
                for (ll j = 0; j < sz(s); ++j) {
                    cnt += (s[j] != n[j]);
                }
                amin(ans, cnt);
            }
        }
    }
    for (ll i = 10; i <= 999; ++i) {
        if (i % 7 == 0) {
            string n = to_string(i);
            if (sz(n) == sz(s)) {
                ll cnt = 0;
                for (ll j = 0; j < sz(s); ++j) {
                    cnt += (s[j] != n[j]);
                }
                if (cnt == ans) return void(cout << n << '\n');
            }
        }
    }
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