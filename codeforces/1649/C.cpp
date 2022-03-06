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

ll distancesum(vector<ll> &arr) {
    ll n = sz(arr);
    sort(all(arr));
    ll res = 0, sum = 0;
    for (ll i = 0; i < n; i++) {
        res += (arr[i] * i - sum);
        sum += arr[i];
    }
    return res;
}

ll totaldistancesum(vector<ll> &x, vector<ll> &y) {
    return distancesum(x) + distancesum(y);
}

// https://www.geeksforgeeks.org/sum-manhattan-distances-pairs-points/
void Solution() {
    map<ll, pair<vector<ll>, vector<ll>>> mp;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> col(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> col[i][j];
            mp[col[i][j]].first.push_back(i);
            mp[col[i][j]].second.push_back(j);
        }
    }
    ll ans = 0;
    dbg(mp);
    for (auto &[x, y] : mp) {
        ans += totaldistancesum(y.first, y.second);
    }
    cout << ans << '\n';
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