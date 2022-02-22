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
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll &A : arr) cin >> A;
    vector<ll> maxi(n + 1, -INF);
    for (ll i = 0; i < n; i++) {
        ll sum = 0;
        for (ll j = i; j < n; j++) {
            sum += arr[j];
            maxi[j - i + 1] = max(maxi[j - i + 1], sum);
        }
    }
    for (ll i = 0; i <= n; i++) {
        ll ans = 0;
        for (ll j = 1; j <= n; j++)
            ans = max(ans, maxi[j] + (min(i, j) * x));
        cout << ans << ' ';
    }
    cout << '\n';
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