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

int lenOfLongSubarr(vector<int> &arr, int n, int k) {
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k)
            maxLen = i + 1;
        if (um.find(sum) == um.end())
            um[sum] = i;
        if (um.find(sum - k) != um.end()) {
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }
    return maxLen;
}

void test() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    if (accumulate(all(a), 0) < s)
        cout << -1 << '\n';
    else
        cout << n - lenOfLongSubarr(a, n, s) << '\n';
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
