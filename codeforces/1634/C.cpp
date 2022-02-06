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

// Al + ... + Ar = (r - l + 1) * (A_l + A_r) / 2
void Solution() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "YES\n";
        for (ll i = 1; i <= n; ++i) cout << i << '\n';
        return;
    } else if (k % 2 == 0) {
        // r - l + 1 is even here
        if (n % 2 == 0) {
            set<ll> vals;
            for (ll i = 1; i <= n * k; ++i) vals.insert(i);
            vector<vector<ll>> ans(n, vector<ll>(k));
            for (ll i = 0; i < n; ++i) {
                ans[i][0] = *vals.begin();
                vals.erase(ans[i][0]);
                for (ll j = 1; j < k; ++j) {
                    ans[i][j] = 2 + ans[i][j - 1];
                    vals.erase(ans[i][j]);
                }
            }
            cout << "YES\n";
            for (auto &x : ans) {
                for (auto &y : x) cout << y << ' ';
                cout << '\n';
            }
        } else {
            cout << "NO\n";
            // n odd, k even
        }
    } else {
        if (n % 2 == 0) {
            ll cnt = 1;
            vector<vector<ll>> ans(n, vector<ll>(k));
            for (ll j = 0; j < k; ++j) {
                for (ll i = 0; i < n; ++i) {
                    ans[i][j] = cnt++;
                }
            }
            cout << "YES\n";
            for (auto &x : ans) {
                for (auto &y : x) cout << y << ' ';
                cout << '\n';
            }
        } else {
            cout << "NO\n";
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