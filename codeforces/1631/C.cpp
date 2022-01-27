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
    ll n, k;
    cin >> n >> k;
    if (k == n - 1 && n == 4) return void(cout << "-1\n");  //!
    vector<ll> a, b;
    for (ll i = 0; i < n; ++i) {
        ((i < n / 2) ? a : b).push_back(i);
    }
    reverse(all(b));
    if (k == n - 1) {
        dbg(a, b);
        // 0 1 2 3
        // 7 6 5 4
        // 6 with 7, 1 with 5
        swap(a[1], b[0]);
        // 0 7 2 3
        // 1 6 5 4
        swap(b[0], a[2]);
    } else if (k < n / 2) {
        swap(a[0], a[k]);
    } else {
        swap(a[0], b[n / 2 - 1 - (k - n / 2)]);
    }
    dbg(a, b);
    ll ans = 0;
    for (ll i = 0; i < n / 2; ++i) {
        cout << a[i] << ' ' << b[i] << '\n';
        ans += ((a[i] & b[i]));
    }
    assert(ans == k);
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
        // Brute();
    }
    return 0;
}