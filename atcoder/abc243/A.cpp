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
    ll v, a, b, c;
    cin >> v >> a >> b >> c;
    v %= (a + b + c);
    if (a > v) return void(cout << "F");
    if (a + b > v) return void(cout << "M");
    cout << "T";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cout.rdbuf(cout.rdbuf()), std::cin.rdbuf(cin.rdbuf());
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
