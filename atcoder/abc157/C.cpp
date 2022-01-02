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
    ll N, M;
    ll s;
    char c;
    cin >> N >> M;
    string ans(N, '.');
    while (M--) {
        cin >> s >> c, --s;
        if (ans[s] != '.' and c != ans[s]) return void(cout << "-1\n");
        ans[s] = c;
    }
    dbg(ans);
    for (ll i = 0; i <= 999; ++i) {
        string S = to_string(i);
        if (sz(S) != N) continue;
        if (sz(S) > N) break;
        bool flag = true;
        for (ll j = 0; j < sz(S); ++j)
            if (ans[j] != '.' and S[j] != ans[j]) flag = false;
        if (flag) return void(cout << i << '\n');
    }
    cout << "-1\n";
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