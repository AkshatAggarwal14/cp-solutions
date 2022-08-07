#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    array<ll, 5> a;
    for (auto &A : a) cin >> A;
    sort(all(a));
    bool x = (a[0] == a[1] && a[1] != a[2] && a[2] == a[3] && a[3] == a[4]);
    reverse(all(a));
    bool y = (a[0] == a[1] && a[1] != a[2] && a[2] == a[3] && a[3] == a[4]);
    if (x || y)
        cout << "Yes\n";
    else
        cout << "No\n";
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
