#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 3010;
const ll MOD = 1e9 + 7;  // 998244353
void test() {
    vector<bitset<N>> v(N);
    ll n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (ll j = 0; j < n; ++j) {
            grid[i][j] = (s[j] == '1');
        }
        v[i] = bitset<N>(s);
    }
    vector<bitset<N>> use(N);
    use.back().set();
    for (ll i = N - 2; i >= 0; --i) {
        use[i] = (use[i + 1] >> 1);
    }
    // dbg(use, v);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            if (grid[i][j]) {
                ll id = (n - (j + 1));
                if (id != 0) {
                    auto X = use[id - 1];
                    X &= (v[i] & v[j]);
                    // dbg(X, id, i, j);
                    ans += X.count();
                }
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
