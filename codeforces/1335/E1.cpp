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
const ll N = 26;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<vector<ll>> pos(N + 1), pref(N + 1, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
        pref[a[i]][i] = 1;
    }
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 1; j < n; ++j) {
            pref[i][j] += pref[i][j - 1];
        }
    }
    auto count_of = [&](ll value, ll L, ll R) -> ll {
        // between L and R
        L++, R--;
        if (L > R) return 0LL;
        return pref[value][R] - pref[value][L - 1];
    };
    ll best = 1;
    for (ll A = 1; A <= N; ++A) {
        ll l = 0, r = sz(pos[A]) - 1;
        ll ans = 1;
        while (l < r) {
            for (ll B = 1; B <= N; ++B) {
                ll y = count_of(B, pos[A][l], pos[A][r]);
                if (y > 0 || (B == A)) amax(ans, 2 * (l + 1) + y);
            }
            ++l, --r;
        }
        amax(best, ans);
    }
    cout << best << '\n';
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