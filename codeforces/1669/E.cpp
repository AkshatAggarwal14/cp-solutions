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
    vector<string> a(n);
    map<string, ll> cnt;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    set<string> used;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        string &s = a[i];
        if (used.count(a[i])) continue;
        used.insert(a[i]);
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                string t = "";
                t += c1;
                t += c2;
                if (cnt.count(t))
                    if ((s[0] == c1) ^ (s[1] == c2)) ans += cnt[s] * cnt[t];
            }
        }
    }
    cout << ans / 2 << '\n';
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
