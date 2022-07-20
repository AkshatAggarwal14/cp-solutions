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
    // speed and overtake violations are independent
    ll n;
    cin >> n;
    int violations = 0;
    int no_overtakes = 0;
    vector<int> limits;
    int type, x, curr;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        switch (type) {
            case 1:
                cin >> x;
                curr = x;
                while (!limits.empty() && limits.back() < curr)
                    limits.pop_back(), ++violations;
                break;
            case 2:
                violations += no_overtakes;
                no_overtakes = 0;
                break;
            case 3:
                cin >> x;
                limits.push_back(x);
                break;
            case 4:
                no_overtakes = 0;
                break;
            case 5:
                limits.clear();
                break;
            case 6:
                ++no_overtakes;
                break;
        }
        while (!limits.empty() && limits.back() < curr)
            limits.pop_back(), ++violations;
    }
    cout << violations << '\n';
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
