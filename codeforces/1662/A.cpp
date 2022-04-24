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
    ll n;
    cin >> n;
    vector<ll> mx_beauty(11, -1);
    for (ll i = 0, b, d; i < n; ++i) {
        cin >> b >> d;
        mx_beauty[d] = max(mx_beauty[d], b);
    }
    dbg(mx_beauty);
    for (ll i = 1; i <= 10; ++i)
        if (mx_beauty[i] == -1) return void(cout << "MOREPROBLEMS\n");
    cout << accumulate(1 + all(mx_beauty), 0LL) << '\n';
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
