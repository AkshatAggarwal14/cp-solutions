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
    ll n;
    cin >> n;
    vector<ll> q(n);
    auto ask = [&]() -> ll {
        cout << "? ";
        for (ll &x : q) cout << x << ' ';
        cout << endl;
        ll k;
        cin >> k;
        return k - 1;
    };
    vector<ll> P(n, -1);
    // find last element first and use it to find all others
    for (ll i = 1; i <= n; ++i) {
        if (i == n) {
            P[n - 1] = n;
            break;
        }
        fill(all(q), i);
        q[n - 1] = n;
        ll id = ask();
        if (id != -1) {
            P[n - 1] = i;
            break;
        }
    }
    for (ll i = 0; i < n && count(all(P), -1); ++i) {
        fill(all(q), P[n - 1]);
        q[n - 1] = i + 1;
        ll id = ask();
        if (id == -1) continue;
        P[id] = i + 1;
    }
    dbg(P);
    cout << "! ";
    for (ll &x : P) cout << x << ' ';
    cout << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}