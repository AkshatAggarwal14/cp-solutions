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
    ll n, m, l, r, x;
    cin >> n >> m;
    set<ll> st;
    vector<ll> ans(n, -1);
    for (ll i = 1; i <= n; ++i) st.insert(i);
    for (ll i = 0; i < m; ++i) {
        cin >> l >> r >> x;
        auto it = st.lower_bound(l);
        while (it != st.end() && *it <= r) {
            ans[*it - 1] = x;
            st.erase(*it);
            it = st.lower_bound(l);
        }
        st.insert(x);
        ans[x - 1] = 0;
    }
    for (auto &X : ans) cout << X << ' ';
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