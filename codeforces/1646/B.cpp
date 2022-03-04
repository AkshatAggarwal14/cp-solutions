#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    ll sum1 = a[n - 1], sum2 = a[0] + a[1];
    if (sum1 > sum2) return void(cout << "YES\n");
    ll i = 2, j = n - 2;
    while (i < j) {
        if (sum1 > sum2) return void(cout << "YES\n");
        sum1 += a[j];
        sum2 += a[i];
        ++i, --j;
    }
    if (sum1 > sum2) return void(cout << "YES\n");
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
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