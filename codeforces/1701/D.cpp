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
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n;
    cin >> n;
    vector<ll> b(n);
    vector<array<ll, 3>> LR(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        ll id = i + 1;
        ll L = 1, R = n;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (id / M <= b[i]) {
                R = M;
            } else {
                L = M;
            }
        }
        LR[i][0] = R;
        L = 1, R = n;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (id / M >= b[i]) {
                L = M;
            } else {
                R = M;
            }
        }
        LR[i][1] = L;
        LR[i][2] = i;
    }
    set<ll> unvis;
    for (ll i = 1; i <= n; ++i) unvis.insert(i);
    sort(all(LR), [](const auto &i, const auto &j) {
        return i[1] < j[1];
    });
    vector<ll> ans(n, -1);
    for (auto &[L, R, i] : LR) {
        auto it = unvis.lower_bound(L);
        assert(it != unvis.end() and *it <= R);
        ans[i] = *it;
        unvis.erase(it);
    }
    for (ll &i : ans) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
