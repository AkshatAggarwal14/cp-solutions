#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

using ll = long long;
#define int ll
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll INF = 1e18;
const ll M = 2e5 + 5;

vector<vector<vector<int>>> real_count(10, vector<vector<int>>(M + 1, vector<int>(10, 0)));
const int MOD = 1e9 + 7;
void Solution() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(10, 0);
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
    vector<int> ans(10, 0);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans[j] = (ans[j] + (cnt[i] % MOD) * (real_count[i][m][j] % MOD)) % MOD;
        }
    }
    ll res = 0;
    for (ll i = 0; i < 10; ++i) res = (res + ans[i]) % MOD;
    cout << res << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> temp(10, 0);
    // preprocess answer for 1, 2, 3, 4, 5,.. 9 for all 1 <= m <= 2e5, then use it to calculate total answer per digit in input
    for (int digit = 0; digit <= 9; ++digit) {
        real_count[digit][0][digit] = 1;
        for (int mm = 1; mm <= M; ++mm) {
            for (int i = 0; i <= 9; ++i) temp[i] = 0;
            for (int i = 0; i <= 9; ++i) {
                for (char &c : to_string(i + 1)) {
                    temp[c - '0'] =
                        (temp[c - '0'] + real_count[digit][mm - 1][i]) % MOD;
                }
            }
            swap(temp, real_count[digit][mm]);
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