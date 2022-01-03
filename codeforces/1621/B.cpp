#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, l, r, c;
    cin >> n;
    map<ll, set<pair<ll, ll>>> mp;  // {L or R, {cost, index}}
    ll d = -1, cc = -1;
    for (ll i = 0; i < n; ++i) {
        // minimum L and maximum R
        cin >> l >> r >> c;
        // if L and R for ans have same index
        if (r - l + 1 > d) d = r - l + 1, cc = c;
        if (r - l + 1 == d) amin(cc, c);
        // if L and R have different index
        mp[l].insert({c, i});
        mp[r].insert({c, i});
        auto front = *(mp.begin()->second).begin();  // smallest L wale set ka 1st element
        auto back = *(mp.rbegin()->second).begin();  // largest R wale set ka 1st element
        ll ans = front.first;
        if (front.second != back.second) ans += back.first;  // if different index, add both cost
        if ((mp.rbegin()->first - mp.begin()->first + 1) <= d) amin(ans, cc);
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}