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

using node = pair<ll, pair<ll, ll>>;

void Solution() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<node> v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i].first;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].second.first, --v[i].second.first;
        v[i].second.second = i;
    }
    sort(all(v), [](const node &A, const node &B) { return A.second.first < B.second.first; });
    ll prev = -INF;
    vector<pair<ll, ll>> b(n, {-1, -1});
    for (ll i = 0; i < n; ++i) {
        b[i].second = v[i].second.second;
        ll &B = b[i].first, &A = v[i].first;
        // BS on C, find min C in range, [l - a[i], r - a[i]] such that C > prev as c[i] = b[i] - a[i]
        ll C = -INF;
        ll L = l - A, R = r - A;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (M > prev) {
                R = M;
                C = M;
            } else {
                L = M;
            }
        }
        if (C == -INF) return void(cout << "-1\n");
        B = C + A;
        prev = C;
    }
    dbg(v, b);
    sort(all(b), [](const pair<ll, ll> &A, const pair<ll, ll> &B) { return A.second < B.second; });
    for (auto &[x, y] : b) cout << x << ' ';
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
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}