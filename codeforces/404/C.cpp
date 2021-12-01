#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

void Solution() {
    ll n, k, p = 1;
    cin >> n >> k;
    vector<bool> mark(n, false);
    vector<ll> d(n), cnt(n, 0), deg(n, 0);
    for (ll &x : d) cin >> x, ++cnt[x];
    ll mx = *ranges::max_element(d);
    for (ll i = 0; i < n; ++i) {
        if (!cnt[i] || p >= (ll)1e5) break;
        if (cnt[i] > p) return void(cout << "-1\n");
        mark[i] = true;
        p *= k;
    }
    vector<ll> check(d);
    sort(all(check));
    check.resize(unique(all(check)) - check.begin());
    for (ll i = 1; i < sz(check); ++i) {
        if (check[i] != check[i - 1] + 1) {
            return void(cout << "-1\n");
        }
    }
    vector<vector<ll>> avail(mx + 1);
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < n; ++i) avail[d[i]].push_back(i);
    for (ll i = 1; i <= mx; ++i) {
        ll parent = i - 1, child = i;
        if (avail[parent].empty()) break;
        for (ll j = 0; j < sz(avail[child]); ++j) {
            edges.push_back({avail[parent][j % sz(avail[parent])], avail[child][j]});
        }
    }
    if (edges.empty()) return void(cout << "-1\n");
    for (auto &[x, y] : edges) ++deg[x], ++deg[y];
    if (*ranges::max_element(deg) > k) return void(cout << "-1\n");
    cout << sz(edges) << '\n';
    for (auto &[x, y] : edges) cout << x + 1 << ' ' << y + 1 << '\n';
    dbg(edges);
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}