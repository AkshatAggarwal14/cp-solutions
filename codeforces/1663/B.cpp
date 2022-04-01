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
    if (n < 1200)
        cout << 1200;
    else if (n < 1400)
        cout << 1400;
    else if (n < 1600)
        cout << 1600;
    else if (n < 1900)
        cout << 1900;
    else if (n < 2100)
        cout << 2100;
    else if (n < 2300)
        cout << 2300;
    else if (n < 2400)
        cout << 2400;
    else if (n < 2600)
        cout << 2600;
    else if (n < 3000)
        cout << 3000;
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
