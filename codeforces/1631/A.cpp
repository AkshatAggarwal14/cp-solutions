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
    vector<ll> a(n), b(n);
    for (ll &A : a) cin >> A;
    for (ll &B : b) cin >> B;
    ll mx_a = *max_element(all(a));
    ll mx_b = *max_element(all(b));
    if (mx_b > mx_a) swap(a, b), swap(mx_a, mx_b);
    for (ll i = 0; i < n; ++i) {
        if (a[i] == mx_a) continue;
        if (b[i] > a[i]) swap(a[i], b[i]);
    }
    dbg(a, b);
    cout << (*max_element(all(a))) * (*max_element(all(b))) << '\n';
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