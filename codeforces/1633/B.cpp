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
    function<ll(string)> solve = [&](string S) {
        ll c0 = count(all(S), '0');
        ll c1 = count(all(S), '1');
        if (c0 == 0 || c1 == 0 || S == "01" || S == "10") return 0LL;
        if (c0 == c1) {
            string s1 = S.substr(1);
            string s2 = S.substr(0, sz(S) - 1);
            return max(solve(s1), solve(s2));
        } else {
            return min(c0, c1);
        }
    };
    cout << solve(s) << '\n';
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