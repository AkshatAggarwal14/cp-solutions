#include "bits/stdc++.h"
using namespace std;

using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll INF = 1e18;
const ll M = 2e5 + 5;

// dp[dig][x][i] is count of digit `i` after `x` moves on digit `dig`
vector<vector<vector<ll>>> dp;
const ll MOD = 1e9 + 7;
void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> cnt_digits(10, 0);
    while (n) {
        ++cnt_digits[n % 10];
        n /= 10;
    }
    vector<ll> ans(10, 0);
    for (ll i = 0; i < 10; ++i) {
        for (ll j = 0; j < 10; ++j) {
            ans[j] = (ans[j] + cnt_digits[i] * dp[i][m][j]) % MOD;
        }
    }
    ll res = 0;
    for (ll i = 0; i < 10; ++i) res = (res + ans[i]) % MOD;
    cout << res << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<ll> temp(10, 0);
    dp.resize(10, vector<vector<ll>>(M + 1, vector<ll>(10, 0)));
    // preprocess answer for 1, 2, 3, 4, 5,.. 9 for all 1 <= m <= 2e5, then use it to calculate total answer per digit in input
    for (ll digit = 0; digit <= 9; ++digit) {
        dp[digit][0][digit] = 1;  // on 0 moves, only the digit itself is set
        for (ll move_number = 1; move_number <= M; ++move_number) {
            for (ll i = 0; i <= 9; ++i) temp[i] = 0;
            for (ll i = 0; i <= 9; ++i) {
                ll next = i + 1;
                while (next) {
                    ll last = next % 10;
                    temp[last] += dp[digit][move_number - 1][i] % MOD;
                    if (temp[last] > MOD) temp[last] -= MOD;
                    next /= 10;
                }
            }
            swap(temp, dp[digit][move_number]);  // update the next state from previous
        }
    }

#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}