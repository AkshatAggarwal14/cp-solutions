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
    vector<ll> a(n);
    ll sum = 0;
    for (ll &i : a) cin >> i, sum += i;
    if (sum & 1) return void(cout << "0\n");  // if odd cant divide into 2 parts
    // else remove one element and check

    vector<bool> dp(sum / 2 + 1);
    // dp[i] = true if we can make a subset with sum = i
    // if can never achieve half sum
    dp[0] = true;
    for (ll S = 1; S <= sum / 2; ++S) dp[S] = false;
    for (ll i = 0; i < n; ++i)
        for (ll j = sum / 2; j >= a[i]; --j)
            if (dp[j - a[i]])
                dp[j] = true;
    if (!dp[sum / 2]) return void(cout << "0\n");

    for (ll k = 0; k < n; ++k) {
        ll val = a[k];
        sum -= val;
        ll Sum = sum / 2;
        if (sum & 1) {
            cout << "1\n";
            cout << k + 1 << '\n';
            return;
        }
        // remove one element and check if sum / 2 can be reached
        dp[0] = true;
        for (ll S = 1; S <= Sum; ++S) dp[S] = false;
        for (ll i = 0; i < n; ++i)
            if (i != k)
                for (ll j = Sum; j >= a[i]; --j)
                    if (dp[j - a[i]])
                        dp[j] = true;
        if (!dp[Sum]) {
            cout << "1\n";
            cout << k + 1 << '\n';
            return;
        }

        sum += val;
    }
    cout << "1\n1\n";
    // assert(false);
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
